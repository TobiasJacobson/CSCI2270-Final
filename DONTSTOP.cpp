#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>

#include "Game.hpp"

using namespace std;

// TODO:
// Store player position using currNode to txt file
// Return after 3B_2 to 3B


void introDisplay() // Main menu for start of game
{
    cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
    cout << "|                                                                                                           |" << endl;
    cout << "|                ██████╗  ██████╗ ███╗   ██╗████████╗    ███████╗████████╗ ██████╗ ██████╗                  |" << endl;
    cout << "|                ██╔══██╗██╔═══██╗████╗  ██║╚══██╔══╝    ██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗                 |" << endl;
    cout << "|                ██║  ██║██║   ██║██╔██╗ ██║   ██║       ███████╗   ██║   ██║   ██║██████╔╝                 |" << endl;
    cout << "|                ██║  ██║██║   ██║██║╚██╗██║   ██║       ╚════██║   ██║   ██║   ██║██╔═══╝                  |" << endl;
    cout << "|                ██████╔╝╚██████╔╝██║ ╚████║   ██║       ███████║   ██║   ╚██████╔╝██║                      |" << endl;
    cout << "|                ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝   ╚═╝       ╚══════╝   ╚═╝    ╚═════╝ ╚═╝                      |" << endl;
    cout << "|                                     ___________                    _______________                        |" << endl;
    cout << "|                                    |  __   __  |                  |- ___________ -|                       |" << endl;
    cout << "|                                    | |  | |  | |                  | |  _ _ _ _  | |                       |" << endl;
    cout << "|                                    | |  | |  | |                  | | | | | | | | |                       |" << endl;
    cout << "|                                    | |  | |  | |                  | | |-+-+-+-| | |                       |" << endl;
    cout << "|      (1) New Game                  | |__| |__| |                  | | |_|_|_|_| | |                       |" << endl;
    cout << "|      (2) Load Previous Game        |  __   __()|                  | |    ___    | |                       |" << endl;
    cout << "|      (3) Credits                   | |  | |  | |                  | |   [___] ()| |                       |" << endl;
    cout << "|      (4) Quit Game                 | |  | |  | |                  | |         ||| |                       |" << endl;
    cout << "|                                    | |  | |  | |                  | |         ()| |                       |" << endl;
    cout << "|                                    | |  | |  | |                  | |           | |                       |" << endl;
    cout << "|                                    | |__| |__| |                  | |           | |                       |" << endl;
    cout << "|                                    |___________|                  |_|___________|_|                       |" << endl;
    cout << " ----------------------------------------------------------------------------------------------------------- " << endl;
}

void endGameDisplay() // End of game display
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
}
void gameOverOutro()
{
    cout << "   ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗     " << endl;
    cout << "  ██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗    " << endl;
    cout << "  ██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝    " << endl;
    cout << "  ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗    " << endl;
    cout << "  ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║    " << endl;
    cout << "   ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝    " << endl;
}
void gameWonOutro()
{
    cout << "██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗███████╗ ██████╗ █████╗ ██████╗ ███████╗██████╗ ██╗" << endl;
    cout << "╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝██╔════╝██╔════╝██╔══██╗██╔══██╗██╔════╝██╔══██╗██║" << endl;
    cout << " ╚████╔╝ ██║   ██║██║   ██║    █████╗  ███████╗██║     ███████║██████╔╝█████╗  ██║  ██║██║" << endl;
    cout << "  ╚██╔╝  ██║   ██║██║   ██║    ██╔══╝  ╚════██║██║     ██╔══██║██╔═══╝ ██╔══╝  ██║  ██║╚═╝" << endl;
    cout << "   ██║   ╚██████╔╝╚██████╔╝    ███████╗███████║╚██████╗██║  ██║██║     ███████╗██████╔╝██╗" << endl;
    cout << "   ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═════╝ ╚═╝" << endl;
}
void newGame() // Intro to a new game
{
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Welcome to -- Don't Stop -- " << endl;
    cout << "The rules are quite simple really" << endl;
    cout << "Follow the storyline and when given a choice, choose the option you'd like to explore" << endl;
    cout << "Each choice leads you down a different road -- each with a different end" << endl;
    cout << "-Play several times to get various endings-" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
}

void inGameMenu() // In game menu to if 9 is pressed
{
    cout << "(1) Back to game" << endl;
    cout << "(2) Save Game" << endl;
    cout << "(3) Quit to main menu" << endl;
}


void options() // Not sure what this will do but menu's always have options
{
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Will implement if time allows" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;

}

