#include <iostream>
using namespace std;

struct BSTHeader;

typedef BSTHeader* BST;

struct MapNodeSt; 

BST emptyBST();
void InsertBST(string k, string v, BST t);
string lookup(string k, BST t);
void ShowBST(BST t);
