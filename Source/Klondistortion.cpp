//
//  Klondistortion.cpp
//  KlonPedalTest
//
//  Created by Joel Sharat on 27/02/21.
//

#include <stdio.h>
#include <iostream>
using namespace std; 
#include "Klondistortion.h"


void Klondistortion::setSampleRate(float newFs) {
    Fs = newFs;
    }

void Klondistortion::setDriveValue(float newDrive){
    drive = newDrive;
}

void Klondistortion::setToneValue(float newTone){
    tone = newTone;
    
}

void Klondistortion::setLevelValue(float newLevel){
    level = newLevel;

}


float Klondistortion::processSample(float x, int channel) {
    
    V2 = x * (1 + R4/R3) - (R4/R3 * V1);
    V3 = -R5/R4 * x + (V2 * (1 + R5/R4));
    V4 =  -R6/R1 * V1 + (-R6/R5 * V2) + (V3 * (1 + R6/R1 + R6/R5)) - R6*X1;
    V5 = -R7/R6 * V3 + V4 * (1 + R7/R6);
    V6 = -R2/R8 * V1 + (-R2/R7 * V4) + (V5 * (1 + R2/R7+ R2/R8)) - (R2 * X2) ;
    V7 = -R7/R2 * V5 + V6 *(1 + R7/R2) + R7 * X2;
    x = V7 / (1+R10/R11);
    
    //state update variables
    X1 = (2/R1) * (V3 - V1) - X1;
    X2 = (2/R2) * (V5 - V6) - X2;
    
    updateCoefficients();
   

    return x;
}


void Klondistortion::updateCoefficients(){
    
    Ts = 1/Fs;

    //components that require update
    pT = tone/10;
    R5 = pT * 10e3;
    R6 = (1.f - pT) * 10e3;
    R7 = 4.7e3;
    R8 = 100e3;
    R9 = 560;
    pO = level;
    R10 = pO * 10e3;
    R11 = (1-pO) * 10e3;

  

}


