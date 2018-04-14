// Challenge 06: Lowest Common Ancestor

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctype.h>
#include <unistd.h>
#include <sstream>
using namespace std;

//Declare Node Struct
struct Node
{
    int data;
    Node * left;
    Node * right;

    ~Node()
    {
        delete left;
        delete right;
    }
};

//Create a function that returns a node with shared pointers
Node* newNode(int data)
{ 
    Node * node = new Node;
    node->data = data;
    node->right = nullptr;
    node->left = nullptr;
    return(node);
}
//Create the Tree with the given value and node
Node* createTree(Node * root, int value)
{
    if (root == nullptr) return newNode(value);

    if (value <= root->data)
        root -> left = createTree(root->left,value);
    else if (value > root->data)
        root->right = createTree(root->right, value);

    return root;
}
//Make sure it is a correct path and get a path for a given value
bool checkPath(Node *root, vector<int>& vec, int nodeElement)
{
    if(!root)
    {
        return false;
    }

    vec.push_back(root->data);

    if (root->data == nodeElement)
    {
        return true;
    }

    if ((checkPath(root->left, vec, nodeElement)) || (checkPath(root->right, vec, nodeElement)))
    {
        return true;
    }

    vec.pop_back();
    return false;
}

//Get the required path
void getPath(Node * root, vector<int>& nodePathOne, int nodeElementOne, vector<int>& nodePathTwo, int nodeElementTwo, vector<int>& lcaVector)
{    
    int LCA = 0;
    if(checkPath(root, nodePathOne, nodeElementOne) && checkPath(root, nodePathTwo, nodeElementTwo))
    {
        for (unsigned int i = 0; i < nodePathOne.size(); i++)
        {
            for(unsigned int j = 0; j < nodePathTwo.size(); j++)
            {
                if (nodePathOne[i] == nodePathTwo[j])
                {

                    LCA = nodePathOne[i];
                }
            }

        }
       lcaVector.push_back(LCA);
    }
}
// Main Execution
int main(int argc, char *argv[]) {

//variable declarations
    int nodeLength = 0;
    int nodeInput = 0;
    int nodeCount = 0;
    int searchLength = 0;
    bool keepGoing = true;
    vector<int> lcaVector;
//First loop to get the Node side   
    while(keepGoing)
    { 
        Node *root = NULL;             
        cin >> nodeLength;
        if (nodeLength != -1)
        {
            //Declarations
            vector<int> nodeHolder;
            vector<vector<int>> pairList;
            
            //Get Elements
            cin >> nodeInput;
            nodeHolder.push_back(nodeInput);
            root = createTree(root,nodeInput);
            nodeCount++;
            
            //Get numbers up the number the user inputed
            while(nodeCount < nodeLength)
            {
                cin >> nodeInput;
                nodeHolder.push_back(nodeInput);
                nodeCount++;
                createTree(root,nodeInput);
            }
            //Get the number of paits to search for!
            nodeCount = 0;
            cin >> searchLength;
            //Get the 2 numbers and push it into a vector of vectors
            for (int v = 0; v < searchLength; v++)
            {
                int firstNum, secondNum = 0;
                vector<int> nodePair;
                cin >> firstNum;
                cin >> secondNum;
                nodePair.push_back(firstNum);
                nodePair.push_back(secondNum);
                pairList.push_back(nodePair);
            }
            //Get the vector or paths for the two specified numbers
            for (unsigned int k = 0; k < pairList.size(); k++)
            {
                vector<int> nodePathOne;
                vector<int> nodePathTwo;
                getPath(root, nodePathOne, pairList[k][0], nodePathTwo, pairList[k][1],lcaVector);
            }
        }
        else{
            keepGoing = false;
            //Final Display
            for (unsigned int p = 0; p < lcaVector.size(); p++)
            {
                cout << lcaVector[p] << endl;
                if ((p == 2) || (p == 7) || (p == 15))
                {
                    cout << endl;
                }
            }
        }
        delete root;
    }
    return EXIT_SUCCESS;
}



// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
