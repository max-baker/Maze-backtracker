#include <iostream>
#include "Maze.h"
#include "Creature.h"

using namespace std;

bool goNorth(Maze &m, Creature &c, bool** &visit);
bool goSouth(Maze &m, Creature &c, bool** &visit);
bool goWest(Maze &m, Creature &c, bool** &visit);
bool goEast(Maze &m, Creature &c, bool** &visit);
bool traverse(Maze &m, Creature &c, bool** &visit);

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
bool traverse(Maze &m, Creature &c, bool** &visit){
    return false;
}

bool goNorth(Maze &m, Creature &c, bool** &visit){
    bool success =false;

    if(m.getMaze()[c.getX()][c.getY() - 1] != 'x' && !&visit[c.getX()][c.getY() - 1]){// no wall and not visited
            c.push(c.getX(),c.getY() - 1);
            visit[c.getX()][c.getY()] = true;
         if(c.getX() == m.getEndX() && c.getY() == m.getEndY() ){
                success = true;
                return success;
            }
            else{
                success = goNorth(m, c, visit);
                if(!success){
                    success = goWest(m, c, visit);
                    if(!success){
                        success = goEast(m, c, visit);
                        if(!success){
                            c.pop();
                            success = false;
                            goSouth(m, c, visit);
                        }
                    }
                }
            }
    }
    else{
        success = false;
    }
    return success;
}

bool goWest(Maze &m, Creature &c, bool** &visit){
    bool success =false;

    if(m.getMaze()[c.getX() + 1][c.getY()] != 'x' && !&visit[c.getX() + 1][c.getY()]){// no wall and not visited
            c.push(c.getX() + 1, c.getY());
            visit[c.getX()][c.getY()] = true;
         if(c.getX() == m.getEndX() && c.getY() == m.getEndY() ){
                success = true;
                return success;
            }
            else{
                success = goNorth(m, c, visit);
                if(!success){
                    success = goWest(m, c, visit);
                    if(!success){
                        success = goEast(m, c, visit);
                        if(!success){
                            c.pop();
                            success = false;
                            goSouth(m, c, visit);
                        }
                    }
                }
            }
    }
    else{
        success = false;
    }
    return success;
}

bool goEast(Maze &m, Creature &c, bool** &visit){
bool success =false;
    if(m.getMaze()[c.getX() - 1][c.getY()] != 'x' && !&visit[c.getX() - 1][c.getY()]){// no wall and not visited
            c.push(c.getX() - 1,c.getY());
            visit[c.getX()][c.getY()] = true;
         if(c.getX() == m.getEndX() && c.getY() == m.getEndY() ){
                success = true;
                return success;
            }
            else{
                success = goNorth(m, c, visit);
                if(!success){
                    success = goWest(m, c, visit);
                    if(!success){
                        success = goEast(m, c, visit);
                        if(!success){
                            c.pop();
                            success = false;
                            goSouth(m, c, visit);
                        }
                    }
                }
            }
    }
    else{
        success = false;
    }
    return success;
}

bool goSouth(Maze &m, Creature &c, bool** &visit){

     bool success =false;

    if(m.getMaze()[c.getX()][c.getY() + 1] != 'x' && !&visit[c.getX()][c.getY() + 1]){// no wall and not visited
            c.push(c.getX(),c.getY() + 1);
            visit[c.getX()][c.getY()] = true;
         if(c.getX() == m.getEndX() && c.getY() == m.getEndY() ){
                success = true;
                return success;
            }
            else{
                success = goNorth(m, c, visit);
                if(!success){
                    success = goWest(m, c, visit);
                    if(!success){
                        success = goEast(m, c, visit);
                        if(!success){
                            c.pop();
                            success = false;
                            goSouth(m, c, visit);
                        }
                    }
                }
            }
    }
    else{
        success = false;
    }
    return success;
}
