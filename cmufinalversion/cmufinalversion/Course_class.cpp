#include "Course_class.h"
#include "FileInput.h"

Course::Course()
{
    
}
void Course::Initialize(char args[])
{
    int nWord, wordTop[32], wordLength[32];
    char word[256];
    ParseString(nWord, wordTop, wordLength, args, 16);
    SafeStrCpy(title, args + wordTop[0], wordLength[0], 255);
    SafeStrCpy(word, args + wordTop[1], wordLength[1], 255);
    courseID = atoi(word);
    SafeStrCpy(word, args + wordTop[2], wordLength[2], 255);
    unit = atoi(word);
    SafeStrCpy(word, args + wordTop[3], wordLength[3], 255);
    experience[0] = atoi(word);
    SafeStrCpy(word, args + wordTop[4], wordLength[4], 255);
    experience[1] = atoi(word);
    SafeStrCpy(word, args + wordTop[5], wordLength[5], 255);
    experience[2] = atoi(word);
    SafeStrCpy(word, args + wordTop[6], wordLength[6], 255);
    experience[3] = atoi(word);
    SafeStrCpy(word, args + wordTop[7], wordLength[7], 255);
    focus= atoi(word);
}

int Course::GetID() const
{
    return courseID;
}
int Course::GetUnit() const
{
    return unit;
}
int Course::GetFocus() const
{
    return focus;
}
char* Course::GetTitle()
{
    char* str = title;
    return str;
}

void Course::CleanUp()
{
    focus=0;
    courseID=0;
    unit=0;
}

Course::~Course()
{
    CleanUp();
}
