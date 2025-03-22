//
// Created by Pratik Giri on 22-03-2025.
//

#include <iostream>
using namespace std;

// Define a Node structure
struct Node
{
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert nodes dynamically
Node* insertNode(Node* root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    // Insert in left if value is smaller, else insert in right
    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Inorder traversal (Left, Root, Right)
void inorderTraversal(Node* root)
{
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    Node* root = nullptr;

    // Insert nodes dynamically
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    cout << "Inorder Traversal of Tree: ";
    inorderTraversal(root);

    return 0;
}
