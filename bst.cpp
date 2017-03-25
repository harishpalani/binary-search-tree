#include <iostream>

using namespace std;

struct BSTNode {
    int data;
    BSTNode *left;
    BSTNode *right;
}

// Function prototypes
BSTNode* create(int data);
BSTNode* insert(BSTNode* root, int data);
bool search(BSTNode* root, int data);
BSTNode* findMin(BSTNode* root);
BSTNode* remove(BSTNode* root, int data);

int main() {
    while (true) {
        // Get input through console
        char numbers[128];
        cout << "Enter the list of numbers:" << endl;
        cin.ignore();
        cin.getline(numbers, 128);
    }
}

// Create a new BST node
BSTNode* create(int data) {
    BSTNode* node = new BSTNode();
    
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

// Insert a node into the BST
BSTNode* insert(BSTNode* root, int data) {
    if (root == NULL) { // If null, create a new node
        root = create(data);
    } else if (data <= root->data) { // Else, insert data into the proper location on the tree
        root->left = insert(root->left, data);
    } else { 
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Search for a node in the BST
bool search(BSTNode* root, int data) {
    if (root = NULL) {
        return false;
    } else if (data == root->data) {
        return true;
    } else if (data <= root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Find the smallest node in BST
BSTNode* findMin(BSTNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node from the BST
BSTNode* remove(BSTNode* root, int data) {
    
}