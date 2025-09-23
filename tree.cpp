#include "tree.h"
#include <stack>
#include <sstream>

using namespace std;

Node::Node(string valor){
    this -> valor = valor;
    left = nullptr;
    right = nullptr;
}

bool operador(string &operador){
    return operador == "+" || operador == "-" || operador == "*" || operador == "/";
}

Node *arvore(string &expressão){
    stack<Node*> stk;
    stringstream str(expressão);
    string operador;

    while(str >> expressão){
        if(!operador_(operador)){
            stk.push(new Node(expressão));
        } else{
            if(stk.size() < 2){
                throw runtime_error("expressão inválida!");
            } 

            Node *right = stk.top(); 
            stk.pop();

            Node *left = stk.top();
            stk.pop();

            Node *opNode = new Node(operador);
            opNode -> left = left;
            opNode -> right = right;
            stk.push(opNode); 
        }
    }
    if(stk.size() != 1){
        throw runtime_error("expressão inválida!");
    }

    return stk.top();
}