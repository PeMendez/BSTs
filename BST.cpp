#include <iostream>
#include <string.h>
#include <stdexcept>
#include "BST.h"
using namespace std;

struct MapNodeSt {
    string key;
    string value;
    MapNodeSt* left;
    MapNodeSt* right;
};

struct BSTHeader {
    MapNodeSt* root;
};

BST emptyBST() {
    BSTHeader* t = new BSTHeader;
    t->root = NULL;
    return t;
}

string lookup(string k, BST t) {
    MapNodeSt* nodoActual = t->root; 
    while((nodoActual != NULL) && (k != nodoActual->key)){
        if(k < nodoActual->key){
            nodoActual = nodoActual->left; 
        } else {
            nodoActual = nodoActual->right; 
        }
    }
    if (nodoActual != NULL){
        return nodoActual->value; 
    } else {
        throw std::domain_error( "ERROR: la key buscada no pertenece al BST dado"); 
    }
}

void InsertBST(string k, string v, BST t) {
    MapNodeSt* newMapNode = new MapNodeSt;  
    newMapNode->key = k; 
    newMapNode->value = v; 
    newMapNode->right = NULL; 
    newMapNode->left = NULL;
    if (t->root == NULL){
        t->root = newMapNode;  
    } else {
        MapNodeSt* actual = t->root; 
        MapNodeSt* anterior = NULL; 
        while((actual != NULL) && (k != actual->key)){
                anterior = actual;
                if(k < actual->key){
                    actual = actual->left; 
                } else {
                    actual = actual->right; 
                }
        }
        if (actual != NULL){
            actual->value = v;
            delete newMapNode;  
        } else if(k < anterior->key){
            anterior->left = newMapNode; 
        } else {
            anterior->right = newMapNode; 
        } 
    }   
}

void Indent(int n) {
    for(int i=0; i<n; i++) cout << " ";
}

void ShowTreeAt(MapNodeSt* t, int i) {
    if (t==NULL) return;
    if (t->right!=NULL){ 
        ShowTreeAt(t->right, i+2); 
    }
        Indent(i); cout << " " << t->key << " := "<< t-> value << endl;
    if (t->left!=NULL) { 
        ShowTreeAt(t->left, i+2); 
    }
}

void ShowBST(BST t) {
    cout << "Tree(" << endl;
    ShowTreeAt(t->root, 5);
    cout << " )" << endl;
}
