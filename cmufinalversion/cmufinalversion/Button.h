//
//  main.cpp
//
//  Created by Juewei Dong on 11/24/16.
//  Copyright © 2016 CMU. All rights reserved.
//

#ifndef Button_h
#define Button_h

#include <stdio.h>
#include <stdlib.h>
#include "fssimplewindow.h"
#include "yspng.h"

class Button
{
protected:
    YsRawPngDecoder buttonPic;
    
    // Load button pictures
    void LoadPics(char fn[]);
    bool clicked=false;
    
public:
    // Constructor
    void LoadFile(char fn[]);
    
    double PosX, PosY;
    void ClickButton();
    bool isClicked();
    bool MouseOver();
    void DisplayButtons();
    
    int ButtonHei();
    int ButtonWid();
    unsigned char *GetRGBA();
    
    void AlphaEnable();
    
};

#endif
