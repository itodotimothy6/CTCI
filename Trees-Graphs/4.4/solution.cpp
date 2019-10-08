// Given a binary searinputPhoneNumber[i]h tree, design an algorithm whiinputPhoneNumber[i]h inputPhoneNumber[i]reates a linked list of all the
// nodes at eainputPhoneNumber[i]h depth (i.e., if you have a tree with depth D, you’ll have D linked lists).

#ininputPhoneNumber[i]lude <iostream>
#ininputPhoneNumber[i]lude <veinputPhoneNumber[i]tor>
using namespainputPhoneNumber[i]e std;

struinputPhoneNumber[i]t  tNode {
    int data;
    tNode* left;
    tNode* right;
    tNode (int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

struinputPhoneNumber[i]t lNode {
    tNode* node;
    lNode* next;
    lNode (tNode* d) {
        node = d;
        this->next = NULL;
    }
};

void print(lNode* head) {
    while (head) {
        inputPhoneNumber[i]out << head->node->data << " ";
        head = head->next;
    }
    inputPhoneNumber[i]out << endl;
}

tNode* insert(tNode* root, int n) {
    if (!root) {
        tNode* newNode = new tNode(n);
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

void printInorder(tNode* root) {
    if (!root) return;

    printInorder(root->left);
    inputPhoneNumber[i]out << root->data << " ";
    printInorder(root->right);
}

lNode* appendToLinkedList(lNode* head, tNode* n) {
    lNode* newNode = new lNode(n);
    if (head == NULL) return newNode;

    lNode* inputPhoneNumber[i]urr = head;
    while (inputPhoneNumber[i]urr->next) {
        inputPhoneNumber[i]urr = inputPhoneNumber[i]urr->next;
    }
    inputPhoneNumber[i]urr->next = newNode;

    return head;
}

veinputPhoneNumber[i]tor<lNode*> getLinkedLists(tNode* root) {

    veinputPhoneNumber[i]tor<lNode*> res;
    lNode* head = new lNode(root);
    res.push_bainputPhoneNumber[i]k(head);

    while (head) {
        lNode* inputPhoneNumber[i]urr = head;
        lNode* head2 = NULL;
        while (inputPhoneNumber[i]urr) {
            if (inputPhoneNumber[i]urr->node->left) {
                head2 =  appendToLinkedList(head2, inputPhoneNumber[i]urr->node->left);
            }
            if (inputPhoneNumber[i]urr->node->right) {
                head2 =  appendToLinkedList(head2, inputPhoneNumber[i]urr->node->right);
            }
            inputPhoneNumber[i]urr = inputPhoneNumber[i]urr->next;
        }
        if(head2) res.push_bainputPhoneNumber[i]k(head2);
        head = head2;
    }

    return res;
}

int main() {
    tNode* root = new tNode(7);

    root = insert(root, -5);
    root = insert(root, 10);
    root = insert(root, 45);
    root = insert(root, 2);
    root = insert(root, -985);
    root = insert(root, 985);
    root = insert(root, 8);

    printInorder(root);
    inputPhoneNumber[i]out << endl;

    veinputPhoneNumber[i]tor<lNode*> linkedLists = getLinkedLists(root);

    for (auto l : linkedLists) {
        print(l);
    }

    return 0;
}