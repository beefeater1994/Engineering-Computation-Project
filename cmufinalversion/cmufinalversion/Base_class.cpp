//
//  Base_class.cpp
//  Project_3D_BoardAndPlayer_WithPopup
//
//  Created by Liu Yuzhang on 16/11/20.
//  Copyright © 2016年 Yuzhang Liu. All rights reserved.
//

#include "Base_class.h"

Base::Base()
{
    width = 20.0;
    height = 30.0;
    depth = 5.0;
    NoOfBlock = 10;
    NormalR1 = 200;
    NormalG1 = 20;
    NormalB1 = 20;
    
    CornerR = 255;
    CornerG = 255;
    CornerB = 0;
    
    NormalR2 = 52;
    NormalG2 = 245;
    NormalB2 = 255;
    
    NormalR3 = 152;
    NormalG3 = 45;
    NormalB3 = 255;
    
    NormalR4 = 152;
    NormalG4 = 245;
    NormalB4 = 55;
    
}



void Base::DrawCube2(double x1,double y1,double z1,double x2,double y2,double z2,int r,int g,int b, GLuint texId)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    
    glEnable(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, texId);        //
    
    //glPushMatrix();
    glColor4ub(255,255,255,200);
    glBegin(GL_QUADS);
    //
    glTexCoord2f(0.0f, 0.0f); glVertex3d(x1, y2, z1);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x2, y2, z1);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x2, y2, z2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x1, y2, z2);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glColor4ub(r,g,b,100);
    glBegin(GL_QUADS);
    glVertex3d(x1,y1,z1);
    glVertex3d(x2,y1,z1);
    glVertex3d(x2,y2,z1);
    glVertex3d(x1,y2,z1);
    glVertex3d(x1,y1,z2);
    glVertex3d(x2,y1,z2);
    glVertex3d(x2,y2,z2);
    glVertex3d(x1,y2,z2);
    glVertex3d(x1,y1,z1);
    glVertex3d(x2,y1,z1);
    glVertex3d(x2,y1,z2);
    glVertex3d(x1,y1,z2);
    glVertex3d(x1,y1,z1);
    glVertex3d(x1,y2,z1);
    glVertex3d(x1,y2,z2);
    glVertex3d(x1,y1,z2);
    glVertex3d(x2,y1,z1);
    glVertex3d(x2,y2,z1);
    glVertex3d(x2,y2,z2);
    glVertex3d(x2,y1,z2);
    glEnd();
    glDisable(GL_BLEND);
    
    
    
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex3d(x1,y1,z1);
    glVertex3d(x1,y1,z2);
    glVertex3d(x1,y1,z2);
    glVertex3d(x2,y1,z2);
    glVertex3d(x2,y1,z2);
    glVertex3d(x2,y1,z1);
    glVertex3d(x2,y1,z1);
    glVertex3d(x1,y1,z1);
    glVertex3d(x1,y2,z1);
    glVertex3d(x1,y2,z2);
    glVertex3d(x1,y2,z2);
    glVertex3d(x2,y2,z2);
    glVertex3d(x2,y2,z2);
    glVertex3d(x2,y2,z1);
    glVertex3d(x2,y2,z1);
    glVertex3d(x1,y2,z1);
    glVertex3d(x1,y1,z1);
    glVertex3d(x1,y2,z1);
    glVertex3d(x1,y1,z2);
    glVertex3d(x1,y2,z2);
    glVertex3d(x2,y1,z2);
    glVertex3d(x2,y2,z2);
    glVertex3d(x2,y1,z1);
    glVertex3d(x2,y2,z1);
    glEnd();
    
}





void Base::DrawCube1(double x1,double y1,double z1,double x2,double y2,double z2,int r,int g,int b, GLuint texId)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    
    glEnable(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, texId);        //
    
    //glPushMatrix();
    glColor4ub(255,255,255,200);
    glBegin(GL_QUADS);
    //
    glTexCoord2f(0.0f, 0.0f); glVertex3d(x1, y2, z1);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x1, y2, z2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x2, y2, z2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x2, y2, z1);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glColor4ub(r,g,b,100);
    glBegin(GL_QUADS);
    glVertex3d(x1,y1,z1);
    glVertex3d(x2,y1,z1);
    glVertex3d(x2,y2,z1);
    glVertex3d(x1,y2,z1);
    glVertex3d(x1,y1,z2);
    glVertex3d(x2,y1,z2);
    glVertex3d(x2,y2,z2);
    glVertex3d(x1,y2,z2);
    glVertex3d(x1,y1,z1);
    glVertex3d(x2,y1,z1);
    glVertex3d(x2,y1,z2);
    glVertex3d(x1,y1,z2);
    glVertex3d(x1,y1,z1);
    glVertex3d(x1,y2,z1);
    glVertex3d(x1,y2,z2);
    glVertex3d(x1,y1,z2);
    glVertex3d(x2,y1,z1);
    glVertex3d(x2,y2,z1);
    glVertex3d(x2,y2,z2);
    glVertex3d(x2,y1,z2);
    glEnd();
    glDisable(GL_BLEND);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex3d(x1,y1,z1);
    glVertex3d(x1,y1,z2);
    glVertex3d(x1,y1,z2);
    glVertex3d(x2,y1,z2);
    glVertex3d(x2,y1,z2);
    glVertex3d(x2,y1,z1);
    glVertex3d(x2,y1,z1);
    glVertex3d(x1,y1,z1);
    glVertex3d(x1,y2,z1);
    glVertex3d(x1,y2,z2);
    glVertex3d(x1,y2,z2);
    glVertex3d(x2,y2,z2);
    glVertex3d(x2,y2,z2);
    glVertex3d(x2,y2,z1);
    glVertex3d(x2,y2,z1);
    glVertex3d(x1,y2,z1);
    glVertex3d(x1,y1,z1);
    glVertex3d(x1,y2,z1);
    glVertex3d(x1,y1,z2);
    glVertex3d(x1,y2,z2);
    glVertex3d(x2,y1,z2);
    glVertex3d(x2,y2,z2);
    glVertex3d(x2,y1,z1);
    glVertex3d(x2,y2,z1);
    glEnd();
}



