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
    int searchTimes;
    int fear; // This will effect players ability to make certain choices (ex. Broken leg, can't climb)
    bool roomGarageKey; // A key that can be found in the first room
    bool girlFound; // Bool to represent if the girl is found
    bool potion; // Bool to represent if potion is found
    character()
    {
        searchTimes = 0;
        fear = 0;
        roomGarageKey = false; // A key that can be found in the first room
        girlFound = false; // Bool to represent if the girl is found
        potion = false; // B
    }
    vertex *savePos;
    //vector<string> fullPath;
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
    vertex *findVertex(string name);

    void saveProgress();
    bool loadGame(string txtFile);
    void showChapter(vertex *curr);
    vertex *makeChoice(int choice, vertex *v); // Function to make choices
    vertex *startGame();
    bool riddle();
    void checkConditions(character *characterPosition);
    character *characterStart();
    character *characterReboot(int, int, bool, bool, bool);

    vertex *userPos; // Public variable to access the current user position
    vertex *savedProgress; // Public variable to allow loading of a new game
    character *player;
    bool isGameOver;
    bool isGameWon = false;
  private:
    vector<vertex> vertices; //stores vertices
    vector<character> userPlayer;
    vertex *currNode;

    void DFT_traversal(vertex *v);

};

#endif
