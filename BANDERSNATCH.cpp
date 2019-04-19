#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>

#include "Game.hpp"

using namespace std;

// (1) New Game from top of BST
// (2) Load Previous Game from previsouly saved tree nodes
// (3) Options such as color? sounds?
// (4) Credits for us and anything we want to say
// (5) Quit Game and unsave

// Name Ideas:
// Everdoom
//

void introDisplay()
{
    cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
    cout << "|                                                                                                           |" << endl;
    cout << "|                                                                                                           |" << endl;
    cout << "|                         ______ _____ _   _ _____   _____ _____ ___________                                |" << endl;
    cout << "|                         |  _  \\  _  | \\ | |_   _| /  ___|_   _|  _  | ___ \\                               |" << endl;
    cout << "|                 _       | | | | | | |  \\| | | |   \\ `--.  | | | | | | |_/ /       _                       |" << endl;
    cout << "|                ___      | | | | | | | . ` | | |    `--. \\ | | | | | |  __/       ___                      |" << endl;
    cout << "|                 _       | |/ /\\ \\_/ / |\\  | | |   /\\__/ / | | \\ \\_/ / |           _                       |" << endl;
    cout << "|                         |___/  \\___/\\_| \\_/ \\_/   \\____/  \\_/  \\___/\\_|                                   |" << endl;
    cout << "|                         ___________________________________________________                               |" << endl;
    cout << "|                                                                                                           |" << endl;
    cout << "|                                   ___________                    _______________                          |" << endl;
    cout << "|                                  |  __   __  |                  |- ___________ -|                         |" << endl;
    cout << "|                                  | |  | |  | |                  | |  _ _ _ _  | |                         |" << endl;
    cout << "|      (1) New Game                | |  | |  | |                  | | | | | | | | |                         |" << endl;
    cout << "|      (2) Load Previous Game      | |  | |  | |                  | | |-+-+-+-| | |                         |" << endl;
    cout << "|      (3) Options                 | |__| |__| |                  | | |_|_|_|_| | |                         |" << endl;
    cout << "|      (4) Credits                 |  __   __()|                  | |    ___    | |                         |" << endl;
    cout << "|      (5) Quit Game               | |  | |  | |                  | |   [___] ()| |                         |" << endl;
    cout << "|                                  | |  | |  | |                  | |         ||| |                         |" << endl;
    cout << "|                                  | |  | |  | |                  | |         ()| |                         |" << endl;
    cout << "|                                  | |  | |  | |                  | |           | |                         |" << endl;
    cout << "|                                  | |__| |__| |                  | |           | |                         |" << endl;
    cout << "|                                  |___________|                  |_|___________|_|                         |" << endl;
    cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
}

void newGame()
{
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Welcome to Bandersnatch -- The rules are quite simple really" << endl;
    cout << "Follow the storyline and when given a choice, choose the option you'd like to explore" << endl;
    cout << "Each choice leads you down a different road -- each with a different end" << endl;
    cout << "-Play several times to get various endings-" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    // call game function here!
}

// void loadPreviousGame() // If time allows
// {
//     cout << "------------------------------------------------------------------------------------------------------------" << endl;
//     cout << endl;
//     // call implementation of saved nodes
//     cout << endl;
//     cout << "------------------------------------------------------------------------------------------------------------" << endl;
//
// }

void options()
{
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;

}

void credits()
{
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Credits -- " << endl;
    cout << "Programmers: Nate Christy, Tobias Jacobson, James Burke" << endl;
    cout << "This was a lot of fun to make and we hope those who play it don't despise it" << endl;
    cout << "Granted some parts were difficult to figure out...." << endl;
    cout << "Anyways, happy trails my friend. See you in another life" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
}

int main(int argc, char* argv[])
{
    Game g;
    string menuInput;
    introDisplay();

    string storyTxt = argv[1];
    while(menuInput != "5")
    {
        getline(cin, menuInput);
        if(menuInput == "1")
        {
            newGame();
            g.loadGame(storyTxt);
        }
        if(menuInput == "2")
        {
            //loadPreviousGame();
        }
        if(menuInput == "3")
        {
            options();
        }
        if(menuInput == "4")
        {
            credits();
        }
        if(menuInput == "5")
        {
            cout << endl;
            cout << "See you in another life mate" << endl;
            cout << endl;
            cout << " ██████╗  ██████╗  ██████╗ ██████╗ ██████╗ ██╗   ██╗███████╗" << endl;
            cout << "██╔════╝ ██╔═══██╗██╔═══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝██╔════╝" << endl;
            cout << "██║  ███╗██║   ██║██║   ██║██║  ██║██████╔╝ ╚████╔╝ █████╗" << endl;
            cout << "██║   ██║██║   ██║██║   ██║██║  ██║██╔══██╗  ╚██╔╝  ██╔══╝" << endl;
            cout << "╚██████╔╝╚██████╔╝╚██████╔╝██████╔╝██████╔╝   ██║   ███████╗" << endl;
            cout << " ╚═════╝  ╚═════╝  ╚═════╝ ╚═════╝ ╚═════╝    ╚═╝   ╚══════╝" << endl;
            break;
        }
    }

}
