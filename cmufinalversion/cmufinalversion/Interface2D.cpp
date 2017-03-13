
#include "Interface2D.h"

int Interface2D::StrLen(char const str[])
{
    int count;
    
    count=sizeof(*str)/sizeof(str[0]);
    
    return count;
}

void Interface2D::DrawPlayerInfo(Player player,Course course[40])
{
    //    int WindowH=15+PopH;
    //Draw Window
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4ub(255,255,255,220);
    glBegin(GL_QUADS);
    glVertex2d(15,15);
    glVertex2d(15,WindowH);
    glVertex2d(PopW+15,WindowH);
    glVertex2d(PopW+15,15);
    
    //Draw player color
    glColor3ub(player.color[0],player.color[1],player.color[2]);
    glVertex2d(15,15);
    glVertex2d(15,41);
    glVertex2d(PopW+15,41);
    glVertex2d(PopW+15,15);
    glEnd();
    glDisable(GL_BLEND);
    
    //Draw window frame
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2d(15,15);
    glVertex2d(15,WindowH);
    glVertex2d(PopW+15,WindowH);
    glVertex2d(PopW+15,15);
    glEnd();
    
    //////////////////////////////Draw Player information////////////////////////////////////////
    //Text Info
    //    int const TextH=12;
    //    int const RowIncr=5;
    //    int const NextLine=TextH+RowIncr;
    
    //Draw Player Title
    string id_s = to_string(player.getID());
    char const *ID = id_s.c_str();
    glColor3ub(255,255,255);
    glRasterPos2d(20,36);
    YsGlDrawFontBitmap12x16("Player");
    glColor3ub(255,255,255);
    glRasterPos2d(104,36);
    YsGlDrawFontBitmap12x16(ID);
    
    //Draw experience
    string exp1_s = to_string(player.exp[0]);
    char const *EXP1= exp1_s.c_str();
    char Cfocus1[100];
    strncpy(Cfocus1,"MechE,   EXP: ",99);
    glColor3ub(0,0,0);
    glRasterPos2d(20,41+5+TextH);
    YsGlDrawFontBitmap8x12(Cfocus1);
    glRasterPos2d(20+8*strlen(Cfocus1),41+5+TextH);
    YsGlDrawFontBitmap8x12(EXP1);
    
    string exp2_s = to_string(player.exp[1]);
    char const *EXP2= exp2_s.c_str();
    char Cfocus2[100];
    strncpy(Cfocus2,"CS,      EXP: ",99);
    glColor3ub(0,0,0);
    glRasterPos2d(20,41+5+TextH+NextLine);
    YsGlDrawFontBitmap8x12(Cfocus2);
    glRasterPos2d(20+8*strlen(Cfocus2),41+5+TextH+NextLine);
    YsGlDrawFontBitmap8x12(EXP2);
    
    string exp3_s = to_string(player.exp[2]);
    char const *EXP3= exp3_s.c_str();
    char Cfocus3[100];
    strncpy(Cfocus3,"ECE,     EXP: ",99);
    glColor3ub(0,0,0);
    glRasterPos2d(20,41+5+TextH+2*NextLine);
    YsGlDrawFontBitmap8x12(Cfocus3);
    glRasterPos2d(20+8*strlen(Cfocus3),41+5+TextH+2*NextLine);
    YsGlDrawFontBitmap8x12(EXP3);
    
    string exp4_s = to_string(player.exp[3]);
    char const *EXP4= exp4_s.c_str();
    char Cfocus4[100];
    strncpy(Cfocus4,"Design,  EXP: ",99);
    glColor3ub(0,0,0);
    glRasterPos2d(20,41+5+TextH+3*NextLine);
    YsGlDrawFontBitmap8x12(Cfocus4);
    glRasterPos2d(20+8*strlen(Cfocus4),41+5+TextH+3*NextLine);
    YsGlDrawFontBitmap8x12(EXP4);
    
    
    //Draw Units
    string units_s = to_string(player.getUnits());
    char const *Units= units_s.c_str();
    char UnitsRemain[100];
    strncpy(UnitsRemain,"Units Remain: ",99);
    glColor3ub(0,0,0);
    glRasterPos2d(20,41+5+TextH+4*NextLine);
    YsGlDrawFontBitmap8x12(UnitsRemain);
    glRasterPos2d(20+8*strlen(UnitsRemain),41+5+TextH+4*NextLine);
    YsGlDrawFontBitmap8x12(Units);
    
    //Draw Player Coarse
    char CourseTaken[100];
    strncpy(CourseTaken,"Course Taken:",99);
    glColor3ub(0,0,0);
    glRasterPos2d(20,41+5+TextH+5*NextLine);
    YsGlDrawFontBitmap8x12(CourseTaken);
    
    for(int i=0;i<player.nCourse;i++)
    {
        glColor3ub(0,0,0);
        glRasterPos2d(20,41+5+TextH+(6+i)*NextLine);
        int ID=player.courseList[i];
        //printf("Before:%d\n", ID);
        if(ID>=2 && ID<=11)
        {
            ID=ID-2;
        }
        else if(ID>=13 && ID<=22)
        {
            ID=ID-3;
        }
        else if(ID>=24 && ID<=33)
        {
            ID=ID-4;
        }
        else if(ID>=35 && ID<=44)
        {
            ID=ID-5;
        }
        //printf("After:%d\n", ID);
        
        
        YsGlDrawFontBitmap8x12(course[ID].GetTitle());
    }
    
    
    
    ////////////////////////////////////////////////////////////////////////////////
}


