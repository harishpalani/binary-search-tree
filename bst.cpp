#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>

using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

// Function prototypes
BSTNode* create(int data);
BSTNode* insert(BSTNode* root, int data);
bool search(BSTNode* root, int data);
BSTNode* findMin(BSTNode* root);
BSTNode* remove(BSTNode* root, int data);
void visualize(BSTNode* root, int spaces);

int main() {
    cout << "Binary Search Tree" << "\n" << "Created by Harish Palani, March 2017" << "\n" << endl;
    BSTNode* root = NULL;
    
    // Get input list
    cout << "Enter your list, separated by spaces:" << endl;
    string input;
    getline(cin, input);
    stringstream ss(input);
    
    // Load input list into vector
    vector<int> list;
    int i;
    while (ss >> i) {
        list.push_back(i);
        if (ss.peek() == ' ') {
            ss.ignore();
        }
    }
    
    // Insert vector contents into BST
    for (i = 0; i < list.size(); i++) {
        root = insert(root, list.at(i));
    }
    
    while (true) {
        int n;
        char response;
        cout << "\n1 | Print out tree\n2 | Insert a number\n3 | Remove a number\nq | quit" << endl;
        cin >> response;
        
        if (response == '1') {
            visualize(root, 0);
        } else if (response == '2') {
            cout << "Number to insert: ";
            cin >> n;
            cout << endl;
            insert(root, n);
            visualize(root, 0);
        } else if (response == '3') {
            cout << "Number to delete: ";
            cin >> n;
            cout << endl;
            if (remove(root, n)) { visualize(root, 0); }
            else { cout << "Sorry! Number could not be found." << endl; }
        } else {
            break;
        }
    }
    
    return 0;
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
    if (root == NULL) { // If null, there's nothing to search
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
    if (root == NULL) { // If null, there's nothing to delete
        return root;
    } else if (data < root->data) { // Move left or right depending on the desired value
        root->left = remove(root->left, data);
    } else if (data > root->data) {
        root->right = remove(root->right, data);
    } else { // data == root->data
        if (root->left == NULL && root->right == NULL) { // If surrounded by null, delete
            delete root;
            root = NULL;
        } else if (root->left == NULL) { // If only left is null, move root to the right & delete
            BSTNode* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) { // If only right is null, move root to the left & delete
            BSTNode* temp = root;
            root = root->left;
            delete temp;
        } else {
            BSTNode* min = findMin(root->right);
            root->data = min->data;
            root->right = remove(root->right, min->data);
        }
    }
    return root;
}

// Visualize BST (sideways tree)
void visualize(BSTNode* root, int spaces) {
    if (root == NULL) { return; }
 
    // Set distance between levels
    int c = 3;
    spaces += c;
 
    // Right child
    visualize(root->right, spaces);
 
    // Print space + current node
    for (int i = c; i < spaces; i++) { printf(" "); }
    printf("%d\n", root->data);
 
    // Left child
    visualize(root->left, spaces);
}