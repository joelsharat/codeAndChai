//
//  Klondistortion.h
//  KlonPedalTest
//
//  Created by Joel Sharat on 27/02/21.
//

#ifndef Klondistortion_h
#define Klondistortion_h

class Klondistortion{ //class creation
    
private:
    float Fs = 48000.f;
    float drive = 1;  //1 - 10
    float tone = 1;   //1 - 10
    float level = 1;  //1 - 10
    
    float Ts;
    
    //voltages
    float V1 = 4.5;
    float V2;
    float V3;
    float V4;
    float V5;
    float V6;
    float V7; 
    

    //components
    float C1 = 3.9e-9;
    float R1 = Ts/(2.f * C1);
    float C2 = 4.7e-6;
    float R2 = Ts/(2.f * C2);
    float R3 = 100e3;
    float R4 = 1.8e3;
    float pT;
    float R5;
    float R6;
    float R7 = 4.7e3;
    float R8 = 100e3;
    float R9 = 560;
    float pO;
    float R10;
    float R11;

    //state update variables
    float X1 = 0;
    float X2 = 0;

    

public:
    Klondistortion();
    ~Klondistortion(); 
    
    void setSampleRate(float newFs);
    void setDriveValue(float newDrive);
    void setToneValue(float newTone);
    void setLevelValue(float newLevel);
    float processSample(const float x, const int channel);
    void updateCoefficients();
   
};
#endif /* Klondistortion_h */
