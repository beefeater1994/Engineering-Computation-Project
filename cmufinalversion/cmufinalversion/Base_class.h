//
//  Base_class.h
//  Created by Liu Yuzhang on 16/11/20.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fssimplewindow.h"
#include "yspng.h"



#ifndef Base_class_h
#define Base_class_h



class Base
{
public:
    
    double width, height, depth;
    int NormalR1,NormalG1,NormalB1,CornerR,CornerG,CornerB;
    int NormalR2,NormalG2,NormalB2;
    int NormalR3,NormalG3,NormalB3;
    int NormalR4,NormalG4,NormalB4;
    
    int NoOfBlock;
    Base();
    void DrawCube2(double x1,double y1,double z1,double x2,double y2,double z2,int r,int g,int b, GLuint texId);
    //void DrawBase(void);
    void DrawCube1(double x1,double y1,double z1,double x2,double y2,double z2,int r,int g,int b, GLuint texId);
    void DrawBase(GLuint texId[]);
    void SetTexture(YsRawPngDecoder &png, GLuint &texId,char fn1[]);
    void DrawBackground(GLuint texId);
    
};


#endif /* Base_class_h */