/*
 void Base::DrawBase()
 {
 DrawCube(0.0,0.0,0.0,height,depth,height,CornerR,CornerG,CornerB);
 DrawCube(0.0,0.0,height+NoOfBlock*width,height,depth,2*height+NoOfBlock*width,CornerR,CornerG,CornerB);
 for (int i=0;i<NoOfBlock;i++)
 {
 DrawCube(0.0,0.0,height+i*width,height,depth,height+(i+1)*width,NormalR1,NormalG1,NormalB1);
 DrawCube(height+i*width,0.0,2*height+NoOfBlock*width,height+(i+1)*width,depth,height+NoOfBlock*width,NormalR2,NormalG2,NormalB2);
 DrawCube(2*height+NoOfBlock*width,0.0,height+(NoOfBlock-i)*width,height+NoOfBlock*width,depth,height+(NoOfBlock-i-1)*width,NormalR3,NormalG3,NormalB3);
 DrawCube(height+(NoOfBlock-i)*width,0.0,0.0,height+(NoOfBlock-i-1)*width,depth,height,NormalR4,NormalG4,NormalB4);
 }
 DrawCube(2*height+NoOfBlock*width,0.0,2*height+NoOfBlock*width,height+NoOfBlock*width,depth,height+NoOfBlock*width,CornerR,CornerG,CornerB);
 DrawCube(2*height+NoOfBlock*width,0.0,0.0,height+NoOfBlock*width,depth,height,CornerR,CornerG,CornerB);
 }
 */



void Base::DrawBase(GLuint texId[])
{
    DrawCube1(0.0,0.0,0.0,height,depth,height,CornerR,CornerG,CornerB,texId[40]);
    DrawCube1(0.0,0.0,height+NoOfBlock*width,height,depth,2*height+NoOfBlock*width,CornerR,CornerG,CornerB,texId[41]);
    for (int i=0;i<NoOfBlock;i++)
    {
        DrawCube1(0.0,0.0,height+i*width,height,depth,height+(i+1)*width,NormalR1,NormalG1,NormalB1,texId[i]);
        DrawCube2(height+i*width,0.0,2*height+NoOfBlock*width,height+(i+1)*width,depth,height+NoOfBlock*width,NormalR2,NormalG2,NormalB2,texId[i+10]);
        DrawCube1(2*height+NoOfBlock*width,0.0,height+(NoOfBlock-i)*width,height+NoOfBlock*width,depth,height+(NoOfBlock-i-1)*width,NormalR3,NormalG3,NormalB3,texId[i+20]);
        DrawCube2(height+(NoOfBlock-i)*width,0.0,0.0,height+(NoOfBlock-i-1)*width,depth,height,NormalR4,NormalG4,NormalB4,texId[i+30]);
    }
    DrawCube1(2*height+NoOfBlock*width,0.0,2*height+NoOfBlock*width,height+NoOfBlock*width,depth,height+NoOfBlock*width,CornerR,CornerG,CornerB,texId[42]);
    DrawCube1(2*height+NoOfBlock*width,0.0,0.0,height+NoOfBlock*width,depth,height,CornerR,CornerG,CornerB,texId[43]);
}



void Base::SetTexture(YsRawPngDecoder &png, GLuint &texId,char fn1[])
{
    
    if (png.Decode(fn1)==YSOK)
    {
        //printf("Decoded\n");
        png.Flip();
    }
    else
    {
        printf("Read error.\n");
        return;
    }
    
    //png.Decode(fn1);
    //printf("test1\n");
    glGenTextures(1,&texId);  // Reserve one texture identifier
    
    glBindTexture(GL_TEXTURE_2D,texId);  // Making the texture identifier current (or bring it to the deck)
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    
    glTexImage2D
    (GL_TEXTURE_2D,
     0,    // Level of detail
     GL_RGBA,
     png.wid,
     png.hei,
     0,    // Border width, but not supported and needs to be 0.
     GL_RGBA,
     GL_UNSIGNED_BYTE,
     png.rgba);
    //printf("test2\n");
}

void Base::DrawBackground(GLuint texId)
{
    glBindTexture(GL_TEXTURE_2D,texId);
    
    glBegin(GL_QUADS);
    
    glTexCoord2d(0.0,0.0);   // For each vertex, assign texture coordinate before vertex coordinate.
    glVertex2d(0.0,800);
    
    glTexCoord2d(1.0,0.0);
    glVertex2d(1280,800);
    
    glTexCoord2d(1.0,1.0);
    glVertex2d(1280,0);
    
    glTexCoord2d(0.0,1.0);
    glVertex2d(0,0);
    
    glEnd();
    
}


