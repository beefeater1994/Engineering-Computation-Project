// 24-780 Engineering Computation
// Project: Courses Monopoly University
// Incidents Class
// Author: Ruihan Fan

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef Incidents_class_h
#define Incidents_class_h
using namespace std;
/*
 The Incidents Class contains four methods indicating these incidents when the player comes to special places.
 */

//The first one, Hunt library, increase the exp by 1 in each field.
class HuntLib {
public:
    char * huntlibTitle();
    char* huntlibDes1();
    char* huntlibDes2();
    char* huntlibDes3();
    char* huntlibDes4();
    char* huntlibDes5();
    char* huntlibDes6();
    void huntlib(class Player &player);
};
//The second one. skiboGym, decrease the exp by 2 in each field.
class SkiboGym {
public:
    char* skiboGymTitle();
    char* skibDes1();
    char* skibDes2();
    char* skibDes3();
    char* skibDes4();
    char* skibDes5();
    char* skibDes6();
    void skiboGym(class Player &player);
};
//The third one, TechTalk, increase the exp in one filed.
class TechTalk {
public:
    char* techTalkTitle();
    char* teachTalkDes1();
    char* teachTalkDes2();
    char* teachTalkDes3();
    char* teachTalkDes4();
    char* teachTalkDes5();
    char* teachTalkDes6();
    void techTalk(class Player &player);
};
//The fourth one, sCraig, the palyer stop to do anything in this round.
class SCraig {
public:
    char* sCraigTitle();
    char* sCraigDes1();
    char* sCraigDes2();
    char* sCraigDes3();
    char* sCraigDes4();
    char* sCraigDes5();
    char* sCraigDes6();
    void sCraig(class Player &player);
};
class Incidents {
public:
    class HuntLib;
    class SkiboGym;	
    class TechTalk;	
    class SCraig;
};
#endif // !INCIDENTS_CLASS_H
