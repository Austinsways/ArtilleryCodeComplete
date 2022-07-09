//
//  Lab10stuff
//
//  Created by Conner Haar and Austin Eldredge on 6/25/22.
//

#ifndef velocity_hpp
#define velocity_hpp

#include <stdio.h>
#include <cmath>

class Velocity{
private:
    double dx;
    double dy;
    double speed;
public:
    // Constructors
    Velocity() {
        initializeVelocities(0.0);
    };
    //Velocity(double dx, double dy);
    
    // Getters
    double getDY(){ return dy; };
    double getDX(){ return dx; };
    double getSpeed(){
        return speed;
    }
    void setSpeed(double val){
        speed = val;
    }
    // Setters
    void setDX(double val){
        dx = val;
    }
    void setDY(double val){
        dy = val;
    }
    
    // adds velocity to the current velocity
    void addDx(double ddx, double time){
        dx += (ddx * time);
    }
    
    // adds velocity to the current velocity
    void addDy(double ddy, double time){
        dy += (ddy * time);
    }
    
    void initializeVelocities(double angle){
        speed = 827;
        setDX(sin(angle) * speed);
        setDY(cos(angle) * speed);

    }
    
};
#endif /* velocity_hpp */