//////////////////Draw Course Interface///////////////////////////////////////////////
void Interface2D::DrawCourseInterface(Course course)
{
    //    int WindowH=15+PopH;
    //    int const TextH=12;
    //    int const RowIncr=5;
    //    int const NextLine=TextH+RowIncr;
    //Draw Window
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4ub(255,255,255,220);
    glBegin(GL_QUADS);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),WindowH);
    glVertex2d(windowW-15,WindowH);
    glVertex2d(windowW-15,15);
    
    //Draw Title color
    glColor3ub(0,0,0);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),41);
    glVertex2d(windowW-15,41);
    glVertex2d(windowW-15,15);
    glEnd();
    glDisable(GL_BLEND);
    
    //Draw window frame
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),WindowH);
    glVertex2d(windowW-15,WindowH);
    glVertex2d(windowW-15,15);
    glEnd();
    
    //Draw Coure Title
    glColor3ub(255,255,255);
    glRasterPos2d(windowW-(PopW+15)+5,36);
    YsGlDrawFontBitmap12x16(course.GetTitle());
    
    //Draw Unit
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+5+TextH);
    YsGlDrawFontBitmap8x12("Units      : 12");
    
    //Draw experience
    string Cexp1_s = to_string(course.experience[0]);
    char const *CEXP1= Cexp1_s.c_str();
    char Cfocus1[100];
    strncpy(Cfocus1,"MechE,  EXP: ",99);
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+5+TextH+NextLine);
    YsGlDrawFontBitmap8x12(Cfocus1);
    glRasterPos2d(windowW-(PopW+15)+5+8*strlen(Cfocus1),41+5+TextH+NextLine);
    YsGlDrawFontBitmap8x12(CEXP1);
    
    string Cexp2_s = to_string(course.experience[1]);
    char const *CEXP2= Cexp2_s.c_str();
    char Cfocus2[100];
    strncpy(Cfocus2,"CS,     EXP: ",99);
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+5+TextH+2*NextLine);
    YsGlDrawFontBitmap8x12(Cfocus2);
    glRasterPos2d(windowW-(PopW+15)+5+8*strlen(Cfocus2),41+5+TextH+2*NextLine);
    YsGlDrawFontBitmap8x12(CEXP2);
    
    string Cexp3_s = to_string(course.experience[2]);
    char const *CEXP3= Cexp3_s.c_str();
    char Cfocus3[100];
    strncpy(Cfocus3,"ECE,    EXP: ",99);
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+5+TextH+3*NextLine);
    YsGlDrawFontBitmap8x12(Cfocus3);
    glRasterPos2d(windowW-(PopW+15)+5+8*strlen(Cfocus3),41+5+TextH+3*NextLine);
    YsGlDrawFontBitmap8x12(CEXP3);
    
    string Cexp4_s = to_string(course.experience[3]);
    char const *CEXP4= Cexp4_s.c_str();
    char Cfocus4[100];
    strncpy(Cfocus4,"Design, EXP: ",99);
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+5+TextH+4*NextLine);
    YsGlDrawFontBitmap8x12(Cfocus4);
    glRasterPos2d(windowW-(PopW+15)+5+8*strlen(Cfocus4),41+5+TextH+4*NextLine);
    YsGlDrawFontBitmap8x12(CEXP4);
}

