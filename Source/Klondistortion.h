//
//  Klondistortion.h
//  KlonPedalTest
//
//  Created by Joel Sharat on 27/02/21.
//

#ifndef Klondistortion_h
#define Klondistortion_h

class Klondistortion{   //class creation
    
private:
    float Fs = 48000.f;
    float Ts = 1.f /Fs;
    
    float drive;       //paramaters of the plugin
    float tone;
    float level;

public:
    Klondistortion();
    float processSample(float x);
    void prepare();//setting sampling rate
    
    
    void setDrive(float newDrive);      //methods   aka function of the
    float getDrive();


    void setTone(float newTone);
    float getTone();
    
    void setLevel(float newLevel);
    float getLevel();
  
   
    
};
#endif /* Klondistortion_h */
