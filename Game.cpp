#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <list>
#include <queue>
#include <sstream>

#include "Game.hpp"

using namespace std;

// NOTES
// cpp file intended to be for the bulk of the game as to remove it from the clutter of the driver BANDERSNATCH.cpp


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Graph::Graph()
// {
//     // No dynamic memory - so not needed
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Graph::~Graph()
// {
//     // No dynamic memory - so not needed
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::addVertex(string identifier, string storyPart) // Function to add a newVertex to verticies with the given inputs
{
    vertex newVertex;
    newVertex.visited = false;
    newVertex.identifier = identifier;
    newVertex.chapter = storyPart;
    vertices.push_back(newVertex);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::addEdge(string identifier1, string identifier2) // Adds an edge between the identifiers of the two given vertices
{
    for(int i = 0; i < vertices.size(); i++)
    {
         if(vertices[i].identifier == identifier1)
         {
             for(int j = 0; j < vertices.size(); j++)
             {
                 if(vertices[j].identifier == identifier2 && i != j) // i != j bc then we'd pus_back not within the limits of the graph size
                 {
                    Edge aV;
                    aV.v = &vertices[j];
                    vertices[i].Edges.push_back(aV);
                 }
             }
         }
     }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::displayEdges() // Displays each vertex in vertices and all of it edges following --> seperated by ***
{
    for(int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i].identifier << "-->"; // Follows the vertex
        for(int j = 0; j < vertices[i].Edges.size(); j++)
        {
            cout << vertices[i].Edges[j].v -> identifier;
            if(j != vertices[i].Edges.size() - 1)
            {
                cout << "***"; // Seperates the edges
            }
        }
        cout << endl;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::printDFT() // Will print all vertices in a Depth First Traversal order
{
    setAllVerticesUnvisited();
    for(int i = 0; i < vertices.size(); i++)
    {
        DFT_traversal(&vertices[i]);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::setAllVerticesUnvisited() // Will set all verticies as unvisited
{
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i].visited = false;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vertex *Game::findVertex(string identifier) // Allows you to search a specific vertex in verticies
{
    int pos = -1;
    string arr[] = {"0", "1", "2", "3", "1A","1A_1", "1A_2", "1A_11", "1A_11_1", "1A_11_2", "1B", "1C", "1C_1", "1C_11", "1C_11_1", "1C_11_2", "1C_2", "1C_21", "1C_21_1", "1C_21_2", "1C_3", "3A", "3B", "3B_1", "3B_11", "3B_12", "3B_12_1", "3B_12_2", "3B_12_21", "3B_12_22", "3B_2" }; // 31
    for(int i = 0; i < 31; i++)
    {
        if(arr[i] == identifier)
        {
            pos = i;
        }
    }

    return &vertices[pos];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::DFT_traversal(vertex *v) // Traveses vertices in a DFT order
{
    if(!v->visited) cout << v->identifier << endl;
    v->visited = true;
    for(int i = 0; i < v->Edges.size(); i++)
    {
        if(!(v->Edges[i].v->visited == true))
        {
            DFT_traversal(v->Edges[i].v);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::saveProgress()
{
    // Need some way to store the current vertex and keep track of where the user is.
    // will also allow to load a previous game
    cout << "Enter a name for the save file" << endl;
    string fileN; //file's name
    getline(cin, fileN);
    fileN = fileN + ".txt"; //make it a txt file
    ofstream saveState;
    saveState.open(fileN); //create new file
    saveState << userPos->identifier << "\n";
    saveState << player->searchTimes << "\n";
    saveState << player->fear << "\n";
    saveState << player->roomGarageKey << "\n";
    saveState << player->girlFound << "\n";
    saveState << player->potion << "\n";
    saveState.close();
    cout << "Save file created" << endl;
    return;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Game::loadGame(string txtFile)
{
    // Array containing all of the vertex identifers from the storyboard
    string arr[] = {"0", "1", "2", "3", "1A","1A_1", "1A_2", "1A_11", "1A_11_1", "1A_11_2", "1B", "1C", "1C_1", "1C_11", "1C_11_1", "1C_11_2", "1C_2", "1C_21", "1C_21_1", "1C_21_2", "1C_3", "3A", "3B", "3B_1", "3B_11", "3B_12", "3B_12_1", "3B_12_2", "3B_12_21", "3B_12_22", "3B_2" }; // 31
    // Opens given txt file
    ifstream inFile;
    inFile.open(txtFile);
    if(!inFile) // If unable to open, displays error and exits program
    {
       cout << "Error: Could Not Open txt File" << endl;
       return false;
    }
    // Declaration of needed variables to read from the txt file, line by line
    string identifier;
    string line;
    int i = 0;
    // Reads txt file line by line, creating a new vertex for each line read
    while(getline(inFile,line))
    {
        // ADDING VERTICIES HERE
        identifier = arr[i];
        addVertex(identifier, line );
        i++;
    }
    ////   EDGES ADDED HERE   /////////////////////////////////////////////////////////////////////////////////////////////
    // 0's edges here
    addEdge("0", "1");
    addEdge("0", "2");
    addEdge("0", "3");
    // 1's edges here
    addEdge("1", "1A");
    addEdge("1", "1B");
    addEdge("1", "1C");
    // 1A's edges here
    addEdge("1A", "1A_1");;
    addEdge("1A", "1A_2");
    // 1A_1's edges here
    addEdge("1A_1", "1A_11");
    // 1A_2's edges here
    addEdge("1A_2", "1A_11");
    // 1A_11's edges here
    addEdge("1A_11", "1A_11_1");
    addEdge("1A_11", "1A_11_2");
    // 1B's edges here
    // Has no edges
    // 1C's edges here
    addEdge("1C", "1C_1");
    addEdge("1C", "1C_2");
    addEdge("1C", "1C_3");
    // 1C_1's edges here
    addEdge("1C_1", "1C_11");
    addEdge("1C_1", "3B_1");
    // 1C_11's edges here
    addEdge("1C_11", "1C_11_1");
    addEdge("1C_11", "1C_11_2");
    // iC_11_2's edges here
    addEdge("1C_11_2", "1C_21_1");
    // 1C_2's edges here
    addEdge("1C_2", "1C_21");
    // 1C_21's edges here
    addEdge("1C_21", "1C_21_1");
    addEdge("1C_21", "1C_21_2");
    // 1C_3's edges here
    // Has no edges
    // 2's edges here
    addEdge("2", "0");
    addEdge("2", "1A_11");
    // 3's edges here
    addEdge("3", "3A");
    addEdge("3", "3B");
    // 3A's edges here
    // 3A has no edges
    // 3B's edges here
    addEdge("3B", "3B_1");
    addEdge("3B", "3B_2");
    // 3B_1's edges here
    addEdge("3B_1", "3B_11");
    addEdge("3B_1", "3B_12");
    // 3B_2's edges here
    addEdge("3B_2", "3");
    // 3B_11's edges here
    // Has no edges
    // 3B_12's edges here
    addEdge("3B_12", "3B_12_1");
    addEdge("3B_12", "3B_12_2");
    // 3B_12_1's edges here
    addEdge("3B_12_1", "1C_21");
    // 3B_12_2's edges here
    addEdge("3B_12_2", "3B_12_21");
    addEdge("3B_12_2", "3B_12_22");
    // 3B_2's edges here
    addEdge("3B_2", "3");
    /////////////////////////////////////////////////////////////////////////////////
    // Creating new player struct obj. for this gameplay
    //character player;
    isGameOver = false;
    isGameWon = false;
    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vertex *Game::startGame() // Returns the first user postion of vertices[0]
{
    return &vertices[0];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::showChapter(vertex *curr) // Displays the chapter/story part/story section of the given vertex node
{
    cout << curr->chapter << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vertex *Game::makeChoice(int choice, vertex *v) // Function allowing user to make a choice based in the chapter of the most recent node
{
    // First a simple call to make sure the choice is within the vertex nodes bounderies
    int maxSize = v->Edges.size();
    if(0 <= choice && choice <= maxSize)
    {
        vertex *newVertex;
        newVertex = v->Edges[choice-1].v;
        return newVertex;
    }
    else
    {
        return NULL;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Game::riddle()
{
    int riddleNum = rand()% 2 + 1; // 1-3 int
    string ans; //user input

    if(riddleNum == 1)
    {
        cout << "Poor people have it. Rich people need it. If you eat it you die. What is it?" << endl;
        getline(cin, ans);
        if(ans == "Nothing" || ans == "nothing") return true;
        return false;
    }
    if(riddleNum == 2)
    {
        cout << "There are 12 white socks and 12 black socks in a drawer in a completely dark room. How many socks must you pull out to get a pair?" << endl;
        getline(cin, ans);
        if(ans == "3" || ans == "three" || ans == "Three") return true;
        return false;
    }
    if(riddleNum == 3)
    {
        cout << "I stay in the corner yet I travel around the world. What am I?" << endl;
        getline(cin, ans);
        if(ans == "stamp" || ans == "Stamp" || ans == "A stamp" || ans == "a stamp") return true;
        return false;
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Game::checkConditions(character *characterPosition)
{
    int riddleCorrect = false;
    //Search too many times
    if(characterPosition->searchTimes >= 2) //Too many searches
    {
        cout << "You peer around again, desperately hoping to find something that help you get out safely. You are so busy studying the contents of the boxes you barely notice the shadow of the figure until its fingers close over your neck and crush. -See you in another life-" << endl;
        isGameOver = true;
    }
    if(userPos->identifier == "2")
    {
        characterPosition->searchTimes++;
        int randGen = rand()%9 + 1;
        if(randGen > 0 && randGen < 4) // Finding hatch
        {
            cout << "You found a hidden hatch!" << endl;
            userPos = userPos->Edges[1].v;
            cout << endl;
        }
        else if(randGen > 3 && randGen < 7) // Garage Key
        {
            cout << "You decide it’s best to prepare yourself and gear up in the event that who or whatever is in the house decides to come back. You begin to scavenge the room for anything that could be of use. On the shelves behind you are see some dusty plates and mugs which look like they haven’t been moved in years. Higher up you notice a small ragged sack tucked into the corner. You pull it down and begin loosening the knot on it, but to your surprise the knot breaks as you pick at it. Peering into the bag, unable to see in the dim light, you hesitantly stick your hand in and pull out a rusty key. Hoping it could be useful you put the key in your back pocket. You found a key! The key has been added to your inventory. Continue exploring to find what the key opens." << endl;
            characterPosition->roomGarageKey = true;
            userPos = userPos->Edges[0].v;
            cout << endl;
        }
        else if(randGen > 7 && randGen <= 10) // Severed head
        {
            int addFear = rand()% 20 + 10;
            characterPosition->fear += addFear;
            cout << "You decide it’s best to prepare yourself and gear up in the event that who or whatever is in the house decides to come back. You begin to scavenge the room for anything that could be of use. As you look around the room you notice a small box in the dark corner. Walking over to the box you are hit with a sudden putrid smell of decay. Weary of what it may contain, you decide to bring it the light in the center of the room. Yet as you pick it up, grasping the underside, your hands are suddenly covered in a warm, thick substance. As you lift it higher you feel the bottom begin to sink down. You realize what you are holding is a human head. You scream and throw the box into the corner. You take deep breaths to calm yourself down but you feel permanently shaken." << endl;
            userPos = userPos->Edges[0].v;
            cout << endl;
        }
        else
        {
            cout << "Something went wrong" << endl;
        }
    }
    //girlFound
    if(userPos->identifier == "1C_11")
    {
        characterPosition->girlFound = true;
    }
    //Shadow man and riddle
     if(userPos->identifier == "3B_1") //Shadow man
    {
        if(riddle())
        {
            userPos = userPos->Edges[1].v;
        }
        else
        {
            userPos = userPos->Edges[0].v;
        }
    }
    //potion
    if(userPos->identifier == "3B_12")
    {
        characterPosition->potion = true;
    }
    //Fear increases
    if(userPos->identifier == "1" || userPos->identifier == "1A" || userPos->identifier == "1A_2" ||
    userPos->identifier == "1C_1" || userPos->identifier == "1C_2" || userPos->identifier == "3B_2" || userPos->identifier == "3B_12_2"
    || userPos->identifier == "1A_11" || userPos->identifier == "3B_12_1")
    {
        int addFear = rand()% 20 + 10;
        characterPosition->fear += addFear;
    }
    //Die from fear
    if(characterPosition->fear >= 100)
    {
        cout << "Knees shaking, you collapse to the ground. You can't take the stress anymore! You black out and never wake up." << endl;
        isGameOver = true;
    }
    //Nodes where you die
    if(userPos->identifier == "1B" || userPos->identifier == "1A_1" || userPos->identifier == "1A_11_1" ||
    userPos->identifier == "1C_3" || userPos->identifier == "1C_11_1" || userPos->identifier == "1C_21_2" || userPos->identifier == "3A" ||
    userPos->identifier == "3B_11" || userPos->identifier == "3B_12_21" || userPos->identifier == "3B_12_22")
    {
        cout << "In the spur of the moment you made a decision. A decision you thought would keep you alive. Oh how wrong you were, because before you know it you everything goes dark and the last thing you are the creatures glowing red eyes." << endl;
        isGameOver = true;
    }
    if(userPos->identifier == "3B_2")
    {
      userPos = userPos->Edges[0].v;
    }
    if(userPos->identifier == "1A_11_2")
    {
        isGameWon = true;
    }
    if(userPos->identifier == "1C_21_1")
    {
        if(characterPosition->girlFound == true)
        {
            isGameWon = true;
        }
        else
        {
            isGameOver = true;
        }
    }
    if(userPos->identifier == "1C_21_1")
    {
        if(characterPosition->girlFound == true)
        {
            isGameWon = true;
        }
        else
        {
            isGameOver = true;
        }
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

character *Game::characterStart()
{
    character userStart;
    userStart.searchTimes = 0;
    userStart.fear = 0; // This will effect players ability to make certain choices (ex. Broken leg, can't climb)
    userStart.roomGarageKey = false; // A key that can be found in the first room
    userStart.girlFound = false; // Bool to represent if the girl is found
    userStart.potion = false; // Bool to represent if potion is found
    userPlayer.push_back(userStart);
    return &userPlayer[0];
}
character *Game::characterReboot(int search, int fear, bool key, bool girl, bool pot)
{
    character userStart;
    userStart.searchTimes = 0;
    userStart.fear = 0; // This will effect players ability to make certain choices (ex. Broken leg, can't climb)
    userStart.roomGarageKey = false; // A key that can be found in the first room
    userStart.girlFound = false; // Bool to represent if the girl is found
    userStart.potion = false; // Bool to represent if potion is found
    userPlayer.push_back(userStart);
    return &userPlayer[0];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
