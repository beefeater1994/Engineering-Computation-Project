#include "Game_class.h"

#define Game_Choose 1
#define Game_Try_Find_Job 2
#define Game_Move 3
#define Game_Confirm 4
#define Game_Hunt_Confirm 5
#define Game_Skibo_Confirm 6
#define Game_Tech_Confirm 7
#define Game_South_Confirm 8
#define Game_Career_Fair 9

// Default constructor
Game::Game()
{
    // Set ID of each player
    P[0].SetID(1);
    P[1].SetID(2);
    P[2].SetID(3);
    P[3].SetID(4);
    
    // Read data from CourseInfo.txt
    FILE *fp1;
    fp1 = fopen("CourseInfo.txt", "r");
    char temp[256];
    int i = 0;
    if ((fp1!=NULL) && (Fgets(temp, 255, fp1)!=NULL))
    {
        while((Fgets(temp, 255, fp1)!=NULL) && (i<40))
        {
            int nWord, wordTop[16], wordLength[16];
            ParseString(nWord, wordTop, wordLength, temp, 16);
            courses[i].Initialize(temp);
            i++;
        }
    }
    fclose(fp1);
    
    // Read data from JobInfo.txt
    FILE *fp2;
    fp2 = fopen("JobInfo.txt", "r");
    i = 0;
    if((fp2!=NULL) && (Fgets(temp, 255, fp2)!=NULL))
    {
        while((Fgets(temp, 255, fp2)!=NULL) && (i<40))
        {
            int nWord, wordTop[16], wordLength[16];
            ParseString(nWord, wordTop, wordLength, temp, 16);
            job[i].Initialize(temp);
            i++;
        }
    }
    fclose(fp2);
    
    GameAction = 0;
    accumStep = 0;
    
    winner = -1;
}

