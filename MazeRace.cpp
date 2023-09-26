//=========================================================================
// 2 Player Minotaur VS Theseus -- Minotaur player tries to block off the
//                 exit before Theseus can reach it.
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
bool move(char maze[][WIDTH], int& thesX, int& thesY, int& minX, int& minY,
    int newX, int newY);
//------------------------------------------------------------------------
// Doesn't let players move past walls
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
// Identifies exit as a win
//---------------------------------------------------------------
bool move(char maze[][WIDTH], int& thesX, int& thesY, int& minX, int& minY,
    int newX, int newY)
{
    bool foundExit = false;
    if (maze[newY][newX] == 'E') // Check for exit
        foundExit = true;
    thesX = newX; // Update location
    thesY = newY;
    return foundExit;
}
//---------------------------------------------------------------
// Display the maze in ASCII
//---------------------------------------------------------------
void printMaze(char maze[][WIDTH], int thesx, int thesy, int minX, int minY)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {

            if ((x == thesx) && (y == thesy))
                cout << "T";
            else if ((x == minX) && (y == minY))
                cout << "M";
            else
                cout << maze[y][x];
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
    int a = 1, b = 8;
    bool foundExit = false;                        // change 1
    while (!foundExit)                  // change 2
        {
        cout << "Welcome to our version of Theseus and the Minotaur!" << endl;
        cout << " " << endl;
        cout << "Player One: You are Theseus, trapped in this grid like maze with a monster" <<
            " called the Minotaur." << endl;
        cout << "You must use your smarts to outsmart that of the Minotaur to" <<
            " escape to the exit with your life." << endl;
        cout << "Every time you make a move, the Minotaur will have chance to move after you!" << endl;
        cout << "You can escape the Minotaur by using the w,a,s,d keys to move around" <<
            " the maze to the exit." << endl;
        cout << "If you can successfully reach the exit before the Minotaur does" <<
            ", you win!" << endl;
        cout << " " << endl;
        cout << "Player Two: Minotaur, you are able to move around with the i,j,k,l keys." << endl;
        cout << "If you get to the exit before Theseus does you can block his only chance to escape and win!" << endl;
        cout << " " << endl;
        cout << "Good luck to you both and have fun!" << endl;
        cout << " " << endl;
        cout << "Grid Key: Walls are X's, Theseus is T, Minotaur is M," <<
            " and the Exit is E." << endl;
        cout << " " << endl;

            printMaze(maze, x, y, a, b);

            cout << " " << endl;
            cout << "Reminder 1: Enter WASD (for Theseus) or IJKL (for Minotaur) to move." << endl;
            cout << "Reminder 2:TAKE TURNS! Theseus (Player One) goes first, then the Minotaur (Player 2)." << endl;
            char c;
            cin >> c;
            c = tolower(c);
            switch (c)
            {
            case 'w':
                if (validMove(maze, x, y - 1))
                    foundExit = move(maze, x, y, x, y, x, y - 1);
                break;
            case 'a':
                if (validMove(maze, x - 1, y))
                    foundExit = move(maze, x, y, x, y, x - 1, y);
                break;
            case 's':
                if (validMove(maze, x, y + 1))
                    foundExit = move(maze, x, y, x, y, x, y + 1);
                break;
            case 'd':
                if (validMove(maze, x + 1, y))
                    foundExit = move(maze, x, y, x, y, x + 1, y);
                break;
            case 'i':
                if (validMove(maze, a, b - 1))
                    foundExit = move(maze, a, b, a, b, a, b - 1);
                break;
            case 'j':
                if (validMove(maze, a - 1, b))
                    foundExit = move(maze, a, b, a, b, a - 1, b);
                break;
            case 'k':
                if (validMove(maze, a, b + 1))
                    foundExit = move(maze, a, b, a, b, a, b + 1);
                break;
            case 'l':
                if (validMove(maze, a + 1, b))
                    foundExit = move(maze, a, b, a, b, a + 1, b);

            
        }
    }

}