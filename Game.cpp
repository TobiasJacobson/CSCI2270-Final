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

// STRUCTS ---------------------------------------------------------------------
// struct Edge
// {
//     vertex *v;
// };
//
// struct vertex
// {
//     string chapter; // Chapter or string for entire storyPart string??
//     bool visited;
//     vector<Edge> Edges; //stores edges to adjacent vertices
// };

// PRIVATE VARIABLES -----------------------------------------------------------
// vector<vertex> story; //stores vertices
//vertex *currNode;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Graph::Graph();
Graph::~Graph();
void Graph::addVertex(string storyPart);
void Graph::addEdge(string storyPart1, string storyPart2);
void Graph::displayEdges();
void Graph::printDFT();
void Graph::printBFT();
void Graph::setAllVerticesUnvisited();

void Graph::saveProgress()
{
    // Need some way to store the current vertex and keep track of where the user is.
}
void Graph::loadSavedGame()
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


vertex *Graph::findVertex(std::string name);
void Graph::BFT_traversal(vertex *v);
void Graph::DFT_traversal(vertex *v);