void credits() // Credits to developers (Us)
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

int main(int argc, char* argv[]) // Main for entire game
{
    // Struct declaration
    Game g;
    // Variable Declarations
    string menuInput;
    string gameInput;
    string game_Menu_Input;
    int userInput;
    string saveProgress;
    string newGameInput;
    bool loadSavedGame = false; //if a saved game is being used
    string storyTxt = argv[1];
    // Game intro displayed
    introDisplay();
    while(menuInput != "4") // While for main menu
    {
        if(g.isGameOver)
        {
            gameOverOutro();
            break;
        }
        if(g.isGameWon)
        {
            gameWonOutro();
            break;
        }
        if(game_Menu_Input == "3")
        {
            // Game intro displayed && variables reset
            menuInput = "";
            gameInput = "";
            game_Menu_Input = "";
            userInput = -1;
            introDisplay();
            // getline(cin, menuInput);
        }

        // User input taken
        if(loadSavedGame) //if loading from a txt file
        {

            //g.player =
            //g.userPos =
        }
        else //
        {
            getline(cin, menuInput);
        }


        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // START GAME
        if(menuInput == "1")
        {
            if(g.loadGame(storyTxt)) // Load chapters from Storyline.txt and adds all edges
            {
                cout << "Game Loaded..." << endl;
                cout << endl;
                if(loadSavedGame) //if loading from a txt file
                {

                    //g.player =
                    //g.userPos =
                }
                else //if freshgame
                {
                    g.player = g.characterStart();
                    g.userPos = g.startGame();
                }
                newGame(); //Intro text

                //Acutally runs game
                while(game_Menu_Input != "3") // While for in game inputs
                {
                    // Taking user input after chapter
                    g.showChapter(g.userPos); // Shows chapter of current node
                    getline(cin, gameInput); // Taking user input based on chapter end
                    if(gameInput == "9") // Opens in game menu if entered while in game
                    {
                        inGameMenu(); // Display in game menu
                        getline(cin, game_Menu_Input); // taking user input
                        if(game_Menu_Input == "1")
                        {
                            // Does nothing so returns back to game and current node
                        }
                        //Save progress to txt file
                        else if(game_Menu_Input == "2")
                        {
                            g.saveProgress();
                        }
                        // Quits to main manu
                        else if(game_Menu_Input == "3")
                        {
                            break;
                        }
                    }
                    else // If not in game menu, takes user input and goes to chosen node
                    {
                        // Check to see if input is in rnge
                        userInput = stoi(gameInput);
                        int maxSize = g.userPos->Edges.size();
                        if(0 <= userInput && userInput <= maxSize) // Checks to make sure choice is within limits of the current node
                        {
                            // Taking user input and change the user position to chosen node path
                            g.userPos = g.makeChoice(userInput, g.userPos);
                        }
                        else
                        {
                            cout << "Invalid" << endl; // Invalid input and displays chapter again
                        }
                    }
                    g.checkConditions(g.player);
                    if(g.isGameOver)
                    {
                        break;
                    }
                    if(g.isGameWon)
                    {
                        break;
                    }
                }
            }
            // New game not loaded succesfully
            else
            {
                cout << "Error: Failed To Load Game" << endl;
                break;
            }
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //LOAD SAVED GAME
        else if(menuInput == "2")
        {
            cout << "Enter the .txt file that contains your info" << endl;
            string saveName;
            getline(cin, saveName);
            ifstream saveFile;
            saveFile.open(saveName);

            string iden; //identifier
            getline(saveFile, iden);
            //string iden = getlin(saveFile, iden);
            g.userPos = g.findVertex(iden);
            cout << "userPos done" << endl;

            getline(saveFile, iden);
            //cout << g.player->searchTimes << endl;
            g.player->searchTimes = stoi(iden);
            getline(saveFile, iden);
            g.player->fear = stoi(iden);
            getline(saveFile, iden);
            g.player->roomGarageKey = stoi(iden);
            getline(saveFile, iden);
            g.player->girlFound = stoi(iden);
            getline(saveFile, iden);
            g.player->potion = stoi(iden);
            //count++;
            cout << "Character loaded" << endl;
            loadSavedGame = true;
            menuInput = "1";
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // SHOW CREDITS
        else if(menuInput == "3")
        {
            credits();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // EXIT GAME
        else if(menuInput == "4")
        {
            endGameDisplay();
            // break;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else
        {
            cout << "INVALID INPUT" << endl; // If no valid option
        }
    }
}
