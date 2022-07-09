#pragma once
//
//  Lab10stuff
//
//  Created by Conner Haar and Austin Eldredge on 6/25/22.
#include <math.h>


/* This file Includes all the code for the acceleration class*/
class Acceleration {
    
public:
    double ddx = 0;
    double ddy = 0;
    double airDensity = 0;
    double forceOnShell = 0;
    double acceleration = 0;
    const double mass = 46.7;
    double cdrag = 0;
    double speed = 827; //this is the intial launch speed
    const double area = 0.018842;

    Acceleration() {
        //TODO
    };

    double getDDX() {
        return ddx;
    };

    double getDDY() {
        return ddy;
    };

    void setDDX(int value) {
        ddx = value;
    };
    void setDDY(int value) {
        ddy = value;
    };

    void calculateAcceleration() {
        acceleration = forceOnShell / mass;
    };


    void calculateForceOnShell(double cDrag) {
        forceOnShell = 0.5 * cDrag * airDensity * pow(speed, 2) * area;
    };
};
