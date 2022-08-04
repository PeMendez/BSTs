#include <iostream>
using namespace std;
#include "BST.h"

int main() {
    BST t = emptyBST();
    InsertBST("L", "1", t);
    InsertBST("G", "2", t);
    InsertBST("J", "5", t);
    InsertBST("K", "11", t);
    InsertBST("D", "4", t);
    InsertBST("S", "3", t);
    InsertBST("P", "6", t);
    InsertBST("M", "12", t);
    InsertBST("B", "8", t);
    InsertBST("E", "4", t);
    InsertBST("V", "7", t);
    InsertBST("U", "14", t);
    InsertBST("Y", "15", t);
    ShowBST(t);
    InsertBST("S", "22", t);
    ShowBST(t);
    cout << "el valor para la key M es: " << lookup("M", t) << endl ; 
    cout << "el valor para la key B es: " << lookup("B", t) << endl ; 
    cout << "el valor para la key H es: " << lookup("H", t) << endl ; 
}