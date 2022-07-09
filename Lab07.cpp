/*************************************************************
 * 1. Name:
 *      The Key
 * 2. Assignment Name:
 *      Lab 08: M777 Howitzer
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
#include "velocity.hpp" // for VELOCITY
#include "Acceleration.hpp" // for ACCELERATION
#include "bullet.hpp"      // for BULLET
#include "test.h"       // for TESTS
      //Angle class
#include <vector>       //for usng vectors
using namespace std;

/*************************************************************************
 * Game
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Game
{
public:
   Game(Position ptUpperRight) :
      ptUpperRight(ptUpperRight),
      ground(ptUpperRight),
      time(0.0)
   {
      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
      ground.reset(ptHowitzer);
      for (int i = 0; i < bullets.size(); i++)

      {
          for (int trail = 0; trail < 1; trail++)
          {


              //         projectilePath[i].setPixelsX((double)i * 2.0);
              //         projectilePath[i].setPixelsY(ptUpperRight.getPixelsY() / 1.5);

                       // New code for bullet
              bullets[i].position.setPixelsX((i * 2.0) + ptHowitzer.getPixelsX());
              bullets[i].position.setPixelsY(ptHowitzer.getPixelsY()); // until we get the constructor working
              bullets[i].velocity.initializeVelocities(bullets[i].angle.angle);
          }
      }

   }

   Ground ground;                 // the ground
   Position  projectilePath[20];  // path of the projectile
   Position  ptHowitzer;          // location of the howitzer
   Position  ptUpperRight;        // size of the screen
   vector<Bullet> bullets; // creats a vector of bullet objects
   Angles angle;                  // angle of the howitzer 
   double time;                   // amount of time since the last firing
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Game* pGame = (Game*)p;

   //
   // accept input
   //

   // move a large amount
   if (pUI->isRight())
      pGame->angle.angle += 0.05;
   if (pUI->isLeft())
      pGame->angle.angle -= 0.05;

   // move by a little
   if (pUI->isUp())
      pGame->angle.angle += (pGame->angle.angle >= 0 ? -0.003 : 0.003);
   if (pUI->isDown())
      pGame->angle.angle += (pGame->angle.angle >= 0 ? 0.003 : -0.003);

   // fire that gun
   if (pUI->isSpace()) {
       pGame->time = 0.0;
       Bullet bullet;
       //for (int i = 0; i < 20; i++)
       //{
       bullet.angle = pGame->angle.angle;
       bullet.position = pGame->ptHowitzer;
       //}
       pGame->bullets.push_back(bullet);
   }

   //
   // perform all the game logic
   //
   
   // advance time by half a second.
   pGame->time += 0.5;
   
   // move the projectile across the screen
//   for (int i = 0; i < 20; i++)
//   {
//      double x = pGame->projectilePath[i].getPixelsX(); // gets X pixel of first point
//      double y = pGame->projectilePath[i].getPixelsY();
//      x -= 1.0;                                         // shifts X over by one pixel
//      y -= 1.0;
//      if (x < 0)
//         x = pGame->ptUpperRight.getPixelsX();
//      if (y < 0)
//         y = pGame->ptUpperRight.getPixelsY();
//      pGame->projectilePath[i].setPixelsX(x);         // Sets shifted X pixel to actual point
//      pGame->projectilePath[i].setPixelsY(y);
//   }
   
   // New code for moving
   for (int i = 0; i < pGame->bullets.size(); i++)
   {
       for (int trail = 0; trail < 1; trail++)
       {


           double x = pGame->bullets[i].position.getPixelsX(); // gets X pixel of first point
           double y = pGame->bullets[i].position.getPixelsY();
           pGame->bullets[i].tick();
           if (x < 0)
               x = pGame->ptUpperRight.getPixelsX();
           if (y < 0)
               y = pGame->ptUpperRight.getPixelsY();
       }
     // pGame->bullet[i].position.setPixelsX(x);         // Sets shifted X pixel to actual point
     // pGame->bullet[i].position.setPixelsY(y);
   }
      
   // My own implementation of moving the bullet
   
//   double y = pGame->bullet.position.getPixelsY();
//   y += 0.5;
//   if (y < 0)
//      y = pGame->ptUpperRight.getPixelsY();
//   pGame->bullet.position.setPixelsY(y);
//   pGame->bullet.position.setPixelsX(pGame->ptHowitzer.getPixelsX());

   //
   // draw everything
   //

   ogstream gout(Position(10.0, pGame->ptUpperRight.getPixelsY() - 20.0));

   // draw the ground first
   pGame->ground.draw(gout);

   // draw the howitzer
   gout.drawHowitzer(pGame->ptHowitzer, pGame->angle.angle, pGame->time);

   // draw the projectile
   for (int i = 0; i < pGame->bullets.size(); i++)
       for (int trail = 0; trail < 1; trail++) {

           gout.drawProjectile(pGame->bullets[i].position, 0.5 * (double)i);
       }
   
   //gout.drawProjectile(pGame->bullet.position); // my own implementation of projectile

   // draw some text on the screen
   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1);
   gout << "Time since the bullet was fired: "
      << pGame->time << "s\n";
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Test Runner
   // testRunner();
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setPixelsX(700.0);
   ptUpperRight.setPixelsY(500.0);
   Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
   Interface ui(0, NULL,
      "Game",   /* name on the window */
      ptUpperRight);

   // Initialize the Game
   Game Game(ptUpperRight);

   // set everything into action
   ui.run(callBack, &Game);


   return 0;
}
