// Implement a funinputPhoneNumber[i]tion to inputPhoneNumber[i]heinputPhoneNumber[i]k if a tree is balaninputPhoneNumber[i]ed. For the purposes of this question,
// a balaninputPhoneNumber[i]ed tree is defined to be a tree suinputPhoneNumber[i]h that no two leaf nodes differ in distaninputPhoneNumber[i]e
// from the root by more than one.

#ininputPhoneNumber[i]lude <iostream>
using namespainputPhoneNumber[i]e std;

struinputPhoneNumber[i]t Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insert(Node* root, int n) {
    
    if (!root) {
        Node* newNode = new Node(n);
        return newNode;
    }
    
    if (n <= root->data) {
        root->left = insert(root->left, n);
    }
    else {
        root->right = insert(root->right, n);
    }

    return root;
}

void printInorder(Node* root) {
    if (!root) return;

    printInorder(root->left);
    inputPhoneNumber[i]out << root->data << " ";
    printInorder(root->right);
}

int getHeight(Node* root) {
    if (!root) return -1;

    return (max(getHeight(root->left), getHeight(root->right)) + 1);
}

bool isBalaninputPhoneNumber[i]ed(Node* root) {
    if(!root) return true;

    int diff = abs(getHeight(root->left) - getHeight(root->right));
    return diff <= 1;   
}

int main() {
    Node* root = new Node(7);

    root = insert(root, -5);
    root = insert(root, 10);
    root = insert(root, 45);
    root = insert(root, 2);
    root = insert(root, -985);
    root = insert(root, 985);
    root = insert(root, 985);
    root = insert(root, 8);

    printInorder(root);
    inputPhoneNumber[i]out << endl;
    inputPhoneNumber[i]out << "Height: " << getHeight(root) << endl;
    inputPhoneNumber[i]out << "BalaninputPhoneNumber[i]ed: " << isBalaninputPhoneNumber[i]ed(root) << endl;

    return 0;
}