#include <stdio.h>
#include "fssimplewindow.h"
#include <stdlib.h>
#include "ysglfontdata.h"
#include "player_class.h"
#include <time.h>
#include <string>
#include "FileInput.h"
#include "Course_Class.h"
#include "incidents_class.h"
#include "Job_class.h"
#include "yspng.h"
using namespace std;
//        glColor3ub(0,0,255);
//        glRasterPos2d(100,120);
//        YsGlDrawFontBitmap12x16("Title");

//        glColor3ub(0,0,255);
//        glRasterPos2d(100,100);
//        YsGlDrawFontBitmap8x12("Text");

class Interface2D
{
    
public:
    int const windowH=800,windowW=1280,PopH=300,PopW=250;
    int WindowH=15+PopH;
    int const TextH=12;
    int const RowIncr=5;
    int const NextLine=TextH+RowIncr;
    int const Gapw=8, Gapw1= 180,Gaph=50,fontw=12,fonth=16;
    int StrLen(char const str[]);
    void DrawPlayerInfo(Player player,Course course[40]);
    void DrawCourseInterface(Course course);
    void DrawHLInterface(HuntLib huntlib);
    void DrawSGInterface(SkiboGym SG);
    void DrawTTInterface(TechTalk TT);
    void DrawSCInterface(SCraig SC);
    void DrawJobName(int x,int y,char Jobname[]);
    void DrawPlayerLabel(int x,int y);
    void DrawFirstColumnJob(int PlayerNum,char Jobname[]);
    void DrawSecondColumnJob(int PlayerNum,char Jobname[]);
    void DrawThirdColumnJob(int PlayerNum,char Jobname[]);
    void DrawCareerFair(Job thisJobs[]);
    void DrawIncidentInterface(GLuint HL);
};
