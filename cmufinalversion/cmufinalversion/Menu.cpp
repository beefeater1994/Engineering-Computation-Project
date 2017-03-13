// 24-780 Engineering Computation
// Project: Courses Monopoly University
// Menu class
// Author: Juewei Dong
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "fssimplewindow.h"
#include "Menu.h"


void Menu::SelectionUpdate()
{
    /*
     int lb,mb,rb,mx,my,evt;
     evt=FsGetMouseEvent(lb,mb,rb,mx,my);
     int key=FsInkey();
     if (mx>=200 && mx<=600 && my<=290 && my>=230)
     {
     Selection=1;
     }
     else if (mx>=200 && mx<=600 && my<=360 && my>=290)
     {
     Selection=2;
     }
     else if (mx>=200 && mx<=600 && my<=420 && my>=360)
     {
     Selection=3;
     }
     else if (mx>=200 && mx<=600 && my<=490 && my>=420)
     {
     Selection=4;
     }
     else
     {
     Selection=0;
     }
     */
    
    
    if (start.MouseOver())
    {
        Selection = 1;
    }
    else if (instruction.MouseOver())
    {
        Selection =2;
    }
    else if (about.MouseOver())
    {
        Selection = 3;
    }
    
}

void Menu::PicHlLoad()
{
    char barfn[]="Highlight.png";
    bar.Decode(barfn);
    bar.Flip();
}

void Menu::PicBgLoadFile()
{
    char bgFile[]="MenuBackground.png";
    SetBgPicFile(bgFile);
    png.Decode(bgPicFile);
    png.Flip();
    PicLoad=true;
}

void Menu::PicCapLoadFile()
{
    cap.Decode(capPicFile);
    cap.Flip();
    //PicLoad=true;
}

void Menu::SetBgPicFile(char *fn)
{
    if (nullptr!=fn)
    {
        bgPicFile=fn;
    }
}

void Menu::SetCapPicFile(char *fn)
{
    if (nullptr!=fn)
    {
        capPicFile=fn;
    }
}

void Menu::PicBgDisplay()
{
    if (PicLoad)
    {
        glRasterPos2d(0,png.hei);
        glDrawPixels(png.wid,png.hei,GL_RGBA,GL_UNSIGNED_BYTE,png.rgba);
    }
}

void Menu::PicCapDisplay()
{
    glRasterPos2d(0,cap.hei);
    glDrawPixels(cap.wid,cap.hei,GL_RGBA,GL_UNSIGNED_BYTE,cap.rgba);
}

void Menu::PicHlDisplay(int Selection)
{
    if (Selection)
    {
        glRasterPos2d(250,SelectionPos[Selection-1]);
        glDrawPixels(bar.wid,bar.hei,GL_RGBA,GL_UNSIGNED_BYTE,bar.rgba);
    }
}

void Menu::ColorBgDisplay()
{
    // Get Window Size
    int wid,hei;
    FsGetWindowSize(wid,hei);
    
    glShadeModel(GL_SMOOTH);
    glBegin(GL_QUADS);
    glColor4ub(240, 255, 240, alpha);
    glVertex2i(0, 0);
    
    glColor4ub(240, 255, 240, alpha);
    glVertex2i(wid, 0);
    
    glColor4ub(255, 127, 80, alpha);
    glVertex2i(wid, hei);
    
    glColor4ub(255, 127, 80, alpha);
    glVertex2i(0, hei);
    glEnd();
}






void Menu::Menu_Set_Texture(YsRawPngDecoder &png, GLuint &texId, char fn1[])
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


void Menu::Set2D()
{
    int wid, hei;
    FsGetWindowSize(wid, hei);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, (float)wid-1, (float)hei-1, 0, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glDisable(GL_DEPTH_TEST);
}


void Menu::PicInstructionLoadFile()
{
    char InstructionFile[] = "Instruction.png";
    Menu_Set_Texture(png_instruction, png_instruction_int, InstructionFile);
    
}

void Menu::PicAboutLoadFile()
{
    char AboutFile[] = "About.png";
    Menu_Set_Texture(png_about, png_about_int, AboutFile);
    
}


