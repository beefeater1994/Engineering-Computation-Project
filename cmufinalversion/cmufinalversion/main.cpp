#include "Menu.h"
#include "Game_class.h"

#include "fssimplewindow.h"

int main()
{
    FsOpenWindow(0, 0, 1280, 800, 1);
    
    int terminate=0;
    
    while(terminate==0)
    {
        Menu menu;
        menu.MainMenu();
        // If certain key is pressed, break out the MainMenu() function.
        
        // If the "Start Game" button is pressed, start the game.
        if(menu.GetSelection()==1)
        {
            Game game;
            game.RunGame();
            
            if(game.winner!=-1)
                game.DrawWinner();
            
            terminate = 1;
            break;
        }
        else if(menu.GetSelection()==2)
            menu.Instruction();
        else if(menu.GetSelection()==3)
            menu.About();
        else
            break;
    }
    
    return 0;
}
