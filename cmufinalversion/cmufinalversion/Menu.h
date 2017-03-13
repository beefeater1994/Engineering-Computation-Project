// 24-780 Engineering Computation
// Project: Courses Monopoly University
// Menu class
// Author: Juewei Dong

#include "yspng.h"
#include "Button.h"


#ifndef Menu_class_h
#define Menu_class_h

class Menu
{
protected:
    
    /*
     * Seperate Picture Display of selection: Enabling alpha channel of PNG file.
     * New feature: using button class to create the layout.
     * Revised by Juewei Dong @ Dec/2/2016
     */
    YsRawPngDecoder menuCaption;
    Button start, about, instruction;
    double capX, capY;
    void InitLayout();    // Initiate button layout of main menu
    
    
    
    // Screen Background Alpha
    double alpha;
    // Initiate parameters
    char *bgPicFile;
    char *capPicFile;
    void InitParam();
    void WindowInit();
    
    int StartPos=290;
    int LoadGamePos;
    int InsPos;
    int AbtPos;
    
    int SelectionPos[4]={290,360,420,490};
    int Selection=0;
    
    YsRawPngDecoder png;
    
    /* Added by Yuzhang Liu & Angran Li @ Dec/2/2016
     * Adding texture mapping features of pictures.
     */
    
    
    YsRawPngDecoder png_about;
    YsRawPngDecoder png_instruction;
    GLuint png_about_int;
    GLuint png_instruction_int;
    
    
    void PicInstructionLoadFile();
    void PicAboutLoadFile();
    void PicInstructionDisplay();
    void PicAboutDisplay();
    ////////////////////////////
    
    YsRawPngDecoder cap;
    YsRawPngDecoder bar;
    
    bool PicLoad=false;
    void PicBgLoadFile();
    void PicCapLoadFile();
    void PicBgDisplay();
    void PicCapDisplay();
    
    /* Added by Juewei Dong Li @ Dec/2/2016
     * Adding texture mapping features of background pictures.
     */
    YsRawPngDecoder png_background;
    GLuint png_background_int;
    void PicBackgroundLoadFile();
    void PicBackgroundDisplay();
    void PicCaptionDisplay();
    
    
    
    
    void PicHlLoad();
    void PicHlDisplay(int Selection);
public:
    Menu();
    void MainMenu();
    void Instruction();
    void About();
    void ColorBgDisplay();
    
    
    void SetBgPicFile(char *fn);
    void SetCapPicFile(char *fn);
    int GetSelection();
    void SelectionUpdate();
    
    /* Added by Yuzhang Liu & Angran Li @ Dec/2/2016
     * Adding texture mapping features of pictures.
     */
    void Menu_Set_Texture(YsRawPngDecoder &png, GLuint &texId, char fn1[]);
    void Set2D();
};

#endif
