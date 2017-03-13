// 24-780 Engineering Computation
// Project: Courses Monopoly University
// Player class (Header file)
// Author: Ziang Lu

#ifndef Player_class_h
#define Player_class_h

#include "Course_class.h"
#include "Job_class.h"
#include "Base_class.h"

class Player
{
protected:
    int ID;
    int units;
    double height;
    double radius;
    
    const double YsPi = 3.1415927;
    
public:
    int state; // 1: Alive, 0: Dead, // Special state 2: Stopped
    int active; // 1: Available in the current round, 0: Unavailable in the current round
    int courseList[15]; // Course IDs that the player have taken
    int nCourse; // Length of courseList
    int exp[4]; // Player's experience in the four focuses
	int selected[3] = { -1,-1,-1 }; // Indicates the IDs of the selected jobs during career fair
    
    int position; // Player's position index on the map
    int color[3]; // R, G, B values of the player
    
    Player(); // Default constructor
    
    int getID(void) const;
    int getUnits(void) const;
    double getHeight(void) const;
    double getRadius(void) const;
    
    void SetID(const int);
    
    void ResetSelected(void);
    
    bool TryFindJob(const Job job) const;
    double CalculatePossibility(const Job job) const;
    
    int RollDice(void) const;
    void Move(const int size);
    
    void TakeCourse(const Course course);
    bool CheckRepeatCourse(const Course course) const;
    
    void Draw(const Base base) const;
    void DrawCylinder(const double x, const double y, const double z, const double radius, const double height) const;
};


#endif
