//
//  Button.cpp
//
//  Created by Juewei Dong on 11/24/16.
//  Copyright © 2016 CMU. All rights reserved.
//

#include "Button.h"

void Button::LoadFile(char fn[])
{
    LoadPics(fn);
}

void Button::LoadPics(char fn[])
{
    buttonPic.Decode(fn);
    buttonPic.Flip();
}

void Button::AlphaEnable()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}



void Button::DisplayButtons()
{
    //    int wid, hei;
    //    FsGetWindowSize(wid, hei);
    
    int bias = 0;
    
    if (MouseOver())
    {
        bias = 5;
    }
    else
    {
        bias = 0;
    }
    
    
    glRasterPos2d(PosX + bias, PosY + bias);
    glDrawPixels(buttonPic.wid, buttonPic.hei, GL_RGBA, GL_UNSIGNED_BYTE, buttonPic.rgba);
    
}

void Button::ClickButton()
{
    clicked=true;
}


bool Button::isClicked()
{
    int evt, lb, mb, rb, mx, my;
    evt=FsGetMouseEvent(lb, mb, rb, mx, my);
    
    if ((mx >= PosX) && (mx <= PosX+buttonPic.wid)
        && (my <= PosY) && (my >= PosY-buttonPic.hei))
    {
        if (FsGetMouseEvent(lb, mb, rb, mx, my) == FSMOUSEEVENT_LBUTTONDOWN)
        {
            printf("LButton Pressed!\n");
        }
        if (FsGetMouseEvent(lb, mb, rb, mx, my) == FSMOUSEEVENT_MBUTTONDOWN)
        {
            printf("M Pressed!\n");
        }
        if (FsGetMouseEvent(lb, mb, rb, mx, my) == FSMOUSEEVENT_RBUTTONDOWN)
        {
            printf("R Pressed!\n");
        }
        
        // printf("Evt: %d\n",evt);
        
        if (lb)
        {
            ClickButton();
        }
    }
    
    bool status=clicked;
    clicked=false;
    return status;
}

bool Button::MouseOver()
{
    int evt, lb, mb, rb, mx, my;
    evt=FsGetMouseEvent(lb, mb, rb, mx, my);
    
    if ((mx >= PosX) && (mx <= PosX+buttonPic.wid)
        && (my <= PosY) && (my >= PosY-buttonPic.hei))
    {
        return true;
    }
    
    return false;
}

int Button::ButtonHei()
{
    return buttonPic.hei;
}

int Button::ButtonWid()
{
    return buttonPic.wid;
}

unsigned char* Button::GetRGBA()
{
    return buttonPic.rgba;
}

