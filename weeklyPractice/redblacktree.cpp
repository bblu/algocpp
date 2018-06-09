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
};

void RedBlackTree::insert(int key){
    Node *n = new Node(NULL, key);
    Node *p = root, *q = NULL;
    
    if(root == NULL){
        root = n;
    }else{
        //find for the property node for insert key
        while(p != NULL){
            q = p;
            if(p < n){
                p = p->right;
            
            }else{
                p = p->left;
                
            }
        }
        n->parent = q;
        if(q < n){
            q->right = n;
        }else{
            q->left = n;
        }
    }
    insertfix(n);
}
void RedBlackTree::insertfix(Node *node){
    if(root == node){
        node->color = BLACK;
        return;
    }
    
}
//} //bblu end namespace



