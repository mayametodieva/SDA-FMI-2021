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
       string s = "";

       string toStr(Node* root) {
            if (root != nullptr) {
            
                 toStr(root->rightNode);
                 toStr(root->leftNode);
                s+= to_string(root->data) + ";";
            }
            return s;
       }

    void print(Node* root) {
        string s = toStr(root);
        s.pop_back();
        cout << s;
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

    myTree.print(root);

    return 0;
}
