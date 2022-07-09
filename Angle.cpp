//
//  main.cpp
//  PS03_Angles
//
//  Created by Conner Haar and Austin Eldredge on 5/3/22.
//

#include <iostream>
#include <corecrt_math_defines.h> //some computers dont have Pi defined, this defines it.
#include <math.h>
#include <iomanip>
using namespace std;

/* A class created to hold an angle and convert it form degrees to radians as needed*/
class Angles {
public:
    //instantiate the single attribute of angle
    double angle;
    //return the angle in degrees

    Angles(double angle1) {
        angle = angle1;
    }

    Angles() {
        angle = 0.0;
    }

    double getDegrees() {
        return convertToDegrees();
    };

    //return the angle in radians
    double getRadians() {
        return angle;
    };

    //set the angle value using degrees
    void setDegrees(double degs) {
        angle = convertToRadians(degs);
    };

    //set the angle value using radians
    void setRadians(double rads) {
        angle = rads;
    };

    //display the angle to the user in degrees
    void display() {
        normalize();
        double degrees = convertToDegrees();
        cout << fixed << setprecision(1);
        cout << "Degrees: " << degrees << endl;
    };

    //assignment operator
    Angles& operator=(const Angles& rhs)
    {
        angle = rhs.angle;
        return *this;
    }

    //negative operator 
    Angles operator-() {
        return -angle;
    }



    //angles comaparison operator for ==
    bool operator==(const Angles& rhs) const {
        return angle == rhs.angle;
    }

    bool operator!=(const Angles& rhs) const {
        return angle != rhs.angle;
    }

    //insertion operator
    friend ostream& operator<<(ostream& out, const Angles& rhs)
    {
        out << rhs.angle;
        return out;
    }

    //extraction operator
    friend istream& operator>>(istream& in, Angles& rhs)
    {
        in >> rhs.angle;
        return in;
    }

    // //plus equals operator
    // Angles& operator+= (const Angles & rhs)
    //     {
    //         angle += rhs.angle;
    //         return *this;
    //     }

    // //minus equals operator
    // Angles& operator+= (const Angles & rhs)
    //     {
    //         angle -= rhs.angle;
    //         return *this;
    //     }

    //increment prefix
    Angles& operator++()
    {
        this->angle += 1.0;
        // return new value
        return *this;
    }

    //increment postfix
    friend Angles operator++(Angles& num, int postfix)
    {
        Angles angleReturn(num);
        num.angle += 1.0;
        // return old value
        return angleReturn;
    }



    //decrement prefix
    Angles& operator--()
    {
        this->angle -= 1.0;
        // return new value
        return *this;
    }

    //decrement postfix
    friend Angles operator--(Angles& num, int postfix)
    {
        Angles angleReturn(num);
        num.angle -= 1.0;
        // return old value
        return angleReturn;
    }




private:

    //convert a value  of radians to degrees
    double convertToDegrees() {
        double degrees = angle * 180 / M_PI;
        return degrees;
    };

    //convert a value of degrees to radians
    double convertToRadians(double degs) {
        double radians = degs * M_PI / 180;
        return radians;
    };

    //normalize the value to be a normal angle
    void normalize() {
        double degrees = convertToDegrees();
        while (360 < degrees || degrees < 0) {
            if (degrees > 360) {
                degrees -= 360;
            }
            else {
                degrees += 360;
            }
        }
        //convert the new angle into radians to be stored, so we dont have to normalize every time its used
        angle = convertToRadians(degrees);
    };
};