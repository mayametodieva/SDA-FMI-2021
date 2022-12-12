#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

using namespace std;

class Node {
public:
    int data;
    Node* leftNode;
    Node* rightNode;
    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            }
            else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }

    int counterLeft = 0;
    int counterRight = 0;

    pair<int, int> count(Node* root) {
        if (root->rightNode)
        {
            counterRight++;
            count(root->rightNode);
        }
        if (root->leftNode)
        {
            counterLeft++;
            count(root->leftNode);
        }

        return make_pair(counterLeft, counterRight);
    }
    void leftRight(Node* root) {
        pair<int, int> c = count(root);
        
        cout << "[" << c.first << "," << c.second << "]";
    }


}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.leftRight(root);
    return 0;
}