void Interface2D::DrawHLInterface(HuntLib huntlib)
{
    
    //Draw Window
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4ub(255,255,255,220);
    glBegin(GL_QUADS);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),WindowH);
    glVertex2d(windowW-15,WindowH);
    glVertex2d(windowW-15,15);
    
    //Draw Title color
    glColor3ub(0,0,0);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),41);
    glVertex2d(windowW-15,41);
    glVertex2d(windowW-15,15);
    glEnd();
    glDisable(GL_BLEND);
    //Draw window frame
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),WindowH);
    glVertex2d(windowW-15,WindowH);
    glVertex2d(windowW-15,15);
    glEnd();
    
    //Draw incident Title
    glColor3ub(255,255,255);
    glRasterPos2d(windowW-(PopW+15)+5,36);
    YsGlDrawFontBitmap12x16(huntlib.huntlibTitle());
    
    //Draw incident Content
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+NextLine);
    YsGlDrawFontBitmap8x12(huntlib.huntlibDes1());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+2*NextLine);
    YsGlDrawFontBitmap8x12(huntlib.huntlibDes2());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+3*NextLine);
    YsGlDrawFontBitmap8x12(huntlib.huntlibDes3());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+4*NextLine);
    YsGlDrawFontBitmap8x12(huntlib.huntlibDes4());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+5*NextLine);
    YsGlDrawFontBitmap8x12(huntlib.huntlibDes5());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+6*NextLine);
    YsGlDrawFontBitmap8x12(huntlib.huntlibDes6());
    
    
}

void Interface2D::DrawSGInterface(SkiboGym SG)
{
    //Draw Window
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4ub(255,255,255,220);
    glBegin(GL_QUADS);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),WindowH);
    glVertex2d(windowW-15,WindowH);
    glVertex2d(windowW-15,15);
    
    //Draw Title color
    glColor3ub(0,0,0);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),41);
    glVertex2d(windowW-15,41);
    glVertex2d(windowW-15,15);
    glEnd();
    glDisable(GL_BLEND);
    //Draw window frame
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),WindowH);
    glVertex2d(windowW-15,WindowH);
    glVertex2d(windowW-15,15);
    glEnd();
    
    //Draw incident Title
    glColor3ub(255,255,255);
    glRasterPos2d(windowW-(PopW+15)+5,36);
    YsGlDrawFontBitmap12x16(SG.skiboGymTitle());
    
    //Draw incident Content
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+NextLine);
    YsGlDrawFontBitmap8x12(SG.skibDes1());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+2*NextLine);
    YsGlDrawFontBitmap8x12(SG.skibDes2());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+3*NextLine);
    YsGlDrawFontBitmap8x12(SG.skibDes3());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+4*NextLine);
    YsGlDrawFontBitmap8x12(SG.skibDes4());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+5*NextLine);
    YsGlDrawFontBitmap8x12(SG.skibDes5());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+6*NextLine);
    YsGlDrawFontBitmap8x12(SG.skibDes6());
}

