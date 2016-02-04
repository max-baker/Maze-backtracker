#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;

class Maze{

public:
    Maze(string filename);
    ~Maze();
    int getWidth();
    int getLength();
    void printMaze();
    int getStartX();
    int getStartY();
    int getEndX();
    int getEndY();
    char** getMaze();

private:
    int startX, startY, endX, endY, width, length;
    char** maze;
};


#endif // MAZE_H_INCLUDED
