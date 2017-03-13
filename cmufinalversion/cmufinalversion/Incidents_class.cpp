#include <stdio.h>
#include <stdlib.h>
#include "Incidents_class.h"
#include "Player_class.h"
/*
 Incidents
 Author: Ruihan Fan
 There are four incidents in this game.
 */

#define expN 4
/*
 The first one, Hunt library, increase the exp by 1 in each field.
 */

char *HuntLib::huntlibTitle() {
    char *title = "Hunt Library";
    return title;
}

char* HuntLib::huntlibDes1() {
    char* des1 = "Welcome to Hunt Library!";
    return des1;
}
char* HuntLib::huntlibDes2() {
    char* des2 = "Because of your hardwork, your";
    return des2;
}
char* HuntLib::huntlibDes3() {
    char* des3 = "experience in each field has";
    return des3;
}
char* HuntLib::huntlibDes4() {
    char* des4 = "been added by 1.";
    return des4;
}
char* HuntLib::huntlibDes5() {
    char* des5 = " ";
    return des5;
}
char* HuntLib::huntlibDes6() {
    char* des6 = " ";
    return des6;
}

void HuntLib::huntlib(Player &player) {
    for (int i = 0; i < expN; i++) {
        player.exp[i] += 1;
    }
}

/*
 The second one. skiboGym, decrease the exp by 2 in each field.
 */
char* SkiboGym::skiboGymTitle() {
    char* title = "Skibo Gym";
    return title;
}
char* SkiboGym::skibDes1() {
    char* des1 = "Welcome to Skibo Gym!";
    return des1;
}
char* SkiboGym::skibDes2() {
    char* des2 = "Unfortunately, you got hurt";
    return des2;
}
char* SkiboGym::skibDes3() {
    char* des3 = "in the gym, you have to be";
    return des3;
}
char* SkiboGym::skibDes4() {
    char* des4 = "absent for a week. Your experi";
    return des4;
}
char* SkiboGym::skibDes5() {
    char* des5 = "-ence in each field will be ";
    return des5;
}
char* SkiboGym::skibDes6() {
    char* des6 = "decreased by 2.";
    return des6;
}
void SkiboGym::skiboGym(Player &player) {
    for (int i = 0; i < expN; i++) {
        player.exp[i] -= 2;
        if (player.exp[i] < 0) {
            player.exp[i] = 0;
        }
    }
}
/*
 The third one, TechTalk, increase the exp in one filed.
 */
char* TechTalk::techTalkTitle(){
    char* title = "Tech Talk";
    return title;
}
char* TechTalk::teachTalkDes1() {
    char* des1 = "Welcome to Tech Talk!";
    return des1;
}
char* TechTalk::teachTalkDes2() {
    char* des2 = "You have attended a tech talk.";
    return des2;
}
char* TechTalk::teachTalkDes3() {
    char* des3 = "Your experience in this field";
    return des3;
}
char* TechTalk::teachTalkDes4() {
    char* des4 = "has been added by 5";
    return des4;
}
char* TechTalk::teachTalkDes5() {
    char* des5 = " ";
    return des5;
}
char* TechTalk::teachTalkDes6() {
    char* des6 = " ";
    return des6;
}
void TechTalk::techTalk(Player &player) {
    int i = 4 % rand();
    player.exp[i] += 5;
}
/*
 The fourth one, sCraig, the palyer stop to do anything in this round.
 */
char* SCraig::sCraigTitle() {
    char* title = "South Craig";
    return title;
}
char* SCraig::sCraigDes1() {
    char* des1 = "Welcome to South Craig";
    return des1;
}
char* SCraig::sCraigDes2() {
    char* des2 = "Cause you have been robbed in";
    return des2;
}
char* SCraig::sCraigDes3() {
    char* des3 = "South Craig, you're too scared";
    return des3;
}
char* SCraig::sCraigDes4() {
    char* des4 = "to go to school. You will do";
    return des4;
}
char* SCraig::sCraigDes5() {
    char* des5 = "nothing this round.";
    return des5;
}
char* SCraig::sCraigDes6() {
    char* des6 = " ";
    return des6;
}
void SCraig::sCraig(Player &player) {
    player.state = 2;// State 1: Alive, 0: Dead, 2: Stopped
}