void Interface2D::DrawTTInterface(TechTalk TT)
{
    //Draw Window
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4ub(255,255,255,220);
    glBegin(GL_QUADS);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),WindowH);
    glVertex2d(windowW-15,WindowH);
    glVertex2d(windowW-15,15);
    
    //Draw Title color
    glColor3ub(0,0,0);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),41);
    glVertex2d(windowW-15,41);
    glVertex2d(windowW-15,15);
    glEnd();
    glDisable(GL_BLEND);
    
    //Draw window frame
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),WindowH);
    glVertex2d(windowW-15,WindowH);
    glVertex2d(windowW-15,15);
    glEnd();
    
    //Draw incident Title
    glColor3ub(255,255,255);
    glRasterPos2d(windowW-(PopW+15)+5,36);
    YsGlDrawFontBitmap12x16(TT.techTalkTitle());
    
    //Draw incident Content
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+NextLine);
    YsGlDrawFontBitmap8x12(TT.teachTalkDes1());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+2*NextLine);
    YsGlDrawFontBitmap8x12(TT.teachTalkDes2());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+3*NextLine);
    YsGlDrawFontBitmap8x12(TT.teachTalkDes3());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+4*NextLine);
    YsGlDrawFontBitmap8x12(TT.teachTalkDes4());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+5*NextLine);
    YsGlDrawFontBitmap8x12(TT.teachTalkDes5());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+6*NextLine);
    YsGlDrawFontBitmap8x12(TT.teachTalkDes6());
}

void Interface2D::DrawSCInterface(SCraig SC)
{
    //Draw Window
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4ub(255,255,255,220);
    glBegin(GL_QUADS);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),WindowH);
    glVertex2d(windowW-15,WindowH);
    glVertex2d(windowW-15,15);
    
    //Draw Title color
    glColor3ub(0,0,0);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),41);
    glVertex2d(windowW-15,41);
    glVertex2d(windowW-15,15);
    glEnd();
    glDisable(GL_BLEND);
    
    //Draw window frame
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2d(windowW-(PopW+15),15);
    glVertex2d(windowW-(PopW+15),WindowH);
    glVertex2d(windowW-15,WindowH);
    glVertex2d(windowW-15,15);
    glEnd();
    
    //Draw incident Title
    glColor3ub(255,255,255);
    glRasterPos2d(windowW-(PopW+15)+5,36);
    YsGlDrawFontBitmap12x16(SC.sCraigTitle());
    
    //Draw incident Content
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+NextLine);
    YsGlDrawFontBitmap8x12(SC.sCraigDes1());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+2*NextLine);
    YsGlDrawFontBitmap8x12(SC.sCraigDes2());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+3*NextLine);
    YsGlDrawFontBitmap8x12(SC.sCraigDes3());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+4*NextLine);
    YsGlDrawFontBitmap8x12(SC.sCraigDes4());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+5*NextLine);
    YsGlDrawFontBitmap8x12(SC.sCraigDes5());
    
    glColor3ub(0,0,0);
    glRasterPos2d(windowW-(PopW+15)+5,41+6*NextLine);
    YsGlDrawFontBitmap8x12(SC.sCraigDes6());
}




void Interface2D::DrawJobName(int x,int y,char Jobname[])
{
    glColor3ub(0,0,0);
    glRasterPos2d(x,y);
    YsGlDrawFontBitmap12x16(Jobname);
}

void Interface2D::DrawPlayerLabel(int x, int y)
{
    for(int i=0;i<4;i++)
    {
        char P[100];
        switch(i)
        {
            case 0:strncpy(P,"Player 1 :",100);break;
            case 1:strncpy(P,"Player 2 :",100);break;
            case 2:strncpy(P,"Player 3 :",100);break;
            case 3:strncpy(P,"Player 4 :",100);break;
        }
        glColor3ub(0,0,0);
        glRasterPos2d(x,y+(Gaph+fonth)*i);
        YsGlDrawFontBitmap12x16(P);
    }
    
}

void Interface2D::DrawFirstColumnJob(int PlayerNum, char Jobname[])
{
    switch(PlayerNum)
    {
        case 1:
        {
            glColor3ub(0,0,0);
            glRasterPos2d(Gapw+10*fontw+Gapw,8*Gaph);
            YsGlDrawFontBitmap12x16(Jobname);
        };break;
        case 2:
        {
            glColor3ub(0,0,0);
            glRasterPos2d(Gapw+10*fontw+Gapw,8*Gaph+(Gaph+fonth));
            YsGlDrawFontBitmap12x16(Jobname);
        };break;
        case 3:
        {
            glColor3ub(0,0,0);
            glRasterPos2d(Gapw+10*fontw+Gapw,8*Gaph+(Gaph+fonth)*2);
            YsGlDrawFontBitmap12x16(Jobname);
        };break;
        case 4:
        {
            glColor3ub(0,0,0);
            glRasterPos2d(Gapw+10*fontw+Gapw,8*Gaph+(Gaph+fonth)*3);
            YsGlDrawFontBitmap12x16(Jobname);
        };break;
    }
    
}

