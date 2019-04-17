#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <list>
#include <queue>



// cpp file intended to be for the bulk of the game as to remove it from the clutter of the intital stages

//  Directed graph, allows user to back track after dying
//  txt of final unique path
//  cyclical
struct Edge
{
    vertex *v;
};

struct vertex
{
    string chapter; // Chapter or string for entire storyPart string??
    bool visited;
    vector<Edge> Edges; //stores edges to adjacent vertices



};

struct character
{
    
    bool injuries; // These will effect players ability to make certain choices (ex. Broken leg, can't climb)
    bool roomOneKey; // A key that can be found in the first room. It opens ______
};

class Graph
{
  public:
    Graph();
    ~Graph();
    void addVertex(string storyPart);
    void addEdge(string storyPart1, string storyPart2);
    void displayEdges();
    void printDFT();
    void printBFT();
    void setAllVerticesUnvisited();

    void saveProgress();
    void loadSavedGame();
    void saveNode();
    void makeChoice(); // Function to make choices

  private:
    std::vector<vertex> vertices; //stores vertices
    vertex *currNode;
    vertex *findVertex(std::string name);
    void BFT_traversal(vertex *v);
    void DFT_traversal(vertex *v);

};

#endif
