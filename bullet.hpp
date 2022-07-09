//
//  Lab10stuff
//
//  Created by Conner Haar and Austin Eldredge on 6/25/22.
//



#ifndef bullet_hpp
#define bullet_hpp
#include "position.h"
#include "velocity.hpp"
#include "Acceleration.hpp"
#include "LinearInterpolation.hpp"
#include "Angle.h"
#include <iostream>
#include <vector>
using namespace std;


class TestBullet;

class Bullet {
public:
    Bullet(){};
    Bullet(Position startPoint) {
        position.setMetersX(startPoint.getMetersX());
        position.setMetersY(startPoint.getMetersY());
    }
    
    Position position;
    Velocity velocity;
    Acceleration acceleration;
    LinearInterpolation linearInterpolaiton;
    Angles angle; // using until angle class is complete, 30 degrees = 0.5235 radians
    bool alive = true;
    
    /* tick is to be called once each frame or time period on the bullet class.
       It calculates the location of where the bullet should be and adds the time interval */
    void tick(){
       
        doAllLinearInterpolationInThisOneFunctionPrettyCoolRight();
        acceleration.airDensity = airDensity;
        acceleration.speed = velocity.getSpeed();
        acceleration.calculateForceOnShell(dragCoefficient); 
        acceleration.calculateAcceleration();   // meanwhile until acceleration class is figured out

        acceleration.setDDX( -sin(angle.angle) * acceleration.acceleration);
        acceleration.setDDY( -gravity - (cos(angle.angle) * acceleration.acceleration));

        position.addMetersX((velocity.getDX() * time) + (0.5 * acceleration.getDDX() * pow(time, 2)));
        //position.setMetersY(position.getMetersY() + (velocity.getDY() * time) + (0.5 * acceleration.ddy * pow(time, 2)));
        position.addMetersY((velocity.getDY() * time) + (0.5 * acceleration.getDDY() * pow(time, 2)));
        
        velocity.addDx(acceleration.ddx, time);
        velocity.addDy(acceleration.ddy, time);
        
        double totalSpeed = sqrt(pow(velocity.getDX(), 2) + pow(velocity.getDY(), 2));
        velocity.setSpeed(totalSpeed);
        
        // not needed for now vvvv
//                If collisions.isCrashed()
//                    bullet.isAlive -> false
        
        
        this->currentTime += this->time;

    }
    
    // Getters
    bool isAlive(){ return alive; }
    double getArea(){ return area; }
    double getMass(){ return mass; }
    double getTime(){ return time; }
    double getCurrentTime(){ return currentTime; }
    double getDragCoefficient(){ return dragCoefficient; }
    double getAirDensity(){ return airDensity; }
    double getSpeedSound(){ return speedSound; }
    double getGravity(){ return gravity; }
    double getMach(){ return mach; }
    
    // Setters
    void doAllLinearInterpolationInThisOneFunctionPrettyCoolRight(){
        calculateMach();
        setDragCoefficient();
        setAirDensity();
        setSpeedSound();
        setGravity();
    }
    void setDragCoefficient(){
        vector <double> Tmach = { 0.3, 0.5, 0.7, 0.89, 0.920, 0.960, 0.980, 1.000, 1.02, 1.06, 1.240, 1.530, 1.990, 2.870, 2.890, 5.00 };
        vector <double> Tdragcoefficient = { 0.1629, 0.1659, 0.2031, 0.2597, 0.3010, 0.3287, 0.4002, 0.4258, 0.4335, 0.4483, 0.4064, 0.3663, 0.2897, 0.2297, 0.2306, 0.2656 };
        dragCoefficient = linearInterpolaiton.allPurposeLinearInterpolation(mach,5.00, Tmach, Tdragcoefficient);
    }
    
    void setAirDensity(){
        vector <double> Taltitude = { 0,1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000, 30000, 40000, 50000, 60000, 70000, 80000 };
        vector <double> Tairdensity = { 1.2250000, 1.1120000, 1.007000, 0.9093000, 0.8194000, 0.7364000, 0.6601000, 0.5900000, 0.5258000, 0.4671000, 0.4135000, 0.1948000,0.0889100, 0.0400800, 0.0184100, 0.0039960, 0.0010270, 0.0003097,  0.0000828, 0.0000185 };
        airDensity = linearInterpolaiton.allPurposeLinearInterpolation(position.getMetersY(),80000, Taltitude, Tairdensity);
    }

    void setSpeedSound(){
        vector <double> Taltitude = { 0,1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000, 30000, 40000, 50000, 60000, 70000, 80000 };
        vector <double> Tspeedsound = { 340, 336, 332, 328, 324, 320, 316, 312, 308, 303, 299, 295, 295, 295, 305, 324 };
        speedSound = linearInterpolaiton.allPurposeLinearInterpolation(position.getMetersY(),40000, Taltitude, Tspeedsound);
    }

    void setGravity(){
        vector <double> Taltitude = { 0,1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000, 30000, 40000, 50000, 60000, 70000, 80000 };
        vector <double> Tgravity = { 9.807, 9.804, 9.801, 9.797, 9.794, 9.791, 9.788, 9.785, 9.782, 9.779, 9.776, 9.761, 9.745, 9.730 };
        gravity = linearInterpolaiton.allPurposeLinearInterpolation(position.getMetersY(),25000,  Taltitude, Tgravity);
    }
    
    void calculateMach(){
        mach = velocity.getSpeed() / speedSound;
    }
    void setMach(double input){mach = input;} // Only used for setting up testcases
    void calculateForceOnShell(){
        forceOnShell = 0.5 * dragCoefficient * airDensity * pow(velocity.getSpeed(), 2) * area;
    }

private:
    // Tables used for Linear Interpolation
    vector <double> Taltitude = { 0,1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000, 30000, 40000, 50000, 60000, 70000, 80000 };
    vector <double> Tairdensity = { 1.2250000, 1.1120000, 1.007000, 0.9093000, 0.8194000, 0.7364000, 0.6601000, 0.5900000, 0.5258000, 0.4671000, 0.4135000, 0.1948000,0.0889100, 0.0400800, 0.0184100, 0.0039960, 0.0010270, 0.0003097,  0.0000828, 0.0000185 };
    vector <double> Tspeedsound = { 340, 336, 332, 328, 324, 320, 316, 312, 308, 303, 299, 295, 295, 295, 305, 324 };
    vector <double> Tgravity = { 9.807, 9.804, 9.801, 9.797, 9.794, 9.791, 9.788, 9.785, 9.782, 9.779, 9.776, 9.761, 9.745, 9.730 };
    vector <double> Tmach = { 0.3, 0.5, 0.7, 0.89, 0.920, 0.960, 0.980, 1.000, 1.02, 1.06, 1.240, 1.530, 1.990, 2.870, 2.890, 5.00 };
    vector <double> Tdragcoefficient = { 0.1629, 0.1659, 0.2031, 0.2597, 0.3010, 0.3287, 0.4002, 0.4258, 0.4335, 0.4483, 0.4064, 0.3663, 0.2897, 0.2297, 0.2306, 0.2656 };
    
    
    double const area = 0.018842;
    double const mass = 46.7;
    double time = 1;
    double currentTime = 0.0;
    
    // Things where Linear Interpolation is needed
    double dragCoefficient;
    double airDensity;
    double speedSound = 340;
    double mach;
    double gravity;
    
    double forceOnShell;
    

};
#include <stdio.h>

#endif /* bullet_hpp */
