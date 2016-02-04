#include "Creature.h"
#include <iostream>
using namespace std;

Creature::Creature(int x, int y){
    this->path = new Node();
    currX = x;
    currY = y;
    this->path->x = currX;
    this->path->y = currY;
    this->path->next = NULL;
}

int Creature::getX(){
    return currX;
}

int Creature::getY(){
    return currY;
}

void Creature::push(int xx, int yy){
    Node* n = new Node();
    n->x = xx;
    n->y = yy;
    n->next = path;
    path = n;
}

void Creature::pop(){
    Node* deleteNode = new Node();
    deleteNode = path;
    path = path->next;
    delete deleteNode;
}

void Creature::printPath(){
    Node* temp = new Node();
    temp = path;
    while(temp != NULL){
        cout << " (" << temp->x << ", " << temp->y << ") " << endl;
        temp = temp->next;
    }
}