void Game::RunGame()
{
    int terminate = 0;
    
    int round = 0; // Indicate the index of the current player
    P[round].active = 1;
    GameAction = Game_Choose;
    int totalStep, step; // Indicate the total steps that the current player will move, and the steps he has moved
    int count = 0; // Used to delay one step to 0.5 second
    
    // Import the background image
    YsRawPngDecoder png;
    GLuint texId;
    char fn1[256];
    strncpy(fn1, "CMUBackground.png", 255);
    base.SetTexture(png, texId, fn1);
    
    // Import the block images
    YsRawPngDecoder pngBlock[44];
    GLuint texIdBlock[44];
    
    char picture1[256];
    char picture3[256];
    for (int picturei=0; picturei<44; picturei++)
    {
        strncpy(picture1, "c", 255);
        strncpy(picture3, ".png", 255);
        string picture2_s = to_string(picturei+1);
        const char *picture2 = picture2_s.c_str();
        strcat(picture1, picture2);
        strcat(picture1, picture3);
        base.SetTexture(pngBlock[picturei], texIdBlock[picturei], picture1);
    }
    
    // Import incident images
    YsRawPngDecoder pngIN[4];
    GLuint texIdIN[4];
    
    char In1[256];
    strncpy(In1, "HuntLibrary_Incident.png", 255);
    base.SetTexture(pngIN[0], texIdIN[0], In1);
    
    char In2[256];
    strncpy(In2, "SkiboGym_Incident.png", 255);
    base.SetTexture(pngIN[1], texIdIN[1], In2);
    
    char In3[256];
    strncpy(In3, "TechTalk_Incident.png", 255);
    base.SetTexture(pngIN[2], texIdIN[2], In3);
    
    char In4[256];
    strncpy(In4, "SouthCraig_Incident.png", 255);
    base.SetTexture(pngIN[3], texIdIN[3], In4);
    
    // Import sound files
    YsSoundPlayer player;
    player.MakeCurrent();
    player.Start();
    FsChangeToProgramDir();
    
    YsSoundPlayer::SoundData summer, notice, skiboSound;
    if ((summer.LoadWav("summer.wav")!=YSOK) && (summer.LoadWav("datafiles/summer.wav")!=YSOK))
        printf("Error!\n");
    if ((notice.LoadWav("notice.wav")!=YSOK) && (notice.LoadWav("datafiles/notice.wav")!=YSOK))
        printf("Error!\n");
    if ((skiboSound.LoadWav("jarvis_service.wav")!=YSOK) && (skiboSound.LoadWav("datafiles/jarvis_service.wav")!=YSOK))
        printf("Error!\n");
    
    int incidentSoundState = 0; // Indicates whether the player is invoking the incident, or is about to go out of the incident
    
    player.PlayBackground(summer);

    while(terminate==0)
    {
        FsPollDevice();
        
        // Check key stroke
        int key = FsInkey();
        
        // Press ESC to quit the game
        if(key==FSKEY_ESC)
        {
            terminate = 1;
            break;
        }
        
        // Check current game action
        
        if(GameAction==Game_Choose)
        {
            // Check whether the player is in South Craig St
            // If the player is in South Craig St, stop one round
            if((P[round].position==34) && (P[round].state==2))
            {
                P[round].state = 1;
                
                // Add a South_Stop_Confirm action, and GameAction=Game_South_Stop_Confirm
                
                GameAction = Game_Confirm;
            }
            
            switch(key)
            {
                case FSKEY_F:
                    // Try to find a job
                    GameAction = Game_Try_Find_Job;
                    break;
                case FSKEY_M:
                    // Move
                    GameAction = Game_Move;
                    totalStep = P[round].RollDice();
                    step = 0;
                    accumStep += totalStep;
                    break;
            }
        }
        
        if(GameAction==Game_Try_Find_Job)
        {
            // Get three random distinct jobs from the job list
            int j[3];
            while(true)
            {
                for(int i=0; i<3; i++)
                    j[i] = rand()%40 + 1; // Ranging between 1 and 40
                
                if((j[0]!=j[1]) && (j[1]!=j[2]) && (j[2]!=j[0]))
                    break;
            }
            
            for(int i=0; i<3; i++)
            {
                printf("%s\n", job[j[i]].GetJobTitle());
                if (P[round].TryFindJob(job[j[i]]))
                {
                    winner = round;
                    terminate = 1;
                    break;
                }
            }
            
            // Switch to next player
            P[round].active = 0;
            round++;
            round %= 4;
            P[round].active = 1;
            GameAction = Game_Choose;
        }
        
        if((GameAction==Game_Move) && (step<=totalStep))
        {
            if((step<totalStep) && (count>=20))
            {
                // Move one step
                P[round].Move(44);
                step++;
                count = 0; // Reset the counter
            }
            else if(step==totalStep)
            {
                // The player has moved to the temporary destination.
                
                // Check if invoke career fair
                if(accumStep>10)
                {
                    NewCareerFair();
                    accumStep = 0;
                }
                
                // Check invoke incidents
                if(P[round].position==1)
                {
                    huntLib.huntlib(P[round]);
                    GameAction = Game_Hunt_Confirm;
                    
                    // Change the sound state to play one shot of the incident sound
                    incidentSoundState = 1;
                }
                else if(P[round].position==12)
                {
                    skiboGym.skiboGym(P[round]);
                    GameAction = Game_Skibo_Confirm;
                    
                    // Change the sound state to play one shot of the incident sound
                    incidentSoundState = 1;
                    
                }
                else if(P[round].position==23)
                {
                    techTalk.techTalk(P[round]);
                    GameAction = Game_Tech_Confirm;
                    
                    // Change the sound state to play one shot of the incident sound
                    incidentSoundState = 1;
                }
                else if(P[round].position==34)
                {
                    scraig.sCraig(P[round]);
                    GameAction = Game_South_Confirm;
                    
                    // Change the sound state to play one shot of the incident sound
                    incidentSoundState = 1;
                }
                else
                {
                    switch(key)
                    {
                        case FSKEY_T:
                        {
                            // Take the course
                            
                            // Find the index of the course according to its ID, and the take the course
                            int courseID = P[round].position;
                            int IDindex = FindCourseIndex(courseID);
                            P[round].TakeCourse(courses[IDindex]);
                            
                            GameAction = Game_Confirm;
                            
                            // Play one shot of the take-course sound
                            player.Stop(notice);
                            player.PlayOneShot(notice);
                            
                            break;
                        }
                        case FSKEY_N:
                        {
                            // Not take the course and switch to next player
                            P[round].active = 0;
                            round++;
                            round %= 4;
                            P[round].active = 1;
                            GameAction = Game_Choose;
                            break;
                        }
                    }
                }
            }
        }
        
        if(GameAction==Game_Confirm)
        {
            if(key==FSKEY_C)
            {
                // Switch to next player
                P[round].active = 0;
                round++;
                round %= 4;
                P[round].active = 1;
                GameAction = Game_Choose;
            }
        }
        
        if(GameAction==Game_Hunt_Confirm)
        {
            // Play one shot of the incident sound only when the player invokes the incident
            if(incidentSoundState==1)
            {
                player.Stop(skiboSound);
                player.PlayOneShot(skiboSound);
                
                incidentSoundState = 0; // Reset incidentSountState
            }
            
            // Press ENTER to continue
            if(key==FSKEY_ENTER)
            {
                // Switch to next player
                P[round].active = 0;
                round++;
                round %= 4;
                P[round].active = 1;
                GameAction = Game_Choose;
            }
        }
        
        if(GameAction==Game_Skibo_Confirm)
        {
            // Play one shot of the incident sound only when the player invokes the incident
            if(incidentSoundState==1)
            {
                player.Stop(skiboSound);
                player.PlayOneShot(skiboSound);
                
                incidentSoundState = 0; // Reset incidentSountState
            }
            
            // Press ENTER to continue
            if(key==FSKEY_ENTER)
            {
                // Switch to next player
                P[round].active = 0;
                round++;
                round %= 4;
                P[round].active = 1;
                GameAction = Game_Choose;
            }
        }
        
        if(GameAction==Game_Tech_Confirm)
        {
            // Play one shot of the incident sound only when the player invokes the incident
            if(incidentSoundState==1)
            {
                player.Stop(skiboSound);
                player.PlayOneShot(skiboSound);
                
                incidentSoundState = 0; // Reset the incidentSoundState
            }
            
            // Press ENTER to continue
            if(key==FSKEY_ENTER)
            {
                // Switch to next player
                P[round].active = 0;
                round++;
                round %= 4;
                P[round].active = 1;
                GameAction = Game_Choose;
            }
        }
        
        if(GameAction==Game_South_Confirm)
        {
            // Play one shot of the incident sound only when the player invokes the incident
            if(incidentSoundState==1)
            {
                player.Stop(skiboSound);
                player.PlayOneShot(skiboSound);
                
                incidentSoundState = 0; // Reset incidentSoundState
            }
            
            // Press ENTER to continue
            if(key==FSKEY_ENTER)
            {
                // Switch to next player
                P[round].active = 0;
                round++;
                round %= 4;
                P[round].active = 1;
                GameAction = Game_Choose;
            }
        }
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // Draw 2D background
        Set2DBack();
        base.DrawBackground(texId);
        
        // Draw 3D map
        Set3D();
        base.DrawBase(texIdBlock);
        for(int i=0; i<4; i++)
        {
            P[i].Draw(base);
            
            // Move the camera towards the current player
            if (P[i].active==1)
                camera.MoveCamera(P[i], base);
        }
        
        // Draw 2D information
        Set2D();
        for(int i=0; i<4; i++)
        {
            if (P[i].active == 1)
            {
                i2d.DrawPlayerInfo(P[i], courses);
                
                switch(P[i].position)
                {
                    case 1:
                        if(GameAction==Game_Hunt_Confirm)
                            i2d.DrawIncidentInterface(texIdIN[0]);
                        break;
                    case 12:
                        if(GameAction==Game_Skibo_Confirm)
                            i2d.DrawIncidentInterface(texIdIN[1]);
                        break;
                    case 23:
                        if(GameAction==Game_Tech_Confirm)
                            i2d.DrawIncidentInterface(texIdIN[2]);
                        break;
                    case 34:
                        if(GameAction==Game_South_Confirm)
                            i2d.DrawIncidentInterface(texIdIN[3]);
                        break;
                    default:
                        // Find the index of the course according to its ID, and draw the course information
                        int courseID = P[round].position;
                        int IDindex = FindCourseIndex(courseID);
                        i2d.DrawCourseInterface(courses[IDindex]);
                        break;
                }
            }
        }
        
        // Used to delay one step to 0.5 second
        count++;
        
        FsSwapBuffers();
        FsSleep(25);
    }
    
    // Stop and close the player
    player.Stop(summer);
    player.End();
}

