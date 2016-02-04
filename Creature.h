#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

class Creature{
public:
    struct Node{
        int x,y;
        Node* next;
    };
    Creature(int x, int y);
    int getX();
    int getY();
    void push(int x, int y);
    void pop();
    void printPath();

private:
    char** position;
    int currX, currY;
    Node* path;
};



#endif // CREATURE_H_INCLUDED
