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

// NOTES FROM GUPTA IN OFFICE HOURS --------------------------------------------
// cpp file intended to be for the bulk of the game as to remove it from the clutter of the intital stages
//  Directed graph, allows user to back track after dying
//  txt of final unique path
//  cyclical

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Graph::Graph()
// {
//     // No dynamic memory - so not needed
// }
// Graph::~Graph()
// {
//     // No dynamic memory - so not needed
// }
void Game::addVertex(string identifier, string storyPart)
{
    vertex newVertex;
    newVertex.visited = false;
    newVertex.identifier = identifier;
    newVertex.chapter = storyPart;
    vertices.push_back(newVertex);
}
void Game::addEdge(string identifier1, string identifier2)
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
void Game::displayEdges()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i].identifier << "-->";
        for(int j = 0; j < vertices[i].Edges.size(); j++)
        {
            cout << vertices[i].Edges[j].v -> identifier;
            if(j != vertices[i].Edges.size() - 1)
            {
                cout << "***";
            }
        }
        cout << endl;
    }
}
void Game::printDFT()
{
    setAllVerticesUnvisited();
    for(int i = 0; i < vertices.size(); i++)
    {
        DFT_traversal(&vertices[i]);
    }
}
void Game::setAllVerticesUnvisited()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i].visited = false;
    }
}
vertex DFS(vertex *v, string identifier){
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
vertex* Game::findVertex(string identifier){

    for(int i = 0; i < vertices.size(); i++)
    {
        vertex myV = DFS(&vertices[i], identifier);
    }
}
void Game::DFT_traversal(vertex *v)
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Game::saveProgress()
{
    // Need some way to store the current vertex and keep track of where the user is.
}
bool Game::loadGame(string txtFile)
{
    string arr[] = {"0", "1", "2", "3", "1A","1A_1", "1A_2", "1A_11", "1A_11_1", "1A_11_2", "1B", "1C", "1C_1", "1C_11", "1C_11_1", "1C_11_2", "1C_2", "1C_21", "1C_21_1", "1C_21_2", "1C_3", "2A", "2B", "2C", "2D", "3A", "3B", "3B_1", "3B_11", "3B_12", "3B_12_1", "3B_12_2", "3B_12_21", "3B_12_22", "3B_2" };
    ifstream inFile;
    inFile.open(txtFile);
    if(!inFile)
    {
       cout << "Could not open storyfile" << endl;
       return false;
    }
    string identifier;
    string line;
    int i = 0;
    while(getline(inFile,line)) // reads storyline.txt line by line
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
    addEdge("1C_11_2", "1C_21");
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
    character player;
    player.fear = 0;
    player.roomGarageKey = false;
    player.girlFound = false;
    player.potion = false;
    return true;
}

void Game::saveNode()
{
    // To save and distrubt the current location
    // This way we can also add it to the unique output for the user in the txt file
}



void Game::makeChoice(vertex *v) // Function to make choices
{
    // To node based on user choice
    // if(!v->visited) cout << v->identifier << endl;
    // v->visited = true;
    // if(!(v->Edges[i].v->visited == true))
    // {
    //     DFT_traversal(v->Edges[i].v);
    // }
}
