//
//  Camera_class.h
//  Project_3D_BoardAndPlayer_WithPopup
//
//  Created by Liu Yuzhang on 16/11/20.
//  Copyright © 2016年 Yuzhang Liu. All rights reserved.
//


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "fssimplewindow.h"
#include "Player_class.h"
#include "Base_class.h"




#ifndef Camera_class_h
#define Camera_class_h

//extern const double YsPi;

class CameraObject
{
public:
    const double YsPi = 3.1415927;
    double x,y,z;
    double h,p,b;
    
    double fov,nearZ,farZ;
    
    
    CameraObject();
    void Initialize(void);
    void SetUpCameraProjection(void);
    void SetUpCameraTransformation(void);
    
    void GetForwardVector(double &vx,double &vy,double &vz);
    void MoveCamera(Player player, Base base);
};



#endif /* Camera_class_h */