void Menu::PicInstructionDisplay()
{
    Set2D();
    
    glEnable(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, png_instruction_int);        //
    
    //glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    //
    glTexCoord2f(0.0f, 0.0f); glVertex2d(0, 800);
    glTexCoord2f(1.0f, 0.0f); glVertex2d(1280, 800);
    glTexCoord2f(1.0f, 1.0f); glVertex2d(1280, 0);
    glTexCoord2f(0.0f, 1.0f); glVertex2d(0, 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
}
void Menu::PicAboutDisplay()
{
    Set2D();
    
    glEnable(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, png_about_int);        //
    
    //glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    //
    glTexCoord2f(0.0f, 0.0f); glVertex2d(0, 800);
    glTexCoord2f(1.0f, 0.0f); glVertex2d(1280, 800);
    glTexCoord2f(1.0f, 1.0f); glVertex2d(1280, 0);
    glTexCoord2f(0.0f, 1.0f); glVertex2d(0, 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Menu::WindowInit()
{
    FsPollDevice();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Menu::InitParam()
{
    alpha=0;
}

Menu::Menu()
{
    InitParam();
}

int Menu::GetSelection()
{
    return Selection;
}


void Menu::Instruction()
{
    int key = 0;
    PicInstructionLoadFile();
    
    while (key != FSKEY_SPACE)
    {
        key = FsInkey();
        
        WindowInit();
        PicInstructionDisplay();
        FsSwapBuffers();
        
        glFlush();
        FsSleep(2);
    }
}
void Menu::About()
{
    int key = 0;
    PicAboutLoadFile();
    
    while (key != FSKEY_SPACE)
    {
        key = FsInkey();
        
        WindowInit();
        PicAboutDisplay();
        
        FsSwapBuffers();
        
        glFlush();
        FsSleep(2);
    }
}




/*
 * Juewei Dong revised @ Dec/2/2016
 */
void Menu::PicBackgroundDisplay()
{
    Set2D();
    
    glEnable(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, png_background_int);        //
    
    //glPushMatrix();
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    //
    glTexCoord2f(0.0f, 0.0f); glVertex2d(0, 800);
    glTexCoord2f(1.0f, 0.0f); glVertex2d(1280, 800);
    glTexCoord2f(1.0f, 1.0f); glVertex2d(1280, 0);
    glTexCoord2f(0.0f, 1.0f); glVertex2d(0, 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Menu::PicBackgroundLoadFile()
{
    char BackgroundFile[] = "MenuBackground.png";
    Menu_Set_Texture(png_background, png_background_int, BackgroundFile);
    
}


void Menu::InitLayout()
{
    char captionfn[] = "MenuCaption.png";
    char startfn[] = "MenuStart.png";
    char aboutfn[] = "MenuAbout.png";
    char instructionfn[] = "MenuInstruction.png";
    
    // Pure picture initialize
    menuCaption.Decode(captionfn);
    menuCaption.Flip();
    
    // Button initialize
    start.LoadFile(startfn);
    about.LoadFile(aboutfn);
    instruction.LoadFile(instructionfn);
    
    // Set Button Position
    int wid, hei;
    FsGetWindowSize(wid, hei);
    
    capX = (double)wid*1.0/2.0 - menuCaption.wid/2.0;
    capY = (double)hei*3.0/16.0 + menuCaption.hei/2.0;
    
    start.PosX = (double) wid/2.0 - start.ButtonWid()/2.0;
    start.PosY = (double) hei*(4.0/8.0) + start.ButtonHei()/2.0;
    
    instruction.PosX = (double) wid/2.0 - instruction.ButtonWid()/2.0;
    instruction.PosY = (double) hei*(4.0/8.0 + 1.0/10.0) + instruction.ButtonHei()/2.0;
    
    about.PosX = (double) wid/2.0 - about.ButtonWid()/2.0;
    about.PosY = (double) hei*(4.0/8.0 + 1.0/5.0) + about.ButtonHei()/2.0;
    
}

void Menu::PicCaptionDisplay()
{
    glRasterPos2d(capX,capY);
    glDrawPixels(menuCaption.wid, menuCaption.hei, GL_RGBA,GL_UNSIGNED_BYTE, menuCaption.rgba);
}

///////




void Menu::MainMenu()
{
    int key = FsInkey();
    
    // Layout Initialization
    InitLayout();
    
    // Texture mapping version.
    PicBackgroundLoadFile();
    
    // PicBgLoadFile();
    //PicCapLoadFile();
    PicHlLoad();
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    
    while (key!=FSKEY_ESC)
    {
        WindowInit();
        
        key = FsInkey();
        
        // New version of Selection update - mouse over driven
        SelectionUpdate();
        //ColorBgDisplay();
        
        // Tex Map version
        PicBackgroundDisplay();
        
        
        // Button display
        PicCaptionDisplay();
        start.DisplayButtons();
        about.DisplayButtons();
        instruction.DisplayButtons();
        
        // PicBgDisplay();
        // PicHlDisplay(Selection);
        //PicCapDisplay();
        
        
        int lb, mb, rb, mx, my;
        int key=FsInkey();
        int evt=0;
        evt=FsGetMouseEvent(lb, mb, rb, mx, my);
        if (Selection==1 && (lb || key==FSKEY_ENTER))
        {
            break;
        }
        if (Selection == 2 && (lb || key == FSKEY_ENTER))
        {
            break;
        }
        if (Selection == 3 && (lb || key == FSKEY_ENTER))
        {
            break;
        }
        if(Selection==-1)
        {
            break;
        }
        
        FsSwapBuffers();
        
        glFlush();
        FsSleep(2);
    }
    
    
}
