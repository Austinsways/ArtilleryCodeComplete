//
//  Lab10stuff
//
//  Created by Conner Haar and Austin Eldredge on 6/25/22.
//

#pragma once
//this is the test counterpart for the acceleration class.
#include "Acceleration.hpp"
#include "bullet.hpp"
#include <cassert>

class TestAcceleration {
public:
    double ddx;
    double ddy;
    double forceOnShell;

    //run all the test cases.
    void run() {

        //test constructor
        testDefaultAcceleration();

        //test getters and setter
        testGetDDX();
        testGetDDY();
        testSetDDX();
        testSetDDY();

        //run acceleration claculation tests
        testCalculateAccelerationNegative();
        testCalculateAccelerationExtremelyHigh();
        testCalculateAccelerationPositive();
        testCalculateAccelerationSmallValue();
        testCalculateAccelerationZeros();

        //run Force on shell Calculation tests
        testCalculateForceOnShellPositive();
        testCalculateForceOnShellNegative();
        testCalculateForceOnShellZero();
        testCalculateForceOnShellExtremelyHigh();
        testCalculateForceOnShellSmallValue();
    };
    //testing constructor
    void testDefaultAcceleration() {
        //setup
        Acceleration* acceleration = new Acceleration;
        //the constructor excerszes itself when constructed.

        //verify
        assert(acceleration->ddx == 0);
        assert(acceleration->ddy == 0);
        assert(acceleration->forceOnShell == 0);
        //teardown
        delete acceleration;
    };

    //testing getters
    void testGetDDX() {
        //setup
        Acceleration* acceleration = new Acceleration;
        acceleration->ddx = 0;
        //excersize and verify
        assert(acceleration->getDDX() == 0);
        //teardown
        delete acceleration;
    };
    void testGetDDY() {
        //setup
        Acceleration* acceleration = new Acceleration;
        acceleration->ddy = 0;
        //excersize and verify
        assert(acceleration->getDDY() == 0);
        //teardown
        delete acceleration;
    }
    //testing Setters
    void testSetDDX() {
        //setup
        Acceleration* acceleration = new Acceleration;
        //excersize
        acceleration->setDDX(400);
        //verify
        assert(acceleration->ddx == 400);
        //teardown
        delete acceleration;
    }
    void testSetDDY() {
        //setup
        Acceleration* acceleration = new Acceleration;
        //excersize
        acceleration->setDDX(400);
        //verify
        assert(acceleration->ddx == 400);
        //teardown
        delete acceleration;
    }

    //testing thoroughly the Acceleration class
    void testCalculateAccelerationNegative() {
        //setup
        Acceleration* acceleration = new Acceleration;
        acceleration->forceOnShell = -10;
        //excersize
        acceleration->calculateAcceleration();
        //verify
        assert(acceleration->acceleration == -0.21413276231263381);

        //teardown
        delete acceleration;
    };
    void testCalculateAccelerationPositive() {
        //setup
        Acceleration* acceleration = new Acceleration;
        acceleration->forceOnShell = 10;
        //excersize
        acceleration->calculateAcceleration();
        //verify
        assert(acceleration->acceleration == 0.21413276231263381);
        //teardown
        delete acceleration;
    };
    void testCalculateAccelerationZeros() {
        //setup
        Acceleration* acceleration = new Acceleration;
        acceleration->forceOnShell = 0;
        //execute
        acceleration->calculateAcceleration();
        //verify
        assert(acceleration->acceleration == 0.0);
        //teardown
        delete acceleration;
    };
    void testCalculateAccelerationExtremelyHigh() {
        //setup
        Acceleration* acceleration = new Acceleration;
        acceleration->forceOnShell = 1000000;
        //excersize
        acceleration->calculateAcceleration();
        //verify
        assert(acceleration->acceleration == 21413.276231263382);
        //teardown
        delete acceleration;
    };
    void testCalculateAccelerationSmallValue() {
        //setup
        Acceleration* acceleration = new Acceleration;
        acceleration->forceOnShell = .01;
        //excersize
        acceleration->calculateAcceleration();
        //verify
        assert(acceleration->acceleration == 0.00021413276231263382);
        //teardown
        delete acceleration;
    };

    //testing thoroughly the Force on Shell class
    void testCalculateForceOnShellPositive() {
        //setup
        double cDrag = 10;
        Acceleration* acceleration = new Acceleration;
        acceleration->airDensity = 1.2250000;
        acceleration->ddy = 100;
        acceleration->ddx = 100;
        //excersize
        acceleration->calculateForceOnShell(cDrag);
        //verify
        assert(acceleration->forceOnShell == 78930.365085250000);
        //teardown
        delete acceleration;


    };
    void testCalculateForceOnShellNegative() {
        //setup
        double cDrag = -10;
        Acceleration* acceleration = new Acceleration;
        acceleration->airDensity = 1.2250000;
        acceleration->ddy = 100;
        acceleration->ddx = 100;
        //excersize
        acceleration->calculateForceOnShell(cDrag);
        //verify
        assert(acceleration->forceOnShell == -78930.365085250000);
        //teardown
        delete acceleration;

    };
    void testCalculateForceOnShellZero() {
        //setup
        double cDrag = 0;
        Acceleration* acceleration = new Acceleration;
        acceleration->airDensity = 1.2250000;
        acceleration->ddy = 100;
        acceleration->ddx = 100;
        //excersize
        acceleration->calculateForceOnShell(cDrag);
        //verify
        assert(acceleration->forceOnShell == 0.0);
        //teardown
        delete acceleration;
    };
    void testCalculateForceOnShellExtremelyHigh() {
        //setup
        double cDrag = 100;
        Acceleration* acceleration = new Acceleration;
        acceleration->airDensity = 1.2250000;
        acceleration->ddy = 100;
        acceleration->ddx = 100;
        //excersize
        acceleration->calculateForceOnShell(cDrag);
        //verify
        assert(acceleration->forceOnShell == 789303.65085250023);
        //teardown
        delete acceleration;
    };
    void testCalculateForceOnShellSmallValue() {
        //setup
        double cDrag = .001;
        Acceleration* acceleration = new Acceleration;
        acceleration->airDensity = 1.2250000;
        acceleration->ddy = 100;
        acceleration->ddx = 100;
        //excersize
        acceleration->calculateForceOnShell(cDrag);
        //verify
        assert(acceleration->forceOnShell == 7.8930365085250020);
        //teardown
        delete acceleration;
    };
};
