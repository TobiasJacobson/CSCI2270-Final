#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <list>
#include <queue>

using namespace std;

// hpp file for most functions and structs used in game

struct vertex; // So it can be referenced in Edge struct

// Struct of Edges to each vertex
struct Edge
{
    vertex *v;
};

// Struct of vertices in the graph
struct vertex
{
    string identifier; // Identifier of the node
    string chapter; // Chapter or string for storyPart
    bool visited;
    vector<Edge> Edges; //stores edges to adjacent vertices
};

// Struct for the player
struct character
{
    int searchTimes; // Keeps track of times user has searched
    int fear; // This will effect players ability to make certain choices
    bool roomGarageKey; // A key that can be found in the first room
    bool girlFound; // Bool to represent if the girl is found
    bool potion; // Bool to represent if potion is found
    character() // Constructor for character struct
    {
        searchTimes = 0;
        fear = 0;
        roomGarageKey = false;
        girlFound = false;
        potion = false;
    }
    //vector<string> fullPath;
};

// Class for most game functions
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
    vertex *startGame(); // Returns user start position
    bool riddle(); // Asks user a riddle
    void checkConditions(character *characterPosition); // Checks all conditions
    character *characterStart(); // Creates a new character
    character *characterReboot(int, int, bool, bool, bool); // Loads a previous character
    void showStats(character *characterPosition); //developer tool to show progress

    vertex *userPos; // Public variable to access the current user position
    vertex *savedProgress; // Public variable to allow loading of a new game
    character *player; // Public access to user at all times
    bool isGameOver; // If game is ended or user is killed
    bool isGameWon = false; // If game is won or user escapes
  private:
    vector<vertex> vertices; //stores vertices
    vector<character> userPlayer; // Stores players
    vertex *currNode;
    void DFT_traversal(vertex *v);
};

#endif
