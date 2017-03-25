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
    if (root = NULL) { // If null, there's nothing to search
        return false;
    } else if (data == root->data) { // If current node has the desired value, return true
        return true;
    } else if (data <= root->data) { // Else, search left or right depending on the desired value
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Find the smallest node in BST
BSTNode* findMin(BSTNode* root) {
    // Move left until you find the left-most node
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node from the BST
BSTNode* remove(BSTNode* root, int data) {
    if (root = NULL) { // If null, there's nothing to delete
        return root;
    } else if (data < root->data) { // Move left or right depending on the desired value
        root->left = remove(root->left, data);
    } else if (data > root->data) {
        root->right = remove(root->right, data);
    } else { // data == root->data
        if ((root->left == NULL) && (root->right == NULL))) { // If surrounded by null, delete
            delete root;
            root = NULL;
        } else if (root->left == NULL) { // If only left is null, move root to the right & delete
            BSTNode* node = root;
            root = root->right;
            delete node;
        } else if (root->right == NULL) { // If only right is null, move root to the left & delete
            BSTNode* node = root;
            root = root->left;
            delete node;
        } else {
            BSTNode* min = findMin(root->right);
            root->data = min->data;
            root->right = remove(root->right, min->data);
        }
    }
    
    return root;
}