int Game::FindCourseIndex(const int ID) const
{
    if((ID>=2) && (ID<=11))
        return ID - 2;
    else if((ID>=13) && (ID<=22))
        return ID - 3;
    else if((ID>=24) && (ID<=33))
        return ID - 4;
    else
        return ID - 5;
}

void Game::Set2DBack()
{
    int wid,hei;
    FsGetWindowSize(wid,hei);
    
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    
    glViewport(0,0,wid,hei);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, (float)wid-1, (float)hei-1, 0, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glColor4d(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_TEXTURE_2D);
}

void Game::Set3D()
{
    int wid, hei;
    FsGetWindowSize(wid, hei);
    
    glViewport(0, 0, wid, hei);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glColor4d(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(1, 1);
    
    camera.SetUpCameraProjection();
    camera.SetUpCameraTransformation();
    
}

void Game::Set2D()
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

void Game::CareerFair(void)
{
    srand((int)time(NULL));
    
    printf("Here comes the career fair!\n");
    
    int i, n;
    int randomNumber[40];
    int thisJobList[10];
    
    // Shuffing to get a random-ordered array
    for(i=0; i<40; i++)
        randomNumber[i] = i;
    for (i=0; i<40; i++)
    {
        n = rand() % 40;
        SwapInt(randomNumber[i], randomNumber[n]);
    }
    
    // Take out the ten chosen jobs and print out
    for(int i=0; i<10; i++)
    {
        thisJobList[i] = randomNumber[i];
        printf("%s\n", job[thisJobList[i]].GetJobTitle());
        printf("%d\n", job[thisJobList[i]].GetJobID());
    }
    
    for(Player &p : P) // Range-based for (with pass-by-reference)
    {
        printf("Player %d's turn\n", p.getID());
        
        int selected[3];
        for(int &n : selected) // Range-based for (with pass-by-reference)
            n = -1;
        
        for(i=0; i<3; i++)
        {
            int ID;
            
            // Get a non-repeated job ID input
            while(true)
            {
                char str[256];
                fgets(str, 255, stdin);
                ID = atoi(str);
                if(CheckRepeatSelection(selected, ID)==true)
                    printf("Repeated selection!\n");
                else
                {
                    selected[i] = ID;
                    break;
                }
            }
            
            int hasTheJob = 0; // Indicates whether the input job is in the job list
            for(int k : thisJobList) // Range-based for
            {
                if(ID==job[k].GetJobID())
                {
                    hasTheJob = 1;
                    printf("You selected %s\n", job[k].GetJobTitle());
                    if(p.TryFindJob(job[k])==true)
                    {
                        printf("You got the job!\n");
                        return;
                    }
                    else
                        printf("You didn't get it.\n");
                }
            }
            if(hasTheJob==0)
                printf("Invalid input job ID.\n");
        }
        printf("Player %d didn't get a job.\n", p.getID());
    }
}

void Game::NewCareerFair(void)
{
    srand((int)time(NULL));
    
    printf("Here comes the career fair!\n");
    
    int i, n;
    int randomNumber[40];
    Job thisJobs[10];
    
    // Shuffing to get a random-ordered array
    for(i=0; i<40; i++)
        randomNumber[i] = i;
    for (i=0; i<40; i++)
    {
        n = rand() % 40;
        SwapInt(randomNumber[i], randomNumber[n]);
    }
    
    // Take out the ten chosen jobs and print out
    for(int i=0; i<10; i++)
    {
        thisJobs[i] = job[randomNumber[i]];
        printf("%s\n", thisJobs[i].GetJobTitle());
        printf("%d\n", thisJobs[i].GetJobID());
    }
    
    int currPlayer = 0; // Indicates the current player who is choosing jobs
    int numOfChoose = 0;
    
    while(true)
    {
        FsPollDevice();
        
        int key = FsInkey();
        
        if(key==FSKEY_ESC)
            break;
        
        int lb, mb, rb, mx, my;
        int event = FsGetMouseEvent(lb, mb, rb, mx, my);
        
        if(event == FSMOUSEEVENT_LBUTTONDOWN)
        {
            printf("In this if.\n");
            int k = 0;
            for(int j=0;j<5;j++)
            {
                for(int i=0;i<2;i++)
                {
                    if((mx>=8+(20*12+2*180)*i) && (mx<=8+(20*12+2*180)*i+20*12) && (my>=50+66*j) && (my<=66+66*j))
                    {
                        printf("%d %d %d.\n", i, j, k);
                        
                        P[currPlayer].selected[numOfChoose] = thisJobs[k].GetJobID();
                        numOfChoose++;
                        if(numOfChoose>=3)
                        {
                            printf("Number of choose: %d currPlayer: %d\n", numOfChoose, currPlayer);
                            currPlayer++;
//                            printf("Number of choose: %d currPlayer: %d\n", numOfChoose, currPlayer);
//                            if(currPlayer>3)
//                                return;
                            numOfChoose = 0;
                        }
                    }
                    k++;
                }
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        i2d.DrawCareerFair(thisJobs);
        
        for(int i=0; i<4; i++)
        {
            if(P[i].selected[0]==-1)
                i2d.DrawFirstColumnJob(i, " ");
            else
                i2d.DrawFirstColumnJob(i, job[P[i].selected[0]-1].GetJobTitle());
            
            if(P[i].selected[1]==-1)
                i2d.DrawSecondColumnJob(i, " ");
            else
                i2d.DrawSecondColumnJob(i, job[P[i].selected[1]-1].GetJobTitle());
            
            if(P[i].selected[2]==-1)
                i2d.DrawThirdColumnJob(i, " ");
            else
                i2d.DrawThirdColumnJob(i, job[P[i].selected[2]-1].GetJobTitle());
        }
        
        if(currPlayer>3)
            return;
        
        FsSwapBuffers();
        FsSleep(25);
    }
    
    // Reset selected for each player
    for(Player &p : P) // Range-based for (with pass-by-reference)
        p.ResetSelected();
}

void Game::SwapInt(int &a, int &b)
{
    int c;
    c = b;
    b = a;
    a = c;
}

bool Game::CheckRepeatSelection(const int selected[], const int incoming) const
{
    for(int i=0; i<3; i++)
    {
        if(selected[i]==incoming)
            return true;
    }
    return false;
}

void Game::DrawWinner(void)
{
    int terminate = 0;
    
    GLuint Win;
    YsRawPngDecoder win;
    
    char winnerFile[256];
    switch(winner)
    {
        case 0:
            strncpy(winnerFile, "player1win.png", 255);
            break;
        case 1:
            strncpy(winnerFile, "player2win.png", 255);
            printf("Here.\n");
            break;
        case 2:
            strncpy(winnerFile, "player3win.png", 255);
            break;
        case 3:
            strncpy(winnerFile, "player4win.png", 255);
            break;
    }
    base.SetTexture(win, Win, winnerFile);

    while (terminate == 0)
    {
        FsPollDevice();
        
        int key = FsInkey();
        if(key == FSKEY_ESC)
        {
            terminate = 1;
            break;
        }
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        Set2DBack();
        glBindTexture(GL_TEXTURE_2D, Win);
        glBegin(GL_QUADS);
        glTexCoord2d(0.0, 0.0);
        glVertex2d(382, 800);
        glTexCoord2d(1.0, 0.0);
        glVertex2d(898, 800);
        glTexCoord2d(1.0, 1.0);
        glVertex2d(898, 0);
        glTexCoord2d(0.0, 1.0);
        glVertex2d(382, 0);
        glEnd();
        
        FsSwapBuffers();
        FsSleep(20);
    }
}
