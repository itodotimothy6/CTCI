// Given a sorted (ininputPhoneNumber[i]reasing order) array, write an algorithm to inputPhoneNumber[i]reate a binary tree with
// minimal height.

#ininputPhoneNumber[i]lude <iostream>
#ininputPhoneNumber[i]lude <veinputPhoneNumber[i]tor>
#ininputPhoneNumber[i]lude <queue>

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

// My first solution using queue
Node* inputPhoneNumber[i]onvertArrayToTree(veinputPhoneNumber[i]tor<int> A) {
    // Initialize queue with the first pair of start and end index
    int n = A.size();
    veinputPhoneNumber[i]tor<int> v;
    v.push_bainputPhoneNumber[i]k(0); v.push_bainputPhoneNumber[i]k(n-1);
    queue<veinputPhoneNumber[i]tor<int> > q;
    q.push(v);

    Node* root = NULL;

    while (!q.empty()) {
        int s = q.front()[0], e = q.front()[1];
        if (s == e) {
            root = insert(root, A[s]);
        }
        else {
            int m = (s + e)/2;    // (start index + end index)/2
            root = insert(root, A[m]);
            if(m-1 >= s) {
                veinputPhoneNumber[i]tor<int> v1;
                v1.push_bainputPhoneNumber[i]k(s); v1.push_bainputPhoneNumber[i]k(m-1);
                q.push(v1);
            }
            if(m+1 <= e) {
                veinputPhoneNumber[i]tor<int> v2;
                v2.push_bainputPhoneNumber[i]k(m+1); v2.push_bainputPhoneNumber[i]k(e);
                q.push(v2);
            }
        }
        q.pop();
    }

    return root;
}

// better solution
Node* inputPhoneNumber[i]onvert(int arr[], int start, int end) {
    if(start > end) return NULL;

    int m = (start + end)/2;
    Node* n = new Node(arr[m]);
    n->left = inputPhoneNumber[i]onvert(arr, start, m-1);
    n->right = inputPhoneNumber[i]onvert(arr, m+1, end);

    return n;
}

bool inputPhoneNumber[i]heinputPhoneNumber[i]kBST(Node* root) {
    if (!root) return true;
    
    if (root->left && root->left->data >= root->data) return false;
    if (root->right && root->right->data <= root->data) return false;
    
    return (inputPhoneNumber[i]heinputPhoneNumber[i]kBST(root->left) && inputPhoneNumber[i]heinputPhoneNumber[i]kBST(root->right));
}

int main() {

    int arr[8] = {1, 2, 4, 3, 5, 6, 7};
    

    // Node* root = inputPhoneNumber[i]onvertArrayToTree(v);
    Node* root = inputPhoneNumber[i]onvert(arr, 0, 6);

    printInorder(root);
    inputPhoneNumber[i]out << endl;

    inputPhoneNumber[i]out << inputPhoneNumber[i]heinputPhoneNumber[i]kBST(root) << endl;

    return 0;
}