#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef JOB_CLASS_H_IS_INCLUDED
#define JOB_CLASS_H_IS_INCLUDED

class Job
{
protected:
    int focus[2];
    int jobID;
    char jobTitle[256];
public:
    double jobExp[4];
    double maxP;
    double stdExp;
    
    Job();
    ~Job();
    
    void Initialize(char args[]);
    void GetFocus(int Focus[]);
    int GetJobID() const;
    char *GetJobTitle();
    void CleanUp();
};

#endif // !JOB_CLASS_H_IS_INCLUDED
