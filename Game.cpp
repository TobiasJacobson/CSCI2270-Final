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
Graph::Graph()
{
    // No dynamic memory - so not needed
}
Graph::~Graph()
{
    // No dynamic memory - so not needed
}
void Graph::addVertex(string identifier, string storyPart)
{
    vertex newVertex;
    newVertex.visited = false;
    newVertex.identifier = identifier
    newVertex.chapter = storyPart
    vertices.push_back(newVertex);
}
void Graph::addEdge(string storyPart1, string storyPart2)
{
    for(int i = 0; i < vertices.size(); i++)
    {
         if(vertices[i].identifier == storyPart1)
         {
             for(int j = 0; j < vertices.size(); j++)
             {
                 if(vertices[j].identifier == storyPart2 && i != j) // i != j bc then we'd pus_back not within the limits of the graph size
                 {
                    Edge aV;
                    aV.v = &vertices[j];
                    vertices[i].Edges.push_back(aV);
                 }
             }
         }
     }
}
void Graph::displayEdges()
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
void Graph::printDFT();
{
    setAllVerticesUnvisited();
    for(int i = 0; i < vertices.size(); i++)
    {
        DFT_traversal(&vertices[i]);
    }
}
void Graph::printBFT()
{
    setAllVerticesUnvisited();
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].visited == false)
        {
            vertices[i].visited = true;
            BFT_traversal(&vertices[i]);
        }
    }
}
void Graph::setAllVerticesUnvisited()
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
vertex* Graph::findVertex(string identifier){

    for(int i = 0; i < vertices.size(); i++)
    {
        vertex myV = DFS(&vertices[i], identifier);
    }
}
void Graph::BFT_traversal(vertex *v)
{
    list<vertex*> queue;
    queue.push_back(v);
    v->visited = true;
    while(!queue.empty())
    {
        vertex *s = queue.front();
        cout << s->name << endl;
        queue.pop_front();
        for(int i=0; i< s->Edges.size(); i++)
        {
            if(s->Edges[i].v->visited == false)
            {
                s->Edges[i].v->visited = true;
                queue.push_back(s->Edges[i].v);
            }
        }
    }
}
void Graph::DFT_traversal(vertex *v)
{
    if(!v->visited) cout << v->name << endl;
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
void Graph::saveProgress()
{
    // Need some way to store the current vertex and keep track of where the user is.
}
void Graph::loadSavedGame() // If time allows
{
    // Revert back to make previous load because they died or the simpl want to go back
}

void Graph::saveNode()
{
    // To save and distrubt the current location
    // This way we can also add it to the unique output for the user in the txt file
}

void makeChoice() // Function to make choices
{
    // Left or right based on their choice
}
