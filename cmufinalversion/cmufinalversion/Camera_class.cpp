//
//  Camera_class.cpp
//  Project_3D_BoardAndPlayer_WithPopup
//
//  Created by Liu Yuzhang on 16/11/20.
//  Copyright © 2016年 Yuzhang Liu. All rights reserved.
//

#include "Camera_class.h"



CameraObject::CameraObject()
{
    Initialize();
}

void CameraObject::Initialize(void)
{
    x= -200 ;
    y= 200;
    z= -200;
    h= -YsPi/2 - YsPi/4;
    p=-YsPi/6;
    b=0;
    
    fov=YsPi/6.0;  // 30 degree
    //nearZ=0.1;
    //farZ=200.0;
    nearZ = 1.0;
    farZ = 1000;
}

void CameraObject::SetUpCameraProjection(void)
{
    int wid,hei;
    double aspect;
    
    FsGetWindowSize(wid,hei);
    aspect=(double)wid/(double)hei;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov*180.0/YsPi,aspect,nearZ,farZ);
}

void CameraObject::SetUpCameraTransformation(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotated(-b*180.0/YsPi,0.0,0.0,1.0);  // Rotation about Z axis
    glRotated(-p*180.0/YsPi,1.0,0.0,0.0);  // Rotation about X axis
    glRotated(-h*180.0/YsPi,0.0,1.0,0.0);  // Rotation about Y axis
    glTranslated(-x,-y,-z);
}

void CameraObject::GetForwardVector(double &vx,double &vy,double &vz)
{
    vx=-cos(p)*sin(h);
    vy= sin(p);
    vz=-cos(p)*cos(h);
}


void CameraObject::MoveCamera(Player player,Base base)
{
    if (player.position==1)
    {
        h=-YsPi/2 - YsPi/4;
        x = -200;
        z = -200;
    }
    if (player.position==12)
    {
        h= - YsPi/4;
        x = -200;
        z = (2*base.height+base.NoOfBlock*base.width)+200;
    }
    if (player.position==23)
    {
        h=  YsPi/4;
        x = (2*base.height+base.NoOfBlock*base.width)+200;
        z = (2*base.height+base.NoOfBlock*base.width)+200;
    }
    if (player.position==34)
    {
        h= 3*YsPi/4;
        x = (2*base.height+base.NoOfBlock*base.width)+200;
        z = -200;
    }
    if (player.position>1&&player.position<12)
    {
        h = -YsPi/2;
        x = -282;
        z = base.height + (player.position-1-0.5)*base.width;
    }
    if (player.position>12&&player.position<23)
    {
        h = 0;
        x = base.height + (player.position-12-0.5)*base.width;
        z = (2*base.height+base.NoOfBlock*base.width)+282;
    }
    
    if (player.position>23&&player.position<34)
    {
        h = YsPi/2;
        x = 2 * base.height + base.NoOfBlock*base.width + 282;
        z =  base.height + base.NoOfBlock*base.width - (player.position-23-0.5)*base.width;
    }
    
    if (player.position>34&&player.position<=44)
    {
        h = YsPi;
        x= base.height + base.NoOfBlock*base.width - (player.position-34-0.5)*base.width;
        z = -282;
    }
}


