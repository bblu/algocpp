//
//  redblacktree.cpp
//  weekly
//
//  Created by lu wenbo on 2018/6/9.
//  Copyright © 2018 lu wenbo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

//namespace bblu{
    
enum Color{
    BLACK,
    RED
};

struct Node{
    int key;
    Node *parent;
    Node *left;
    Node *right;
    Color color;
    Node(Node* p,int k){
        parent = p;
        key = k;
        color = RED;
        left = NULL;
        right = NULL;
    }
    bool isRed(){
        return this->color == RED;
    }
    void setRed(){
        this->color = RED;
    }
    void setBlack(){
        this->color = BLACK;
    }
    bool hasParent(){
        return this->parent != NULL;
    }
    bool hasLeft(){
        return this->left != NULL;
    }
    bool hasRight(){
        return this->right != NULL;
    }
    bool operator < (Node *that){
        return this->key < that->key;
    }
};

class RedBlackTree{
    Node *root;
public:
    RedBlackTree(){
        root = NULL;
    }
    void insert(int key);
    void search(int key);
private:
    void insertfix(Node *node);
    void leftrotate(Node *node);
    void rightrotate(Node *node);
};

//} //bblu end namespace


















