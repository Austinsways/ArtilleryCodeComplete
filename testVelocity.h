//
//  testVelocity.h
//  Lab07
//
//  Created by Conner Haar on 6/17/22.
//

#ifndef testVelocity_h
#define testVelocity_h

using namespace std;

class testVelocity{
public:
    void run(){
        defaultConstructor;
        nonDefaultConstructor;
        copyConstructor;
        
        getDx();
        getDxWithNoDx();
        getDy();
        getDxwithNoDX();
        
        getSpeed();
        getSpeedNegatives();
        getSpeedZeros();
        
        setDx;
        setDxNegative:
        setDxFloat;
        setDxDouble;
        
        setDy;
        setDyNegative;
        setDyFloat;
        setDyDouble;
        
        addVelocity();
    }
private:
    
}

#endif /* testVelocity_h */
