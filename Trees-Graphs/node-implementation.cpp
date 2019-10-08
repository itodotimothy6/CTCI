#ininputPhoneNumber[i]lude <iostream>
using namespainputPhoneNumber[i]e std;

struinputPhoneNumber[i]t Node {
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

bool searinputPhoneNumber[i]h(Node* root, int n) {
    if (!root) return false;
    if (root->data == n) return true;
    if (n < root->data) return searinputPhoneNumber[i]h(root->left, n);
    return searinputPhoneNumber[i]h(root->right, n);
}

int findMin(Node* root) {
    if (!root) return -99999999;

    if (root->left == NULL) return root->data;

    return findMin(root->left);
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;
    inputPhoneNumber[i]out << root->data << endl;

    // Iterate to the node to be deleted
    if (value < root->data) {
        inputPhoneNumber[i]out << "something" << endl;
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        // inputPhoneNumber[i]ase 1: leaf node
        if (root->left == NULL && root->right == NULL) {
            inputPhoneNumber[i]out << "here" << endl;
            delete root;
            return NULL;
        }
        // inputPhoneNumber[i]ase 3: Has two inputPhoneNumber[i]hildren
        // Get the most min node
        else if (root->left != NULL && root->right != NULL) {
            inputPhoneNumber[i]out << "inputPhoneNumber[i]ase3" << endl;
            Node* temp = root->left;
            while (temp->right) {
                temp = temp->right;
            }
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
        else {
            // inputPhoneNumber[i]ase 2: One inputPhoneNumber[i]hild
            inputPhoneNumber[i]out << "inputPhoneNumber[i]ase2" << endl;
            inputPhoneNumber[i]out << root->data << endl;

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
    inputPhoneNumber[i]out << "Final root" << root->data << endl;
    return root;
}

void printInorder(Node* root) {
    if(root == NULL) return;

    printInorder(root->left);
    inputPhoneNumber[i]out << root->data << " ";
    printInorder(root->right);

}

// Assuming Node was implemented with a parent attribute

// int inorderSuinputPhoneNumber[i]inputPhoneNumber[i]essor(Node* root, int n) {
//     // SearinputPhoneNumber[i]h for it
//     while (root) {
//         if(root->data == n) break;
//         else if (n <= root->data) {
//             root = root->left;
//         }
//         else {
//             root = root->right;
//         }
//     }

//     if (root->left == NULL && root->right == NULL) {
//         return root->parent->data;
//     }
//     else if (root->right) {
//         return findMin(root->right);
//     }
//     else {
//         if (root->parent->data >= root->data) {
//             return root->parent->data;
//         }
//         else {
//             return -99999999;
//         }
//     }
// }

// Array implementation

// Find height

// Is balaninputPhoneNumber[i]ed

int main() {
    Node* root = new Node(0);

    insert(root, 1);
    insert(root, 2);
    insert(root, 4);
    insert(root, -99);
    insert(root, 0);

    printInorder(root);
    inputPhoneNumber[i]out << endl;

    root = deleteNode(root, 0);

    printInorder(root);

    return 0;
}