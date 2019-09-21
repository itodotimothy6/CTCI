#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insert(Node* root, int n) {
    if(!root) {
        Node* newNode = new Node(n);
        root = newNode;
    }
    else if(root->data >= n){
        root->left = insert(root->left, n);
    }
    else {
        root->right = insert(root->right, n);
    }
    return root;
}

bool search(Node* root, int n) {
    if (!root) return false;
    if (root->data == n) return true;
    if (n < root->data) return search(root->left, n);
    return search(root->right, n);
}

int findMin(Node* root) {
    if (!root) return -99999999;

    if (root->left == NULL) return root->data;

    return findMin(root->left);
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;
    cout << root->data << endl;

    // Iterate to the node to be deleted
    if (value < root->data) {
        cout << "something" << endl;
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        // Case 1: leaf node
        if (root->left == NULL && root->right == NULL) {
            cout << "here" << endl;
            delete root;
            return NULL;
        }
        // Case 3: Has two children
        // Get the most min node
        else if (root->left != NULL && root->right != NULL) {
            cout << "case3" << endl;
            Node* temp = root->left;
            while (temp->right) {
                temp = temp->right;
            }
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
        else {
            // Case 2: One Child
            cout << "case2" << endl;
            cout << root->data << endl;

            if (root->left) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            if (root->right) {
                Node* temp = root->right;
                delete root;
                return temp;
            } 
        }
        
    }
    cout << "Final root" << root->data << endl;
    return root;
}

void printInorder(Node* root) {
    if(root == NULL) return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);

}

// Array implementation

// Find height

// Is balanced

int main() {
    Node* root = new Node(0);

    insert(root, 1);
    insert(root, 2);
    insert(root, 4);
    insert(root, -99);
    insert(root, 0);

    printInorder(root);
    cout << endl;

    root = deleteNode(root, 0);

    printInorder(root);

    return 0;
}