//
//  redblacktree.cpp
//  weekly
//
//  Created by lu wenbo on 2018/6/9.
//  Copyright © 2018 lu wenbo. All rights reserved.
//

#include <stdio.h>
#include <array>
#include <iostream>
#include "redblacktree.hpp"
using namespace std;

//namespace bblu{

void RedBlackTree::insert(int key){
    Node *n = new Node(NULL, key);
    Node *p = root, *q = NULL;
    cout << "|-insert:" << key << endl;
    if(root == NULL){
        root = n;
    }else{
        //find for the property node for insert key
        while(p != NULL){
            q = p;
            if(p < n){
                p = p->right;
                cout << "|--- p = p->right" << endl;
            }else{
                p = p->left;
                cout << "|--- p = p->left" << endl;
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
    Node *uncle;
    while(node->parent!=NULL && node->parent->color == RED){
        Node *gran = node->parent->parent;
        if(gran->left == node->parent){
            if(gran->right != NULL){
                uncle = gran->right;
                if(uncle->isRed()){
                    node->parent->setBlack();
                    uncle->setRed();
                    node = gran;
                }
            }else{
                if(node->parent->right == node){
                    node = node->parent;
                    leftrotate(node);
                }
                node->parent->setBlack();
                gran->setRed();
                rightrotate(gran);
            }
        }else{
            if(gran->left != NULL){
                uncle = gran->left;
                if(uncle->isRed()){
                    node->parent->setBlack();
                    uncle->setBlack();
                    gran->setRed();
                    node = gran;
                }
            }else{
                if(node->parent->left == node){
                    node = node->parent;
                    rightrotate(node);
                }
                node->parent->setBlack();
                gran->setRed();
                leftrotate(gran);
            }
        }
        root->setBlack();
    }
}
/*
 对4进行左旋，意味着将4变成一个原位置节点的左节点。
 ```
      8                               8
     / \                             / \
    4   12    =leftrotate(4)=>      6   12
   /  \                             / \
  2    6                           4   7
 / \                              / \
5   7                            2   5
 ```
 对比234树的操作把节点4升级成3NodeTree，上图旋转前的情况是选择把4提升为父节点，左旋转是换成了把6提成成父节点,这样理解的话右旋就是相反的操作。节点4左旋就是通过旋转操作把4变成6的左节点，。

      8
     / \
   4|6  12
  / | \
 2  5  7
 */
void RedBlackTree::leftrotate(Node *node){
    if(!node->hasRight())
        return;
    cout << "|------ leftrotate for " << node->key << endl;
    Node *r = node->right;
    if(r->hasLeft()){
        node->right = r->left;
        r->left->parent = node;
    }else{
        node->right = NULL;
    }
    if(node->hasParent())
        r->parent = node->parent;
    if(!node->hasParent()){
        root = r;
    }else{
        if(node->parent->hasLeft())
            node->parent->left = r;
        else
            node->parent->right = r;
    }
    r->left = node;
    node->parent = r;
}
void RedBlackTree::rightrotate(Node *node){
    if(!node->hasLeft()){
        return;
    }
    cout << "|------ rightrotate for " << node->key << endl;
    Node *l = node->left;
    if(l->hasRight()){
        node->left = l->right;
        l->right->parent = node;
    }else{
        node->left = NULL;
    }
    if(node->hasParent())
        l->parent = node->parent;
    if(!node->hasParent()){
        root = l;
    }else{
        if(node == node->parent->left)
            node->parent->left = l;
        else
            node->parent->right = l;
    }
    l->right = node;
    node->parent = l;
}

//} //bblu end namespace


int main(){
    array<int,7> keys = {8,4,6,12,2,5,7};
    RedBlackTree *tree = new RedBlackTree();
    
    for(const auto& key: keys)
        tree->insert(key);
    

    cout << "red-black tree:" << endl;
    return 0;
}















