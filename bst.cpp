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
bool remove(BSTNode* &root, int data);
void visualize(BSTNode* root, int spaces);
BSTNode* findMin(BSTNode* root);
bool removalHelper(BSTNode* curr, int data);

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
    } else if (data == root->data) { // If curr node has the desired value, return true
        return true;
    } else if (data <= root->data) { // Else, search left or right depending on the desired value
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Delete a node from the BST
bool remove(BSTNode* &root, int data) {
    if (root == NULL) { return false; } // If null, there's nothing to delete
    if (root->data == data) {
        BSTNode* node;
        if (root->left == NULL && root->right == NULL) { // If surrounded by null, delete
            delete root;
            root = NULL;
        } else if (root->left == NULL) { // If only left is null, move root to the right & delete
            node = root->right;
            delete root;
            root = node;
        } else if (root->right == NULL) { // If only right is null, move root to the left & delete
            node = root->left;
            delete root;
            root = node;
        } else { // If neither is null, move root to the left
            node = root->left;
            if (node->right == NULL) {
                node->right = root->right;
                delete root;
                root = node;
            } else {
                while (node->right != NULL) { node = node->right; }
                int rootData = node->data;
                node->data = data;
                removalHelper(root->left, data);
                root->data = rootData;
            }
        }
        return true;
    } else {
        return removalHelper(root, data);
    }
}

// Visualize BST (sideways tree)
void visualize(BSTNode* root, int spaces) {
    if (root == NULL) { return; }
 
    // Set distance between levels
    int c = 3;
    spaces += c;
 
    // Right child
    visualize(root->right, spaces);
 
    // Print space + curr node
    for (int i = c; i < spaces; i++) { printf(" "); }
    printf("%d\n", root->data);
 
    // Left child
    visualize(root->left, spaces);
}

// Find the smallest node in BST
BSTNode* findMin(BSTNode* root) {
    // Move left until you find the left-most node
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Recursive helper for removal
bool removalHelper(BSTNode* curr, int data) {
    BSTNode* node;
    if (curr->data <= data) {
        if (curr->right == NULL) { return false; }
        if (curr->right->data == data) {
            if (curr->right->left == NULL && curr->right->right == NULL) {
                delete curr->right;
                curr->right = NULL;
                return true;
            } else if (curr->right->right == NULL) {
                node = curr->right->left;
                delete curr->right;
                curr->right = node;
                return true;
            } else if (curr->right->left == NULL) {
                node = curr->right->right;
                delete curr->right;
                curr->right = node;
                return true;
            } else { // Neither are NULL
                node = curr->right->left;
                if (node->right == NULL) {
                    node->right = curr->right->right;
                    delete curr->right;
                    curr->right = node;
                } else {
                    while (node->right != NULL) {
                        node = node->right;
                    }
                    int nodeData = node->data;
                    node->data = data;
                    removalHelper(curr->right->left, data);
                    curr->right->data = nodeData;
                }
                return true;
            }
        } else { return removalHelper(curr->right, data); }
    } else {
        if (curr->left == NULL) { return false; }
        if (curr->left->data == data) {
            if (curr->left->left == NULL && curr->left->right == NULL) {
                delete curr->left;
                curr->left = NULL;
                return true;
            } else if (curr->left->right == NULL) {
                node = curr->left->left;
                delete curr->left;
                curr->left = node;
                return true;
            } else if (curr->left->left == NULL) {
                node = curr->left->right;
                delete curr->left;
                curr->left = node;
                return true;
            } else { // Neither are NULL
                node = curr->left->left;
                if (node->right == NULL) {
                    node->right = curr->left->right;
                    delete curr->left;
                    curr->left = node;
                } else {
                    while (node->right != NULL) { node = node->right; }
                    int nodeData = node->data;
                    node->data = data;
                    removalHelper(curr->left->left, data);
                    curr->left->data = nodeData;
                }
                return true;
            }
        } else { return removalHelper(curr->left, data); }
    }
}