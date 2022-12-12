#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Tree {
public:
    Tree() : value(0), left(nullptr), right(nullptr) {}
    Tree(long long value) : value(value), left(nullptr), right(nullptr) {}

    void inorder(Tree* node, vector<long long>& els);
    void printByLevels(Tree* root);

    Tree* insert(Tree* root, long long value);
    Tree* erase(Tree* root, long long value);
private:
    long long value;
    Tree* left, * right;
    Tree* minNode(Tree* root);
};

void Tree::inorder(Tree* node, vector<long long>& els) 
{
    if (node != nullptr)
    {
        inorder(node->left, els);
        els.push_back(node->value);
        inorder(node->right, els);
    }
}

void Tree::printByLevels(Tree* root)
{
    if (root == nullptr) {
        return;
    }

    Tree* curr;
    queue<Tree*> trav;

    trav.push(root);
    trav.push(nullptr);

    while (trav.size()) {
        curr = trav.front();
        trav.pop();

        if (curr == nullptr)
        {
            trav.push(nullptr);
        }
        else
        {
            if (curr->left)
            {
                trav.push(curr->left);
            }
            if (curr->right)
            {
                trav.push(curr->right);
            }
            cout << curr->value << " ";
        }
    }
}

Tree* Tree::insert(Tree* node, long long value)
{
    if (node == nullptr)
    {
        return new Tree(value);
    }
    if (value > node->value) {
        node->right = insert(node->right, value);
    }
    else if (value < node->value) {
        node->left = insert(node->left, value);
    }
    return node;
}

Tree* Tree::erase(Tree* node, long long value)
{
    if (node == nullptr) {
        return node;
    }

    if (value > node->value) {
        node->right = erase(node->right, value);
    }
    else if (value < node->value) {
        node->left = erase(node->left, value);
    }
    else {
        if (node->right == nullptr)
        {
            Tree* curr = node->left;
            delete(node);
            return curr;
        }
        else if (node->left == nullptr) {
            Tree* curr = node->right;
            delete(node);
            return curr;
        }

        Tree* curr = minNode(node->right);

        node->value = curr->value;

        node->right = erase(node->right, curr->value);
    }
    return node;
}

Tree* Tree::minNode(Tree* node)
{
    Tree* curr = node;

    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}


int main() {
    long long N, K;

    cin >> N >> K;

    Tree tree, * root = nullptr;
    long long val;

    cin >> val;

    root = tree.insert(root, val);

    for (long long i = 1; i < N; i++)
    {
        long long val;

        cin >> val;

        tree.insert(root, val);
    }

    vector<long long> els;

    tree.inorder(root, els);

    long long valToErase = 0;

    valToErase = els[els.size() - K];

    tree.erase(root, valToErase);

    tree.printByLevels(root);

    return 0;
}