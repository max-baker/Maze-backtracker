#include "Maze.h"


Maze::Maze(string filename){
    ifstream file(filename.c_str());
    while(file >> width >> length >> endX >> endY >> startX >> startY){
        maze = new char*[width+1];
        for(int i = 0; i < width+1; i++){
            maze[i] = new char[length];
        }
            for(int i = 0; i < width + 1; i++){
                for(int j = 0; j < length + 1; j++){
                    file.get(maze[i][j]);
                }
            }
    }
}
Maze::~Maze(){

    for(int i=0;i<width+1;i++){
        delete[]maze[i]; //this part was allocated with new[], so use delete[]
    }
    delete[] maze;
}

int Maze::getWidth(){
    return width;
}
int Maze::getLength(){
    return length;
}
void Maze::printMaze(){
     for(int i = 0; i <= width; i++){
        for(int j = 0; j <= length; j++){
            cout << maze[i][j];
        }
    }
}

int Maze::getStartX(){
    return startX;
}
int Maze::getStartY(){
    return startY;
}

int Maze::getEndX(){
    return endX;
}

int Maze::getEndY(){
    return endY;
}

char** Maze::getMaze(){
    return maze;
}