void Interface2D::DrawSecondColumnJob(int PlayerNum, char Jobname[])
{
    switch(PlayerNum)
    {
        case 1:
        {
            glColor3ub(0,0,0);
            glRasterPos2d(Gapw+10*fontw+Gapw+20*fontw+Gapw1,8*Gaph);
            YsGlDrawFontBitmap12x16(Jobname);
        };break;
        case 2:
        {
            glColor3ub(0,0,0);
            glRasterPos2d(Gapw+10*fontw+Gapw+20*fontw+Gapw1,8*Gaph+(Gaph+fonth));
            YsGlDrawFontBitmap12x16(Jobname);
        };break;
        case 3:
        {
            glColor3ub(0,0,0);
            glRasterPos2d(Gapw+10*fontw+Gapw+20*fontw+Gapw1,8*Gaph+(Gaph+fonth)*2);
            YsGlDrawFontBitmap12x16(Jobname);
        };break;
        case 4:
        {
            glColor3ub(0,0,0);
            glRasterPos2d(Gapw+10*fontw+Gapw+20*fontw+Gapw1,8*Gaph+(Gaph+fonth)*3);
            YsGlDrawFontBitmap12x16(Jobname);
        };break;
    }
    
}

void Interface2D::DrawThirdColumnJob(int PlayerNum, char Jobname[])
{
    switch(PlayerNum)
    {
        case 1:
        {
            glColor3ub(0,0,0);
            glRasterPos2d(Gapw+10*fontw+Gapw+20*fontw+Gapw1+20*fontw,8*Gaph);
            YsGlDrawFontBitmap12x16(Jobname);
        };break;
        case 2:
        {
            glColor3ub(0,0,0);
            glRasterPos2d(Gapw+10*fontw+Gapw+20*fontw+Gapw1+20*fontw,8*Gaph+(Gaph+fonth));
            YsGlDrawFontBitmap12x16(Jobname);
        };break;
        case 3:
        {
            glColor3ub(0,0,0);
            glRasterPos2d(Gapw+10*fontw+Gapw+20*fontw+Gapw1+20*fontw,8*Gaph+(Gaph+fonth)*2);
            YsGlDrawFontBitmap12x16(Jobname);
        };break;
        case 4:
        {
            glColor3ub(0,0,0);
            glRasterPos2d(Gapw+10*fontw+Gapw+20*fontw+Gapw1+20*fontw,8*Gaph+(Gaph+fonth)*3);
            YsGlDrawFontBitmap12x16(Jobname);
        };break;
    }
    
}


void Interface2D::DrawCareerFair(Job thisJobs[])
{
    //char Jobname[100];
    //strncpy(Jobname,"Software Engineer***",100);
    
    //Draw Background
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4ub(255,255,255,220);
    glBegin(GL_QUADS);
    glVertex2d(0, 0);
    glVertex2d(0, 800);
    glVertex2d(1280, 800);
    glVertex2d(1280, 0);
    glEnd();
    glDisable(GL_BLEND);
    
    int k = 0;
    for(int j=0;j<5;j++)
    {
        for(int i=0;i<2;i++)
        {
            DrawJobName(Gapw+(2*Gapw1+fontw*20)*i,Gaph+fonth+(Gaph+fonth)*j, thisJobs[k].GetJobTitle());//i+5*j
            k++;
        }
    }
    
    DrawPlayerLabel(Gapw, 8*Gaph);
}


void Interface2D::DrawIncidentInterface(GLuint in)
{
    glEnable(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, in);        //
    
    //glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    //
    glTexCoord2f(0.0f, 0.0f); glVertex2d(315, 750);
    glTexCoord2f(1.0f, 0.0f); glVertex2d(1230, 750);
    glTexCoord2f(1.0f, 1.0f); glVertex2d(1230, 50);
    glTexCoord2f(0.0f, 1.0f); glVertex2d(315, 50);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
}
