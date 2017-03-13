#include "Job_class.h"
#include "FileInput.h"

Job::Job()
{
    
}

Job::~Job()
{
    CleanUp();
}

void Job::Initialize(char args[])
{
    int nWord, wordTop[32], wordLength[32];
    char word[256];
    ParseString(nWord, wordTop, wordLength, args, 16);
    SafeStrCpy(jobTitle, args+wordTop[0], wordLength[0], 255);
    //printf("%d\n", wordLength[0]);
    SafeStrCpy(word, args+wordTop[1], wordLength[1], 255);
    jobID = atoi(word);
    SafeStrCpy(word, args+wordTop[2], wordLength[2], 255);
    focus[0] = atoi(word);
    SafeStrCpy(word, args+wordTop[3], wordLength[3], 255);
    focus[1] = atoi(word);
    SafeStrCpy(word, args+wordTop[4], wordLength[4], 255);
    jobExp[0] = atof(word);
    SafeStrCpy(word, args+wordTop[5], wordLength[5], 255);
    jobExp[1] = atof(word);
    SafeStrCpy(word, args+wordTop[6], wordLength[6], 255);
    jobExp[2] = atof(word);
    SafeStrCpy(word, args+wordTop[7], wordLength[7], 255);
    jobExp[3] = atof(word);
    SafeStrCpy(word, args+wordTop[8], wordLength[8], 255);
    maxP = atof(word);
    SafeStrCpy(word, args+wordTop[9], wordLength[9], 255);
    stdExp = atof(word);
}

void Job::GetFocus(int Focus[])
{
    Focus[0] = focus[0];
    Focus[1] = focus[1];
}

int Job::GetJobID() const
{
    return jobID;
}

char *Job::GetJobTitle()
{
    char *str = jobTitle;
    return 	str;
}

void Job::CleanUp() // is it necessary?
{
    focus[0] = 0;
    focus[1] = 0;
    jobID = 0;
    jobExp[0] = 0;
    jobExp[1] = 0;
    jobExp[2] = 0;
    jobExp[3] = 0;
    maxP = 0;
    stdExp = 0;
}
