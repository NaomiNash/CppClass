//=========================================================================
// 2 Player Minotaur VS Theseus -- Minotaur player tries to catch Theseus
//                  before Theseus reaches the exit.
// 		  Aaron Burke, Naomi Nash, Conner Paine, Thomas Madden -- 
//		          Saint Leo University -- 4/18/2021
//=========================================================================
#include <iostream>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
const int WIDTH = 20;
const int HEIGHT = 10;
//---------------------------------------------------------------
// Function prototypes
//---------------------------------------------------------------
void printMaze(char maze[][WIDTH], int thesx, int thesy, int minX, int minY);
bool validMove(char maze[][WIDTH], int newX, int newY);
//bool move(char maze[][WIDTH], int &thesX, int &thesY, int &minX, int &minY, int newX, int newY);
bool movet(char maze[][WIDTH], int& thesX, int& thesY, int newX, int newY);
bool movem(char maze[][WIDTH], int& minX, int& minY, int newX, int newY);
//------------------------------------------------------------------------
// Return true or false if moving to the specified coordinate is valid
//------------------------------------------------------------------------
bool validMove(char maze[][WIDTH], int newX, int newY)
{
    // Check for going off the maze edges
    if (newX < 0 || newX >= WIDTH)
        return false;
    if (newY < 0 || newY >= HEIGHT)
        return false;
    // Check if target is a wall
    if (maze[newY][newX] == 'X')
        return false;
    return true;
}
//---------------------------------------------------------------
// Make the move on the maze to move to a new coordinate
// I passed thesX and thesY by reference so they are changed to
// the new coordinates. Same for minX and minY.
// This returns true if T moves onto the exit, false otherwise.
// Returns true if M moves onto the T, false otherwise.
//---------------------------------------------------------------
bool movet(char maze[][WIDTH], int& thesX, int& thesY, int newX, int newY)
{
    bool foundExit = false;
    // for debugging cout<<"T "<<maze[newY][newX]<<endl;
    if (maze[newY][newX] == 'E') // Check for exit
        foundExit = true;
    maze[thesY][thesX] = ' '; //making the location blank again before updating T

    thesX = newX; // Update location
    thesY = newY;
    // for db: cout<<"FE "<<foundExit<<endl;
    return foundExit;

}

bool movem(char maze[][WIDTH], int& minX, int& minY, int newX, int newY)
{
    bool foundTheseus = false;
    // for db: cout<<"M "<<maze[newY][newX]<<endl;
    if (maze[newY][newX] == 'T') // Check for Theseus
        foundTheseus = true;
    maze[minY][minX] = ' '; //making the location blank again before updating M
    minX = newX; // Update location
    minY = newY;
    // for db: cout<<"FT "<<foundTheseus<<endl;
    return foundTheseus;
}

//---------------------------------------------------------------
// Display the maze in ASCII
//---------------------------------------------------------------
void printMaze(char maze[][WIDTH], int thesx, int thesy, int minX, int minY)
{

    maze[thesy][thesx] = 'T'; // Not just display T but actually update it in the maze
    maze[minY][minX] = 'M'; // Same goes for M

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            cout << maze[y][x]; // Print the actual maze
        }
        cout << endl;
    }
}
//---------------------------------------------------------------
// MAIN PROGRAM
//---------------------------------------------------------------
int main()
{
    char maze[HEIGHT][WIDTH] = {
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    {'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X'},
    {'X', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X'},
    {'X', ' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
    {'X', ' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X', 'X'},
    {'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X'},
    {'X', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X'},
    {'X', ' ', 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X'},
    {'X', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', 'X', 'E', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'} };
    int x = 1, y = 1;
    int a = 9, b = 5;
    bool foundExit = false;
    bool foundTheseus = false;
    while (!foundExit && !foundTheseus)
    {

        cout << "Welcome to our version of Theseus and the Minotaur!" << endl;
        cout << " " << endl;
        cout << "Player One: You are Theseus, trapped in this grid like maze with a monster" <<
            " called the Minotaur." << endl;
        cout << "You must use your smarts to outsmart that of the Minotaur to" <<
            " escape to the exit with your life." << endl;
        cout << "Every time you make a move, the Minotaur will have chance to move after you!" << endl;
        cout << "You can escape the maze and the Minotaur by using the w,a,s,d keys to move around" <<
            " the maze to the exit." << endl;
        cout << "If you can successfully reach the exit before the Minotaur catches you" <<
            ", you get to keep your life!" << endl;
        cout << " " << endl;
        cout << "Player Two: Minotaur, you are able to move around with the i,j,k,l keys." << endl;
        cout << "If you get to Theseus before he escapes, you get a nutritious meal!" << endl;
        cout << " " << endl;
        cout << "Good luck to you both and have fun!" << endl;
        cout << " " << endl;
        cout << "(Grid Key: Walls are X's, Theseus is T, Minotaur is M," <<
            " and the Exit is E)." << endl;
        cout << " " << endl;

        printMaze(maze, x, y, a, b);
        char c;
        cin >> c;
        c = tolower(c);
        switch (c)
        {
        case 'w':
            if (validMove(maze, x, y - 1))
                foundExit = movet(maze, x, y, x, y - 1);
            break;
        case 'a':
            if (validMove(maze, x - 1, y))
                foundExit = movet(maze, x, y, x - 1, y);
            break;
        case 's':
            if (validMove(maze, x, y + 1))
                foundExit = movet(maze, x, y, x, y + 1);
            break;
        case 'd':
            if (validMove(maze, x + 1, y))
                foundExit = movet(maze, x, y, x + 1, y);
            break;
        case 'i':
            if (validMove(maze, a, b - 1))
                foundTheseus = movem(maze, a, b, a, b - 1);
            break;
        case 'j':
            if (validMove(maze, a - 1, b))
                foundTheseus = movem(maze, a, b, a - 1, b);
            break;
        case 'k':
            if (validMove(maze, a, b + 1))
                foundTheseus = movem(maze, a, b, a, b + 1);
            break;
        case 'l':
            if (validMove(maze, a + 1, b))
                foundTheseus = movem(maze, a, b, a + 1, b);
        }
    }
    cout << "\nGAME OVER... \nTwas a valiant effort!!" << endl;
}