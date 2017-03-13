#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#ifndef COURSE_CLASS_H_IS_INCLUDED
#define COURSE_CLASS_H_IS_INCLUDED

class Course
{
protected:
    char title[256];
    int focus;
    int courseID;
    int unit;
public:
    int experience[4];
    int takenBy[4];
    Course();
    ~Course();
    void Initialize(char args[]);
    char* GetTitle();
    int GetFocus() const;
    int GetID() const;
    int GetUnit() const;
    void CleanUp();
};

#endif // !COURSE_CLASS_H
