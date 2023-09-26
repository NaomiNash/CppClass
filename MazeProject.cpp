//========================================================================
// 2 Player Minotaur VS Theseus -- Minotaur player tries to intercept 
// Theseus before he escapes.
// 		Aaron Burke, Naomi Nash, Conner Paine, Thomas Madden -- 
//		Saint Leo University -- 4/17/2021
//========================================================================
#include <iostream>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;
const int WIDTH = 20;
const int HEIGHT = 10;
//---------------------------------------------------------------
// Function prototypes
//---------------------------------------------------------------
void printMaze(char maze[][WIDTH], int curx, int cury, int minx, int miny);
bool validMove(char maze[][WIDTH], int newX, int newY, int minnewX, int minnewY);
bool move(char maze[][WIDTH], int& curX, int& curY, int& minx, int& miny,
	int newX, int newY, int minnewx, int minnewY);
// Return true or false if moving to the specified coordinate is valid
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
// ---Minotaur Valid Moves-----------------
bool minvalidMove(char maze[][WIDTH], int minnewX, int minnewY)
{
	// Check for going off the maze edges
	if (minnewX < 0 || minnewX >= WIDTH)
		return false;
	if (minnewY < 0 || minnewY >= HEIGHT)
		return false;
	// Check if target is a wall
	if (maze[minnewY][minnewX] == 'X')
		return false;
	return true;

//---------------------------------------------------------------
// Make the move on the maze to move to a new coordinate
// I passed curX and curY by reference so they are changed to
// the new coordinates. I assume the move coordinates are valid.
// This returns true if we move onto the exit, false otherwise.
//---------------------------------------------------------------
bool move(char maze[][WIDTH], int& curX, int& curY,
	int newX, int newY);
{
	bool foundExit = false;
	if (maze[newY][newX] == 'E') // Check for exit
		foundExit = true;
	curX = newX; // Update location
	curY = newY;
	return foundExit;
}
// ----------------------------
bool minmove(char maze[][WIDTH], int& minX, int& minY,
	int minnewX, int minnewY);
{
	bool foundTheseus = false;
	if (maze[minnewY][minnewX] == 'T') // Check for Theseus
		foundTheseus = true;
	minX = minnewX; // Update location
	minY = minnewY;
	return foundTheseus;
}

//---------------------------------------------------------------
// Display the maze in ASCII
//---------------------------------------------------------------
void printMaze(char maze[][WIDTH], int curx, int cury, int minx, int miny);
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if ((x == curx) && (y == cury))
				cout << "T";
			else
				cout << maze[y][x];
			if ((x == minx) && (y == miny))
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
int main();
{
	char maze[HEIGHT][WIDTH] = {
	 {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
	 {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','X'},
	 {'X',' ','X',' ',' ',' ','X',' ',' ',' ',' ','X',' ',' ',' ','X',' ',' ',' ','X'},
	 {'X',' ','X','X','X',' ','X',' ','X','X','X','X',' ',' ',' ',' ',' ',' ',' ','X'},
	 {'X',' ',' ',' ','X',' ','X',' ',' ',' ',' ',' ',' ','X','X','X',' ',' ','X','X'},
	 {'X',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','X'},
	 {'X',' ','X','X','X',' ',' ',' ',' ',' ',' ','X',' ','X','X','X',' ','X',' ','X'},
	 {'X',' ','X',' ',' ',' ','X',' ','X','X','X','X',' ',' ',' ',' ',' ','X',' ','X'},
	 {'X',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ','X',' ','X','E','X'},
	 {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
	};
	int x = 1, y = 1;
	bool foundExit = false;
	bool foundTheseus = false;
	while (!foundExit)
	{
		printMaze(maze, x, y);
		cout << "Enter WASD to move." << endl;
		char c;
		cin >> c;
		c = tolower(c);
		switch (c)
		{
		case 'w':
			if (validMove(maze, x, y - 1))
				foundExit = move(maze, x, y, x, y - 1);
			break;
		case 'a':
			if (validMove(maze, x - 1, y))
				foundExit = move(maze, x, y, x - 1, y);
			break;
		case 's':
			if (validMove(maze, x, y + 1))
				foundExit = move(maze, x, y, x, y + 1);
			break;
		case 'd':
			if (validMove(maze, x + 1, y))
				foundExit = move(maze, x, y, x + 1, y);
		}
	}
	// ------------
	while (!foundTheseus)
	{
		printMaze(maze, x, y);
		cout << "Enter IJKL to move." << endl;
		char c;
		cin >> c;
		c = tolower(c);
		switch (c)
		{
		case 'i':
			if (minvalidMove(maze, x, y - 1))
				foundTheseus = move(maze, x, y, x, y - 1);
			break;
		case 'j':
			if (minvalidMove(maze, x - 1, y))
				foundTheseus = move(maze, x, y, x - 1, y);
			break;
		case 'k':
			if (minvalidMove(maze, x, y + 1))
				foundTheseus = move(maze, x, y, x, y + 1);
			break;
		case 'l':
			if (minvalidMove(maze, x + 1, y))
				foundTheseus = move(maze, x, y, x + 1, y);
		}
	}
}
//=========================================================================