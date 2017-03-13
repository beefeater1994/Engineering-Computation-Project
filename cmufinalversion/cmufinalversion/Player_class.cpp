// 24-780 Engineering Computation
// Project: Courses Monopoly University
// Player class (cpp file)
// Author: Ziang Lu

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#include "fssimplewindow.h"

#include "Player_class.h"

// Default constructor
Player::Player()
{
    state = 1;
    active = 0;
    units = 96;
    
    for(int i=0; i<100; i++)
        courseList[i] = 0;
    nCourse = 0;
    
    for(int i=0; i<4; i++)
        exp[i] = 0;
    
    position = 1;
    ResetSelected();
    
    color[0] = rand()%255;
    color[1] = rand()%255;
    color[2] = rand()%255;
    height = 15;
    radius = 5;
}

// Method to return the ID of the player
int Player::getID(void) const
{
    return ID;
}

// Method to return the units of the player
int Player::getUnits(void) const
{
    return units;
}

// Method to return the height of the player
double Player::getHeight(void) const
{
    return height;
}

// Method to return the radius of the player
double Player::getRadius(void) const
{
    return radius;
}

// Method to set the ID of the player
void Player::SetID(const int ID)
{
    this->ID = ID;
}

void Player::ResetSelected(void)
{
    for(int i=0; i<3; i++)
        selected[i] = 0;
}

// Method for the player to try to find a job
bool Player::TryFindJob(const Job job) const
{
    if((state==1) && (active==1))
    {
        const double per = 100*CalculatePossibility(job);
        const int threshold = round(per);
        
        if(rand()%101<threshold)
            return true;
        return false;
    }
    return false;
}

// Method to calculate the possibility for the player to successfully get the job
double Player::CalculatePossibility(const Job job) const
{
    int totalExp = 0;
    for(int i=0; i<4; i++)
        totalExp += exp[i]*job.jobExp[i];
    
    if(totalExp>=job.stdExp)
        return job.maxP;
    else
        return totalExp*(job.maxP/job.stdExp);
}

// Method for the player to roll a dice
int Player::RollDice(void) const
{
    srand((int)time(NULL));
    
    return rand() % 6 + 1;
}

// Method for the player to move one step
void Player::Move(const int size)
{
    if((state==1) && (active==1))
    {
        position++;
        
        if(position>size)
            position %= size;
    }
}

// Method for the player to take a course
// The course ID is added to the back of the course list.
void Player::TakeCourse(const Course course)
{
    if((state==1) && (active==1) && (units>=course.GetUnit()) && (CheckRepeatCourse(course)==false))
    {
        units -= course.GetUnit();
        
        for(int &c : courseList) // Range based for (with pass-by-reference)
        {
            if(c==0)
            {
                c = course.GetID();
                break;
            }
        }
        nCourse++;
        
        for(int i=0; i<4; i++)
            exp[i] += course.experience[i];
    }
}

// Method to check whether the incoming course has been added to the course list
bool Player::CheckRepeatCourse(const Course course) const
{
    for(int i=0; courseList[i]!=0; i++)
    {
        if(courseList[i]==course.GetID())
            return true;
    }
    return false;
}

// Method to draw the player on the map
void Player::Draw(const Base base) const
{
    double x, y, z;
    if (position==1)
    {
        x = base.height/2;
        z = base.height/2;
    }
    if (position==12)
    {
        x = base.height/2;
        z = base.height*1.5 + base.NoOfBlock*base.width;
    }
    if (position==23)
    {
        x = base.height*1.5 + base.NoOfBlock*base.width;
        z = base.height*1.5 + base.NoOfBlock*base.width;
    }
    if (position==34)
    {
        x = base.height*1.5 + base.NoOfBlock*base.width;
        z = base.height/2;
    }
    if ((position>1) && (position<12))
    {
        x = base.height/2;
        z = base.height + (position-1-0.5)*base.width;
    }
    if ((position>12) && (position<23))
    {
        x = base.height + (position-12-0.5)*base.width;
        z = base.height*1.5 + base.NoOfBlock*base.width;
    }
    if ((position>23) && (position<34))
    {
        x = base.height*1.5 + base.NoOfBlock*base.width;
        z = base.height + (34-position-0.5)*base.width;
    }
    if ((position>34) && (position<=44))
    {
        x = base.height + (44-position+0.5)*base.width;
        z = base.height/2;
    }
    
    y = base.depth;
    
    DrawCylinder(x, y, z, radius, height);
}

void Player::DrawCylinder(const double x, const double y, const double z, const double radius,const double height) const
{
    glColor3ub(100, 100, 100);
    
    glBegin(GL_TRIANGLE_FAN);
    for(int i=0; i<=360; i+=10)
    {
        double rad = i*YsPi/180.0;
        double s = radius*sin(rad);
        double c = radius*cos(rad);
        
        glVertex3d(c+x, y, s+z);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    for(int i=0; i<=360; i+=10)
    {
        double rad = i*YsPi/180.0;
        double s= radius*sin(rad);
        double c= radius*cos(rad);
        
        glVertex3d(c+x, y+height, s+z);
    }
    glEnd();
    
    glBegin(GL_QUADS);
    for(int i=0; i<=360; i+=10)
    {
        /*glColor3ub(191, 62, 255);*/
        glColor3ub(color[0], color[1], color[2]);
        
        double r0 = i*YsPi/180.0;
        double s0 = radius*sin(r0);
        double c0 = radius*cos(r0);
        
        double r1 = (i+10)*YsPi/180.0;
        double s1 = radius*sin(r1);
        double c1 = radius*cos(r1);
        
        glVertex3d(c0+x, y+height, s0+z);
        glVertex3d(c1+x, y+height, s1+z);
        glVertex3d(c1+x, y, s1+z);
        glVertex3d(c0+x, y, s0+z);
    }
    glEnd();
}

