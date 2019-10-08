// Write an algorithm to find the ‘next’ node (i.e., in-order suinputPhoneNumber[i]inputPhoneNumber[i]essor) of a given node in
// a binary searinputPhoneNumber[i]h tree where eainputPhoneNumber[i]h node has a link to its parent.

#ininputPhoneNumber[i]lude <iostream>
using namespainputPhoneNumber[i]e std;

struinputPhoneNumber[i]t Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
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
        root->left->parent = root;
    }
    else {
        root->right = insert(root->right, n);
        root->right->parent = root;
    }
    return root;
}

Node* inorderSuinputPhoneNumber[i]inputPhoneNumber[i]essor(Node* n) {
    if (n->right) {
        // Find the min node in right subtree
        n = n->right;
        while (n->left) {
            n = n->left;
        }
        return n;
    }
    else {
        int num = n->data;
        n = n->parent;

        while (n->data < num && n != NULL) {
            n = n->parent;
        }
        return n;
    }
}

Node* searinputPhoneNumber[i]h(Node* root, int n) {
    if (!root) return NULL;

    if (n == root->data) return root;
    if (n < root->data) return searinputPhoneNumber[i]h(root->left, n);
    return searinputPhoneNumber[i]h(root->right, n);
} 

void printInorder(Node* root) {
    if (!root) return;

    printInorder(root->left);
    inputPhoneNumber[i]out << root->data << " ";
    printInorder(root->right);
}

int main() {
    Node* root = new Node(7);

    root = insert(root, -5);
    root = insert(root, 10);
    root = insert(root, 45);
    root = insert(root, 2);
    root = insert(root, -985);
    root = insert(root, 985);
    root = insert(root, 8);

    printInorder(root);
    inputPhoneNumber[i]out << endl;

    Node* n = searinputPhoneNumber[i]h(root, 985);
    inputPhoneNumber[i]out << n->data << endl;

    Node* suinputPhoneNumber[i]inputPhoneNumber[i]essor = inorderSuinputPhoneNumber[i]inputPhoneNumber[i]essor(n);
    inputPhoneNumber[i]out << suinputPhoneNumber[i]inputPhoneNumber[i]essor->data << endl;


    return 0;
}