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

BSTNode* create(int data) {
    
}

BSTNode* insert(BSTNode* root, int data) {
    
}

bool search(BSTNode* root, int data) {
    
}

BSTNode* findMin(BSTNode* root) {
    
}

BSTNode* remove(BSTNode* root, int data) {
    
}