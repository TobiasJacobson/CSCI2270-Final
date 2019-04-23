#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <list>
#include <queue>
#include <sstream>

#include "Game.hpp"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Function to add a newVertex to verticies with the given inputs
void Game::addVertex(string identifier, string storyPart)
{
    // Creating new vertex and assigning given inputs
    vertex newVertex;
    newVertex.visited = false;
    newVertex.identifier = identifier;
    newVertex.chapter = storyPart;
    vertices.push_back(newVertex);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Adds an edge between the identifiers of the two given vertices
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
                    // Creates new edge and "connects" identifier1 && identifier2
                    Edge aV;
                    aV.v = &vertices[j];
                    // Adding edge to vector of edges for identifer1
                    vertices[i].Edges.push_back(aV);
                 }
             }
         }
     }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Displays each vertex in vertices and all of it edges following the --> seperated by ***
void Game::displayEdges()
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
// Will print all vertices in a Depth First Traversal order
void Game::printDFT()
{
    // First set all nodes in th graph as unvisited
    setAllVerticesUnvisited();
    // Then loop through all vertices in the vector of vertices
    for(int i = 0; i < vertices.size(); i++)
    {
        DFT_traversal(&vertices[i]);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Will set all verticies as unvisited
void Game::setAllVerticesUnvisited()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i].visited = false;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Allows you to search for a specific vertex in verticies && will return its pointer
vertex *Game::findVertex(string identifier)
{
    int pos = -1;
    string arr[] = {"0", "1", "2", "3", "1A","1A_1", "1A_2", "1A_11", "1A_11_1", "1A_11_2", "1B", "1C", "1C_1", "1C_11", "1C_11_1", "1C_11_2", "1C_2", "1C_21", "1C_21_1", "1C_21_2", "1C_3", "3A", "3B", "3B_1", "3B_11", "3B_12", "3B_12_1", "3B_12_2", "3B_12_21", "3B_12_22", "3B_2" }; // 31
    for(int i = 0; i < 31; i++)
    {
        if(arr[i] == identifier) /// If equal to, will retain that position
        {
            pos = i;
        }
    }
    return &vertices[pos];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Traveses vertices in a Depth First Traversal order
void Game::DFT_traversal(vertex *v)
{
    // If node hasn't been visited, return it and set it to visited
    if(!v->visited) cout << v->identifier << endl;
    v->visited = true;
    // Loop through all vertices and edges
    for(int i = 0; i < v->Edges.size(); i++)
    {
        if(!(v->Edges[i].v->visited == true))
        {
            // Passes first edge vector item of the vertex because of depth first order
            DFT_traversal(v->Edges[i].v);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Allows user to save their progress and resume under the load game option in main menu
void Game::saveProgress()
{
    cout << "Enter a name for the save file" << endl;
    string fileN; //file's name
    getline(cin, fileN);
    fileN = fileN + ".txt"; //make it a txt file
    ofstream saveState;
    saveState.open(fileN); //creating new file
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
// This function loads the default gaming, reading all vertices and their spcific information
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
    // Reads txt file line by line, creating a new vertex for each line read (Each line contains a story part)
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
    // initializing public variables and return true to notify loading has been accomplished
    isGameOver = false;
    isGameWon = false;
    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Returns the first user postion of vertices[0]
vertex *Game::startGame()
{
    return &vertices[0];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Displays the chapter/story part/story section of the given vertex node
void Game::showChapter(vertex *curr)
{
    cout << curr->chapter << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function allowing user to make a choice based on the chapter of the most recent node
// Each part displays options (1) through (n), the user inputs their choice and their position is changed to the chosen options node
vertex *Game::makeChoice(int choice, vertex *v)
{
    // A simple call to make sure the choice is within the vertex nodes bounderies
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
// Node 3B_1 asks the user a riddle, this is the function for checking user inputs and validating the answer
bool Game::riddle()
{
    srand(time(0)); //makes the numbers actually random
    int riddleNum = rand()% 2 + 1; // 1-3 int
    string ans; //user input
    // 3 Different riddles to allow for more variation in each game playthrough
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
// A large function to check various conditions in each turn made by the user
void Game::checkConditions(character *characterPosition)
{
    // Keeps track of whether riddle answer was correct
    int riddleCorrect = false;
    // If user searcehs to many times, game is over
    if(characterPosition->searchTimes >= 2) //Too many searches
    {
        cout << "You peer around again, desperately hoping to find something that help you get out safely. You are so busy studying the contents of the boxes you barely notice the shadow of the figure until its fingers close over your neck and crush. -See you in another life-" << endl;
        isGameOver = true;
    }
    // If user position is 2 (i.e. searching), there are 3 possibles things to be found
    if(userPos->identifier == "2")
    {
        characterPosition->searchTimes++;
        srand(time(0));
        int randGen = rand()%9 + 1;
        if(randGen > 0 && randGen < 4) // Finding hatch
        {
            cout << "You found a hidden hatch!" << endl;
            cout << "It's a rusty metal slate with a small ring at its edge. As you open the hatch it creaks immensely loud and in fear of it attracting whatever is in the house, you descend down the ladder into the abyss. It's a rather short ladder down into a small dimly lit room. The only thing in the room is another ladder across from you leading up. So with no other option you begin to ascend." << endl;
            userPos = userPos->Edges[1].v;
            cout << endl;
        }
        else if(randGen > 3 && randGen < 7) // Finding Garage Key
        {
            cout << "You decide it's best to prepare yourself and gear up in the event that who or whatever is in the house decides to come back. You begin to scavenge the room for anything that could be of use. On the shelves behind you are see some dusty plates and mugs which look like they haven't been moved in years. Higher up you notice a small ragged sack tucked into the corner. You pull it down and begin loosening the knot on it, but to your surprise the knot breaks as you pick at it. Peering into the bag, unable to see in the dim light, you hesitantly stick your hand in and pull out a rusty key. Hoping it could be useful you put the key in your back pocket. You found a key! The key has been added to your inventory. Continue exploring to find what the key opens." << endl;
            characterPosition->roomGarageKey = true;
            userPos = userPos->Edges[0].v;
            cout << endl;
        }
        else if(randGen >= 7 && randGen <= 10) // Finding Severed head
        {
            srand(time(0));
            int addFear = rand()% 20 + 15;
            characterPosition->fear += addFear;
            cout << "You decide it's best to prepare yourself and gear up in the event that who or whatever is in the house decides to come back. You begin to scavenge the room for anything that could be of use. As you look around the room you notice a small box in the dark corner. Walking over to the box you are hit with a sudden putrid smell of decay. Weary of what it may contain, you decide to bring it the light in the center of the room. Yet as you pick it up, grasping the underside, your hands are suddenly covered in a warm, thick substance. As you lift it higher you feel the bottom begin to sink down. You realize what you are holding is a human head. You scream and throw the box into the corner. You take deep breaths to calm yourself down but you feel permanently shaken." << endl;
            userPos = userPos->Edges[0].v;
            cout << endl;
        }
        else
        {
            cout << "Something went wrong" << endl;
        }
    }
    // If user position is 1C_11, sets the character varable to true
    if(userPos->identifier == "1C_11")
    {
        characterPosition->girlFound = true;
    }
    // 30% chance of dying in play room
    if(userPos->identifier == "1A_1")
    {
        cout << "You enter the playroom, choosing the creepy dolls over total darkness. You pick  your way through the toys, careful not to disturb their rest. Suddenly out of the corner of your eye a rocking horse in the darkest corner starts moving back and forth, seemingly of its own accord. You freeze. Then a toy soldier floats into the air and is lifted around. You stand like a statue as one toy at a time is 'played with' and the trail of paranormal activity is slowly coming towards you. You can barely see the outline of a figure with long arms and legs and a strange head. The toy closest to you, a doll wearing a torn dress, is hoisted into the air and spun around and then is dropped to the floor. You get the feeling you are next." << endl;
        //////////////////////////////////////////////////
        srand(time(0));
        int randGen = rand()%9 + 1;
        if(randGen > 0 && randGen < 4)
        {
            cout << "You stand motionless, your heart beating so hard you're sure anything in the room could hear it. Just as you feel the sinister presence has passed, you are picked up as if you weighed nothing and slammed into the floor. You scream in terror and pain and your vision goes red. You hear an angry hiss and long, rough fingers close around your neck. You struggle in vain against the superhuman strength but you cannot escape. You lose consciousness, becoming a better plaything for the monster. -See you in another life-" << endl;
            isGameOver = true;
        }
        else
        {
            cout << "You wait in silence for the entity to 'play' with you, motionless for at least five minutes, but nothing happens. You get the feeling you need to keep moving so after mustering your courage you start sneaking towards the other side of the room where a ladder leads up to darkness. Successfully avoiding making too much noise you grasp the ladder and begin to climb out of the room." << endl;
            userPos = userPos->Edges[0].v;
            cout << endl;
        }
    }
    //Shadow man and riddle
     if(userPos->identifier == "3B_1") //Shadow man
    {
        if(riddle()) // If riddle is true, moved to potions node
        {
            userPos = userPos->Edges[1].v;
        }
        else // If false, user dies
        {
            userPos = userPos->Edges[0].v;
        }
    }
    // If user answers riddle correctly, they are moved to potion node and given the potion
    if(userPos->identifier == "3B_12")
    {
        characterPosition->potion = true;
    }
    // There are several nodes which increase the users fear level , if user is at nay of these positions, featr is increased by RNG amount
    if(userPos->identifier == "1" || userPos->identifier == "1A" || userPos->identifier == "1A_2" ||
    userPos->identifier == "1C_1" || userPos->identifier == "1C_2" || userPos->identifier == "3B_2" || userPos->identifier == "3B_12_2"
    || userPos->identifier == "1A_11" || userPos->identifier == "3B_12_1")
    {
        srand(time(0));
        int addFear = rand()% 20 + 15;
        characterPosition->fear += addFear;
    }
    // If user has too much fear, they die
    if(characterPosition->fear >= 100)
    {
        cout << "Knees shaking, you collapse to the ground. You can't take the stress anymore! You black out and never wake up." << endl;
        isGameOver = true;
    }
    // If user chooses to drink the potion and fear is too low, they will die
    if(userPos->identifier == "3B_12_22" && characterPosition->fear <= 80)
    {
        cout << "You un-stop the potion, shaking your head at what you're about to do. Tilting your head back you drain the contents into your throat. The taste is hard to describe but it might be the best thing you've ever tasted. It's equal parts sweet and savory and reminds you of your mom's cooking and home. You smile thinking back to all the good times and know that everything is going to be okay. You start to rise up feeling confident that you can overcome whatever threat presents itself when suddenly your throat constricts. You can't breathe! You claw at your neck but it's futile. You also feel your skin start to heat up. No. It's burning! You double over in pain and fall to the ground, still unable to breathe. Your last thought is of the feelings of home you got- a false feeling of security, but you cling onto it as the life seeps out of you. -See you in another life- " << endl;
        isGameOver = true;
    }
    // If user chooses to drink the potion and fear is high enough, they win
    if(userPos->identifier == "3B_12_22" && characterPosition->fear > 80)
    {
        cout << "You un-stop the potion; shaking your head at what you're about to do. Tilting your head back you drain the contents into your throat. The taste immediately hits you like a wall. It burns your throat like fire while also being the most bitter and sour thing you've ever tasted. You're so afraid of what's going to happen. You feel death near. You're heart is beating so hard you feel like its gonna come out of your chest. Suddenly you feel a pain in your arms and legs and they start to lengthen before your eyes. Your head spasms and you feel the skin expanding. What is happening to you? You see your skin darken before your eyes and your vision fades to black. You try to scream but your mouth isn't working. In a few seconds you open your eyes again but something's not right. You can see much farther up and around, and the world is grey except for the heat coming from things around you, a radiator is a dull yellow, and a mouse skittering by the corner is a lump of red. Your feeling of fear and desire to escape has been replaced by one thing: the hunger to squeeze the life out of anything you can find. You have become one of the monsters. Congratulations?" << endl;
        isGameWon = true;
    }
    // If the user is located at anyone of these nodes, they will die
    if(userPos->identifier == "1B" || userPos->identifier == "1A_1" || userPos->identifier == "1A_11_1" ||
    userPos->identifier == "1C_3" || userPos->identifier == "1C_11_1" || userPos->identifier == "1C_21_2" || userPos->identifier == "3A" ||
    userPos->identifier == "3B_11" || userPos->identifier == "3B_12_21")
    {
        isGameOver = true;
    }
    // User must be returned to node (3) if they are at (3B_2)
    if(userPos->identifier == "3B_2")
    {
      userPos = userPos->Edges[0].v;
    }
    // One of the very few nodes where the user can escape
    if(userPos->identifier == "1A_11_2")
    {
        isGameWon = true;
    }
    // At node 1C_21_1 the user must have one of two things, either the girl or less than 50% fear
    if(userPos->identifier == "1C_21_1")
    {
        if(characterPosition->girlFound == true || characterPosition->fear < 51)
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
// Generates a new character at start of new game
character *Game::characterStart()
{
    character userStart;
    userStart.searchTimes = 0;
    userStart.fear = 0; // This will effect players ability to make certain choices
    userStart.roomGarageKey = false; // A key that can be found in the first room
    userStart.girlFound = false; // Bool to represent if the girl is found
    userStart.potion = false; // Bool to represent if potion is found
    userPlayer.push_back(userStart); // Adds to vector of players
    return &userPlayer[0];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Loads a previous character with given inputs when loading a previous game
character *Game::characterReboot(int search, int fear, bool key, bool girl, bool pot)
{
    character userStart;
    userStart.searchTimes = 0;
    userStart.fear = 0; // This will effect players ability to make certain choices (ex. Broken leg, can't climb)
    userStart.roomGarageKey = key; // A key that can be found in the first room
    userStart.girlFound = girl; // Bool to represent if the girl is found
    userStart.potion = pot; // Bool to represent if potion is found
    userPlayer.push_back(userStart);
    return &userPlayer[0];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
