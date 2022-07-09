//
//  Lab10stuff
//
//  Created by Conner Haar and Austin Eldredge on 6/25/22.
//


#ifndef LinearInterpolation_hpp
#define LinearInterpolation_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class LinearInterpolation{
public:
    double Equation(double v, double v0, double v1, double c0, double c1) {
        double c;
        c = c0 + (((v - v0) * (c1 - c0)) / (v1 - v0));
        return c;
    }
    double allPurposeLinearInterpolation(double val, double maxValue, vector <double> vec1, vector <double> vec2){
        double a0;
        double a1;
        double d0;
        double d1;
        int index = 0;
        double temp = -1;// output will be 1 if there is an error
        while ((val > vec1[index]) & (maxValue != vec1[index]) ){
            index += 1;
        }
        // For minimum values
        if ((val == 0) or (val == 0.3)) {
            temp = vec2[0];
        }
        // For overmax values
        else if (val > maxValue){
            temp = vec2.back();
        }
        // For exact values
        else if (val == vec1[index]){
            temp = vec2[index];
        }
        // For values in between
        else if (val < vec1[index]) {
            if (index == 0) {
                a0 = vec1[0];
            }
            else {
                a0 = vec1[index - 1];
            }
            a1 = vec1[index];
            if (index == 0) {
                d0 = vec2[0];
            }
            else {
                d0 = vec2[index - 1];
            }
            d1 = vec2[index];
            temp = Equation(val, a0, a1, d0, d1);
        }
        return temp;
    }
};

#endif /* LinearInterpolation_hpp */
