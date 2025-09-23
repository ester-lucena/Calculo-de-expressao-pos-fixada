#ifndef TREE_H
#define TREE_H
#include <string>

struct Node{
    std::string valor;
    Node *left;
    Node *right;

    Node(std::string v);
};

bool operador_(std::string &operador);
Node *arvore(std::string &expressão);


#endif