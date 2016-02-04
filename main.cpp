#include <iostream>
#include "Maze.h"
#include "Creature.h"

using namespace std;

bool goNorth(int x, int y, Maze m, Creature c);
bool goSouth(int x, int y, Maze m, Creature c);
bool goWest(int x, int y, Maze m, Creature c);
bool goEast(int x, int y, Maze m, Creature c);
bool traverse(Maze maze, Creature creature, bool** &visit);

int main()
{
    Maze m("maze_complex.txt");
    m.printMaze();
    Creature c(m.getStartX(), m.getStartY());

    /**
    * init the visited paths table with a true for visited, and false for not
    * true = visited
    * false = not visited
    */

    bool** visitedBlock;
    visitedBlock = new bool*[m.getWidth()+1];
    for(int i = 0; i < m.getWidth()+1; i++){
        visitedBlock[i] = new bool[m.getLength()];
    }
    for(int i = 0; i < m.getWidth()+1; i++){
        for(int j = 0; j < m.getLength()+1; j++){
            visitedBlock[i][j] = false;
        }
    }

    return 0;
}
bool traverse(Maze maze, Creature creature, bool** &visit){

return false;
}
