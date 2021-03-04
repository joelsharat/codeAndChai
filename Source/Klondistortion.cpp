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


Klondistortion::Klondistortion(){     //consructor 
    
    drive = 5.0f;
    tone = 6.0f;
    level = 3.0f;
    cout << "Parameters set" << endl;
}

float Klondistortion::processSample(float x){
    
}
   
void Klondistortion::prepare(){

}

/*float Klondistortion::getDrive(){   //get drive of plugin
return drive;
}

void Klondistortion::setDrive(float newDrive){    //set drive of plugin
    drive = newDrive;
    
}

float Klondistortion::getTone(){           //get tone of plugin
    return tone;
}


void Klondistortion::setTone(float newTone){    //set tone of plugin
    tone = newTone;
    
}


float Klondistortion::getLevel(){        //get level of plugin
    return level;
}


void Klondistortion::setLevel(float newLevel){   //set level of plugin 
    level = newLevel;
}
 */
