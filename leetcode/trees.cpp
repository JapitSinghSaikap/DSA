#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Structure definition for
// a node in a binary tree
struct Node {
    // Defining the value of
    // the node (integer data)
    int data;        
     // Reference pointer to
     // the left child node
    Node* left;      
    // Reference pointer to
    // the right child node
    Node* right;      

    // Method to initialize
    // the node with a value
    Node(int val) {
        // Set the value of the
        // node to the passed integer
        data = val;   
        // Initialize left and 
        //r ight pointers as NULL
        left = right = NULL;  
    }
};

void storeValuesInArray(Node* root, vector<int>& arr) {
    if (root == NULL) {
        return;
    }

    storeValuesInArray(root->left, arr);
    arr.push_back(root->data);
    storeValuesInArray(root->right, arr);
}

void makeBSTFromArray(Node* root, vector<int>& arr, int& index) {
    if (root == NULL) {
        return;
    }

    makeBSTFromArray(root->left, arr, index);
    root->data = arr[index++];
    makeBSTFromArray(root->right, arr, index);
}

Node* binaryTreeToBST(Node* root) {
    vector<int> arr;
    storeValuesInArray(root, arr);
    sort(arr.begin(), arr.end());
    int index = 0;
    makeBSTFromArray(root, arr, index);
    return root;
}

Node* createBSTFromInorder(vector<int>& inorder, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    Node* root = new Node(inorder[mid]);

    root->left = createBSTFromInorder(inorder, start, mid - 1);
    root->right = createBSTFromInorder(inorder, mid + 1, end);

    return root;
}

void printInorder(Node* root) {
    if (root == NULL) {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);

    cout << "Inorder before conversion: ";
    printInorder(root);

    binaryTreeToBST(root);

    cout << endl << "Inorder after conversion: ";
    printInorder(root);

    vector<int> inorder = {1, 2, 3, 4, 5, 6, 7};
    Node* bstRoot = createBSTFromInorder(inorder, 0, inorder.size() - 1);

    cout << endl << "BST created from inorder: ";
    printInorder(bstRoot);

    return 0;
}
