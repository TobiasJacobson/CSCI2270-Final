#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <list>
#include <queue>

using namespace std;

// hpp file for most functions and structs used in game
struct vertex;

struct Edge
{
    vertex *v;
};

struct vertex
{
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

struct savedNode
{
    string saveName;
    vertex *savePos;
    character *saveCharacter;
};

class Game
{
  public:
    // Graph(); // No dynamic memory - so not needed
    // ~Graph();// No dynamic memory - so not needed
    void addVertex(string identifier, string storyPart);
    void addEdge(string identifier1, string identifier2);
    void displayEdges();
    void printDFT();
    void setAllVerticesUnvisited();

    void saveProgress();
    bool loadGame(string txtFile);
    void saveNode(string n, vertex *v, character *c);
    void loadPreviousGame();
    void generatePreviousGame(int user);
    void showChapter(vertex *curr);
    vertex *makeChoice(int choice, vertex *v); // Function to make choices
    vertex *startGame();
    void checkConditions();

    vertex *userPos; // Public variable to access the current user position
    vertex *savedProgress; // Public variable to allow loading of a new game
    character *player;
  private:
    vector<vertex> vertices; //stores vertices
    vector<savedNode> saves; // Stores saves
    vertex *currNode;
    vertex *findVertex(std::string name);
    void DFT_traversal(vertex *v);

};

#endif
