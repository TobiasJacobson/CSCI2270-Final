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

vertex DFS(vertex *v, string identifier) // Helper function for findVertex to traverse vertices in DFT order
{
    if(!(v->identifier == identifier)) return *v;
    v->visited = true;

    for(int i = 0; i < v->Edges.size(); i++)
    {
        if(!(v->Edges[i].v->visited == true))
        {
            DFS(v->Edges[i].v, identifier);
        }
    }
}
vertex* Game::findVertex(string identifier) // Allows you to search a specific vertex in verticies
{

    for(int i = 0; i < vertices.size(); i++)
    {
        vertex myV = DFS(&vertices[i], identifier);
    }
    // return myV; ??
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
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Game::loadGame(string txtFile)
{
    // Array containing all of the vertex identifers from the storyboard
    string arr[] = {"0", "1", "2", "3", "1A","1A_1", "1A_2", "1A_11", "1A_11_1", "1A_11_2", "1B", "1C", "1C_1", "1C_11", "1C_11_1", "1C_11_2", "1C_2", "1C_21", "1C_21_1", "1C_21_2", "1C_3", "2A", "2B", "2C", "2D", "3A", "3B", "3B_1", "3B_11", "3B_12", "3B_12_1", "3B_12_2", "3B_12_21", "3B_12_22", "3B_2" };
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
    addEdge("2", "2A");
    addEdge("2", "2B");
    addEdge("2", "2C");
    addEdge("2", "2D");
    // 2A's edges here
    addEdge("2A", "1A_11");
    addEdge("2A", "0");
    // 2B's edges here
    // Has no edges
    // 2C's edges here
    // Has no edges
    // 2D's edges here
    // Has no edges
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
    addEdge("3B_2", "3B_12");
    // 3B_1's edges here
    // Has no edges
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
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Creating new player struct obj. for this gameplay
    //character player;
    player->fear = 0;
    player->roomGarageKey = false;
    player->girlFound = false;
    player->potion = false;
    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::saveNode(string name, vertex *userPosition, character *c) // Will save current user postion and allow for a loadPreviousGame() function call
{
    // To save and distrubt the current location
    // This way we can also add it to the unique output for the user in the txt file
    savedNode newSave;
    newSave.saveName = name;
    newSave.savePos = userPosition;
    newSave.saveCharacter = c;
    saves.push_back(newSave);
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
        newVertex = v->Edges[choice].v;
        return newVertex;
    }
    else
    {
        return NULL;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::loadPreviousGame() // If time allows
{
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    for(int i = 0; i < saves.size(); i++)
    {
        cout << "(" << i << ")" << endl;
        cout << "Name: " << saves[i].saveName << endl;
        cout << "Progress: " << saves[i].savePos->identifier << endl;
        cout << " ############ " << endl;
    }
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::generatePreviousGame(int user)
{
    bool inRange = false;
    int maxSize = saves.size();
    while(inRange == false)
    {
        if(user <= maxSize)
        {
            userPos = saves[user].savePos;
            player = saves[user].saveCharacter;
            inRange = true;
        }
        else
        {
            cout << "Enter a valid number" << endl;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::checkConditions(character *characterPosition)
{
    if(characterPosition->savePos.identifier == "2B")
    {
        characterPosition.roomGarageKey = true;
    }
    if(characterPosition->savePos.identifier == "1C_11")
    {
        characterPosition.girlFound = true;
    }
    if(characterPosition->savePos.identifier = "3B_12")
    {
        characterPosition.potion = true;
    }
    if(characterPosition->savePos.identifier = "2C" || characterPosition->savePos.identifier = "1" || characterPosition->savePos.identifier = "1A" || characterPosition->savePos.identifier = "1A_2" ||
    characterPosition->savePos.identifier = "1C_1" || characterPosition->savePos.identifier = "1C_2" || characterPosition->savePos.identifier = "3B_2" || characterPosition->savePos.identifier = "3B_12_2" ||
    characterPosition->savePos.identifier = "2A" || characterPosition->savePos.identifier = "1A_11" || characterPosition->savePos.identifier = "3B_12_1")
    {
        int addFear = rand()% 20 + 10;
        characterPosition.fear += addFear;
    }
    if(characterPosition->savePos.identifier = "3B_1")
    {

    }


    if(characterPosition->savePos.identifier = "1B" || characterPosition->savePos.identifier = "2D" || characterPosition->savePos.identifier = "1A_1" || characterPosition->savePos.identifier = "1A_11_1" ||
    characterPosition->savePos.identifier = "1C_3" || characterPosition->savePos.identifier = "1C_11_1" || characterPosition->savePos.identifier = "1C_21_2" || characterPosition->savePos.identifier = "3A" ||
    characterPosition->savePos.identifier = "3B_11" || characterPosition->savePos.identifier = "3B_12_21" || characterPosition->savePos.identifier = "3B_12_22")
    {
        if(characterPosition->savePos.identifier = "2D" && characterPosition.SearchTimes > 2)
        {
            showChapter(currNode);
            break;
        }
    }


}







///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
