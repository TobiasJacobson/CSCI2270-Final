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
    cout << "Press 9 to open in game menu." << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << "You wake with a start. Surveying your surroundings you see you are laying on the dirty floor of a small room lit only buy a torch. You are completely unaware of how you’d gotten here.  Raising your hand you feel a gash on your head and realize you have a thick, decaying broken noose bound tightly around your neck. You look around the room to figure out where you are. ";
}

void inGameMenu() // In game menu to if 9 is pressed
{
    cout << "(1) Back to game" << endl;
    cout << "(2) Save Game" << endl;
    cout << "(3) Quit to main menu" << endl;
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MAIN
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    // Loading saved gameplay

    // Game intro displayed
    introDisplay();
    while(menuInput != "4") // While for main menu
    {
        if(g.isGameOver)
        {
            g.showChapter(g.userPos);
            gameOverOutro();
            break;
        }
        if(g.isGameWon)
        {
            g.showChapter(g.userPos);
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
        }
        // User input taken
        if(loadSavedGame) //if loading from a txt file
        {

        }
        else
        {
            getline(cin, menuInput);
        }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // START GAME
        if(menuInput == "1") // Option 1 to start a new game
        {
            if(g.loadGame(storyTxt)) // New game loaded succesfully
            {
                cout << "Game Loaded..." << endl;
                cout << endl;
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // LOADING GAME FROM TXT FILE
                if(loadSavedGame) //if loading from a txt file
                {
                    cout << "Enter the .txt file that contains your info" << endl;
                    string saveName;
                    getline(cin, saveName);
                    ifstream saveFile;
                    saveFile.open(saveName);

                    string iden = ""; //identifier
                    string textLine = "";
                    string userPosition;
                    int searchNum;
                    int fear;
                    bool garage;
                    bool girl;
                    bool pot;
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    // Runs until reaches last file line when no next line to get
                    while(getline(saveFile, textLine)) // Runs until reaches last file line when no next line to get
                    {
                        userPosition = textLine;
                        cout << "User Position: " << userPosition << endl;
                        /////////////
                        getline(saveFile, iden);
                        searchNum = stoi(iden);
                        cout << "Times Searched: " << iden << endl;
                        ///////////
                        getline(saveFile, iden);
                        fear = stoi(iden);
                        cout << "Fear: " << iden << endl;
                        //////////
                        getline(saveFile, iden);
                        if(iden == "0")
                        {
                            garage = false;
                        }
                        else
                        {
                            garage = true;
                        }
                        cout << "GarageKey: " << garage << endl;
                        ////////
                        getline(saveFile, iden);
                        if(iden == "0")
                        {
                            girl = false;
                        }
                        else
                        {
                            girl = true;
                        }
                        cout << "GirlFound: " << girl << endl;
                        ////////////
                        getline(saveFile, iden);
                        if(iden == "0")
                        {
                            pot = false;
                        }
                        else
                        {
                            pot = true;
                        }
                        cout << "Potion: " << pot << endl;
                    }

                    cout << "Character loaded succesfully\n" << endl;
                    g.player = g.characterReboot(searchNum, fear, garage, girl, pot);
                    g.userPos = g.findVertex(userPosition);
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // NEW GAME
                else //If brand new game
                {
                    g.player = g.characterStart();
                    g.userPos = g.startGame();
                    newGame();
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
                // ACTUALLY RUNS THROUGH THE GAME
                while(game_Menu_Input != "3") // While for in game inputs
                {
                    if(g.userPos->identifier == "1C")
                    {
                        if(g.player->roomGarageKey)
                        {
                            cout << "You descend the staircase hoping to find a way out as quickly as possible. The lower floor is just as dark with the only source of light being the moon. In the corner you see the vague outline of a door with a large padlock that could be the garage(1). Also you see an archway leading to what could be the family room(2). Most enticing of all is the front door which leads straight to the front yard(3)." << endl;
                            getline(cin, gameInput); // Taking user input based on chapter end
                        }
                        else
                        {
                            cout << "You descend the staircase hoping to find a way out as quickly as possible. The lower floor is just as dark with the only source of light being the moon. In the corner you see the vague outline of a door with a large padlock that could be the garage but you have no key so you cannot enter. Also you see an archway leading to what could be the family room(2). Most enticing of all is the front door which leads straight to the front yard(3)." << endl;
                            getline(cin, gameInput); // Taking user input based on chapter end
                            if(gameInput == "1")
                            {
                                gameInput = "5";
                            }
                            else
                            {

                            }
                        }
                    }
                    else
                    {
                        // Taking user input after chapter
                        g.showChapter(g.userPos); // Shows chapter of current node
                        getline(cin, gameInput); // Taking user input based on chapter end
                    }
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    // OPENS IN GAME MENU
                    if(gameInput == "9") // Opens in game menu if entered while in game
                    {
                        inGameMenu(); // Display in game menu
                        getline(cin, game_Menu_Input); // taking user input
                        if(game_Menu_Input == "1")
                        {
                            // Does nothing so returns back to game and current node
                        }
                        else if(game_Menu_Input == "2")
                        {
                            g.saveProgress();
                        }
                        else if(game_Menu_Input == "3")
                        {
                            break; // Quits to main manu
                        }
                        else if(game_Menu_Input == "+")
                        {
                            g.showStats(g.player);
                        }
                    }
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    // If not in game menu, takes user input and goes to chosen node
                    else
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
            else // New game not loaded succesfully
            {
                cout << "Error: Failed To Load Game" << endl;
                break;
            }
        }
        else if(menuInput == "2") // Will load previous save
        {

            loadSavedGame = true;
            menuInput = "1";
        }
        else if(menuInput == "3") // Shows credits
        {
            credits();
        }
        else if(menuInput == "4") // Exits game and quits
        {
            endGameDisplay();
            // break;
        }
        else
        {
            cout << "INVALID INPUT" << endl; // If no valid option
        }
    }

}
