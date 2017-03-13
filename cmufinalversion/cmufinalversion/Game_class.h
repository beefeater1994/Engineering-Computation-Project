#ifndef Game_class_h
#define Game_class_h

#include <string>

#include "Player_class.h"
#include "FileInput.h"
#include "Course_class.h"
#include "Job_class.h"
#include "Incidents_class.h"
#include "Base_class.h"
#include "Camera_class.h"
#include "Interface2D.h"

#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "yspng.h"
#include "yssimplesound.h"

class Game
{
public:
    Player P[4];
    Course courses[40];
    Job job[40];
    HuntLib huntLib;
    SkiboGym skiboGym;
    TechTalk techTalk;
    SCraig scraig;
    Base base;
    CameraObject camera;
    Interface2D i2d;
    int GameAction; // Indicates the action that the current frame is to take
    int accumStep; // Indicates the total steps that the four players have moved
    int winner; // Indicates the index of the winner player
    
    Game(); // Default constructor
    
    void RunGame(void);
    int FindCourseIndex(const int) const;
    void Set2DBack(void);
    void Set3D(void);
    void Set2D(void);
    void CareerFair(void);
    void NewCareerFair(void);
    void SwapInt(int &, int &);
    bool CheckRepeatSelection(const int [], const int) const;
    void DrawWinner(void);
};


#endif
