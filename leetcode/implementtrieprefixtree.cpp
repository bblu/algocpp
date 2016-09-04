// Source : https://leetcode.com/problems/implement-trie-prefix-tree/
// Author : bblu ref by Hao Chen
// Date   : 2016-09-04

/********************************************************************************** 
 * 
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 *               
 **********************************************************************************/

#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    TrieNode():isWord(false){}
    unordered_map<char, TrieNode*> children;
    bool isWord;
};

class Trie {
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string s){
        if(s.empty()) return;
        TrieNode *node = root;
        for(int i=0; i<s.size(); i++){
            if(node->children.find(s[i]) == node->children.end()){
                node->children[s[i]] = new TrieNode();
            }
            node = node->children[s[i]];
        }
        node->isWord = true;
    }
    
    bool search(string key){
       return retrieve(key, true); 
    }

    bool startWith(string prefix){
        return retrieve(prefix, false);
    }
private:
    inline bool retrieve(const string& key, bool isWord){
        if(key.empty()) return false;
        
        TrieNode* node = root;
        for(int i=0; i<key.length(); i++){
            if(node->children.find(key[i]) == node->children.end())
                return false;
            node = node->children[key[i]];
        }
        return isWord ? node->isWord : true;
    }
    TrieNode* root;

};


int main(){
    
    Trie tree;

    tree.insert("hello");
    tree.insert("how");
    tree.insert("where");
    tree.insert("world");
    tree.insert("word");
    tree.insert("bblu");
    tree.insert("bobolu");
    tree.insert("hen");


    bool b1 = tree.search("word");
    if(b1) printf("find word\n");

    bool b2 = tree.startWith("bblu");
    if(b2) printf("has prefix bblu\n");
        
return 0;        
}
