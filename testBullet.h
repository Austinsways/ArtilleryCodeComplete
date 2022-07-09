//
//  Lab10stuff
//
//  Created by Conner Haar and Austin Eldredge on 6/25/22.
//

#ifndef testBullet_h
#define testBullet_h
#include "bullet.hpp"
#include "velocity.hpp"
#include <cassert>
using namespace std;

class TestBullet{
public:
    void run(){
        defaultConstructor();
        
        tick();
        
        isAlive();
        isDead();
        
        getCurrentTime();
        getCurrentTimeInitial();
        
        getTime();
        getArea();
        getMass();
        getDragCoefficient();
        getSpeedSound();
        getAirDensity();
        getGravity();
        
        setDragCoefficient();
        setDragCoefficientMin();
        setDragCoefficientMax();
        setDragCoefficientOverMax();
        
        setSpeedSound();
        setSpeedSoundMin();
        setSpeedSoundMax();
        setSpeedSoundOverMax();
        
        setAirDensity();
        setAirDensityMin();
        setAirDensityMax();
        setAirDensityOverMax();
        
        setGravity();
        setGravityMin();
        setGravityMax();
        setGravityOverMax();
        
        calculateMachNormal();
        
    }
private:
    void defaultConstructor() const
    {  // setup
       // exercise
        Bullet bullet;
       // verify
        assert(bullet.getArea() == 0.018842);
        assert(bullet.getMass() == 46.7);
        assert(bullet.getTime() == 0.1);
    }  // teardown
    
    void tick() const
    {  // setup
        Bullet bullet;
       // exercise
        bullet.tick();
       // verify
        assert(bullet.position.getMetersY() ==71.430896060865948);
        assert(bullet.position.getMetersX() ==44.127047060689300);
        assert(bullet.getCurrentTime() == 0.1);
    }  // teardown
    
    void isAlive() const
    {  // setup
        Bullet bullet;
       // exercise
        bullet.alive = true;
       // verify
        assert(bullet.isAlive() == true);
    }  // teardown
    
    void isDead() const
    {  // setup
        Bullet bullet;
       // exercise
        bullet.alive = false;
       // verify
        assert(bullet.isAlive() == false);
    }  // teardown
    
    void getCurrentTime() const
    {  // setup
        Bullet bullet;
       // exercise
        bullet.tick();
        bullet.tick();
        bullet.tick();
       // verify
        assert(bullet.getCurrentTime() == 0.30000000000000004);
    }  // teardown
    
    void getCurrentTimeInitial() const
    {  // setup
        Bullet bullet;
       // exercise
        double curr = bullet.getCurrentTime();
       // verify
        assert(curr == 0.0);
    }  // teardown
    
    void getTime() const
    {  // setup
        Bullet bullet;
       // exercise
        double area = bullet.getTime();
       // verify
        assert(area == 0.1);
    }  // teardown
    
    void getArea() const
    {  // setup
        Bullet bullet;
       // exercise
        double area = bullet.getArea();
       // verify
        assert(area == 0.018842);
    }  // teardown
    
    void getMass() const
    {  // setup
        Bullet bullet;
       // exercise
        double mass = bullet.getMass();
       // verify
        assert(mass == 46.7);
    }  // teardown
    
    void getDragCoefficient() const
    {  // setup
        Bullet bullet;
        bullet.setMach(0);
        bullet.setDragCoefficient();
       // exercise
        double cdrag = bullet.getDragCoefficient();
       // verify
       assert(cdrag == 0.1629);
    }  // teardown
    
    void getSpeedSound() const
    {  // setup
        Bullet bullet;

        bullet.setSpeedSound();
       // exercise
        double ss = bullet.getSpeedSound();
       // verify
        assert(ss == 340);
    }  // teardown
    
    void getAirDensity() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(0);
        bullet.setAirDensity();
       // exercise
        double ad = bullet.getAirDensity();
       // verify
        assert(ad == 1.225);
    }  // teardown
    
    void getGravity() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(0);
        bullet.setGravity();
       // exercise
        double g = bullet.getGravity();
       // verify
        assert(g == 9.807);
    }  // teardown
    
    void setDragCoefficient() const
    {  // setup
        Bullet bullet;
        bullet.setMach(0.5);
       // exercise
        bullet.setDragCoefficient();
       // verify
        assert(bullet.getDragCoefficient() == 0.1659);
    }  // teardown
    
    void setDragCoefficientMin() const
    {  // setup
        Bullet bullet;
        bullet.setMach(0.3);
       // exercise
        bullet.setDragCoefficient();
       // verify
        assert(bullet.getDragCoefficient() == 0.1629);
    }  // teardown
    
    void setDragCoefficientMax() const
    {  // setup
        Bullet bullet;
        bullet.setMach(5.00);
       // exercise
        bullet.setDragCoefficient();
       // verify
        assert(bullet.getDragCoefficient() == 0.2656);
    }  // teardown
    
    void setDragCoefficientOverMax() const
    {  // setup
        Bullet bullet;
        bullet.setMach(6.0);
       // exercise
        bullet.setDragCoefficient();
       // verify
        assert(bullet.getDragCoefficient() == 0.2656);
    }  // teardown
    
    void setSpeedSound() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(2000);
       // exercise
        bullet.setSpeedSound();
       // verify
        assert(bullet.getSpeedSound() == 332);
    }  // teardown
    
    void setSpeedSoundMin() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(0);
       // exercise
        bullet.setSpeedSound();
       // verify
        assert(bullet.getSpeedSound() == 340);
    }  // teardown
    
    void setSpeedSoundMax() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(40000);
       // exercise
        bullet.setSpeedSound();
       // verify
        assert(bullet.getSpeedSound() == 324);
    }  // teardown
    
    void setSpeedSoundOverMax() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(50000);
       // exercise
        bullet.setSpeedSound();
       // verify
        assert(bullet.getSpeedSound() == 324);
    }  // teardown
    
    void setAirDensity() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(2000);
       // exercise
        bullet.setAirDensity();
       // verify
        assert(bullet.getAirDensity() == 1.007);
    }  // teardown
    
    
    void setAirDensityMin() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(0);
       // exercise
        bullet.setAirDensity();
       // verify
        assert(bullet.getAirDensity() == 1.225);
    }  // teardown
    
    void setAirDensityMax() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(80000);
       // exercise
        bullet.setAirDensity();
       // verify
        assert(bullet.getAirDensity() == 0.0000185);
    }  // teardown
    
    void setAirDensityOverMax() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(100000);
       // exercise
        bullet.setAirDensity();
       // verify
        assert(bullet.getAirDensity() == 0.0000185);
    }  // teardown
    
    void setGravity() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(2000);
       // exercise
        bullet.setGravity();
       // verify
        assert(bullet.getGravity() == 9.801);
    }  // teardown
    
    void setGravityMin() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(0);
       // exercise
        bullet.setGravity();
       // verify
        assert(bullet.getGravity() == 9.807);
    }  // teardown
    
    void setGravityMax() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(25000);
       // exercise
        bullet.setGravity();
       // verify
        assert(bullet.getGravity() == 9.730);
    }  // teardown
    
    void setGravityOverMax() const
    {  // setup
        Bullet bullet;
        bullet.position.setMetersY(30000);
       // exercise
        bullet.setGravity();
       // verify
        assert(bullet.getGravity() == 9.730);
    }  // teardown
    
    void calculateMachNormal() const
    {   //setup
        Bullet bullet;
        // excercise
        bullet.calculateMach();
        // verify
        assert(bullet.getMach() == 2.4705882352941178);
    }   // teardown
};

#endif /* testBullet_h */
