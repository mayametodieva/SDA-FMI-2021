#include <iostream>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* add(Node* root, int data) {
    if (root == nullptr)
    {
        return new Node(data);
    }

    if (data < root->data)
    {
        root->left = add(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = add(root->right, data);
    }

    return root;
}


int getLevel(Node* root, int data, int level) {
    if (root == nullptr)
    {
        return 0;
    }

    if (root->data == data)
    {
        return level;
    }

    int next = getLevel(root->left, data, level + 1);
    if (next != 0)
    {
        return next;
    }

    next = getLevel(root->right, data, level + 1);
    return next;
}


void print_odd_layers(Node* root) {
    if (root == nullptr)
    {
        return;
    }

    std::queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        int level = getLevel(root, curr->data, 1);

        if (level % 2 != 0)
        {
            std::cout << curr->data << " ";
        }

        if (curr->left != nullptr) {
            q.push(curr->left);
        }

        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }
}


Node* getMinimumLeaf(Node* root) {
    while (root->left != nullptr)
    {
        root = root->left;
    }

    return root;
}

Node* remove(Node* root, int data) {
    if (root == nullptr)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = remove(root->left, data);
    }
    else if (data > root->data) {
        root->right = remove(root->right, data);
    }
    else
    {
        if (root->left == nullptr)
        {
            return root->right;
        }
        else if (root->right == nullptr) {
            return root->left;
        }

        Node* min = getMinimumLeaf(root->right);
        root->data = min->data;

        root->right = remove(root->right, min->data);
    }

    return root;
}

void print(Node* root) {
    if (root != nullptr)
    {
        std::cout << root->data << " ";
        print(root->left);
        print(root->right);
    }
}

int main() {
    int N = 0;
    std::cin >> N;

    Node* root = nullptr;
    for (int i = 0; i < N; i++) {
        std::string command;
        std::cin >> command;

        if (command == "add") {
            int value = 0;
            std::cin >> value;
            root = add(root, value);
        }
        else if (command == "remove") {
            int value = 0;
            std::cin >> value;
            root = remove(root, value);
        }
        else if (command == "print_odd_layers") {
            print_odd_layers(root);
        }
        else if (command == "print") {
            print(root);
        }
    }

    return 0;
}
