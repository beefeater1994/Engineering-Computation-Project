#include "FileInput.h"
char *Fgets(char str[], int maxLength, FILE *fp)
{
    if (nullptr != fgets(str, maxLength, fp))
    {
        for (int i = 0; 0 != str[i]; ++i)
        {
            if ('\n' == str[i])
            {
                str[i] = 0;
            }
        }
        return str;
    }
    else
    {
        return nullptr;
    }
}

void RemoveTailControlCode(char str[])
{
    int i, lng;
    lng = strlen(str);
    for (i = lng - 1; i >= 0; i--)
    {
        if (isprint(str[i]) == 0)
        {
            str[i] = 0;
        }
        else
        {
            break;
        }
    }
}

void SafeStrCpy(char dst[], char src[], int nLetters, int nLimit)
{
    int i, stopper;
    if (nLetters<nLimit)
    {
        stopper = nLetters;
    }
    else
    {
        stopper = nLimit;
    }
    
    for (i = 0; i<stopper; i++)
    {
        dst[i] = src[i];
    }
    dst[stopper] = 0;
}


int ParseString(
                int &nWord,
                int wordTop[],
                int wordLength[],
                char str[],
                int maxNumWords)
{
    int i, state;
    
    state = 0;
    nWord = 0;
    for (i = 0; str[i] != 0; i++)
    {
        switch (state)
        {
            case 0:
                if (
                    str[i] != '\t' &&
                    str[i] != ',')
                {
                    state = 1;
                    wordTop[nWord] = i;
                    wordLength[nWord] = 1;
                    nWord++;
                }
                break;
            case 1:
                if (
                    str[i] != '\t' &&
                    str[i] != ',')
                {
                    wordLength[nWord - 1]++;
                }
                else
                {
                    state = 0;
                    if (nWord == maxNumWords)
                    {
                        goto LOOPOUT;
                    }
                }
                break;
        }
    }
LOOPOUT:
    return nWord;
}
