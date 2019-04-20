#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <list>
#include <queue>

using namespace std;

// cpp file intended to be for the bulk of the game as to remove it from the clutter of the intital stages

//  Directed graph, allows user to back track after dying
//  txt of final unique path
//  cyclical
struct vertex;

struct Edge
{
    vertex *v;
};

struct vertex
{
    //character *player;
    string identifier; // Identifier of the node
    string chapter; // Chapter or string for storyPart
    bool visited;
    vector<Edge> Edges; //stores edges to adjacent vertices
};

struct character
{
    int fear; // This will effect players ability to make certain choices (ex. Broken leg, can't climb)
    bool roomGarageKey; // A key that can be found in the first room
    bool girlFound; // Bool to represent if the girl is found
    bool potion; // Bool to represent if potion is found
};

class Game
{
  public:
    // Graph();
    // ~Graph();
    void addVertex(string identifier, string storyPart);
    void addEdge(string identifier1, string identifier2);
    void displayEdges();
    void printDFT();
    void setAllVerticesUnvisited();

    void saveProgress();
    bool loadGame(string txtFile);
    void saveNode();
    void makeChoice(vertex *v); // Function to make choices
    //vector<vertex> BFS(int componentNum, int src, int visited[])

  private:
    vector<vertex> vertices; //stores vertices
    vertex *currNode;
    vertex *findVertex(std::string name);
    void DFT_traversal(vertex *v);

};

#endif
