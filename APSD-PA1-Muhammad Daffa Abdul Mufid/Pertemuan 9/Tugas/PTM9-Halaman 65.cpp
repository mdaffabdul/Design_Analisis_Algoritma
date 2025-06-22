#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Tree {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void preOrder(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node* node) {
        if (node == NULL) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void postOrder(Node* node) {
        if (node == NULL) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

public:
    Tree() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void preOrder() {
        preOrder(root);
    }

    void inOrder() {
        inOrder(root);
    }

    void postOrder() {
        postOrder(root);
    }
};

int main() {
    Tree myTree;

    int numbers[] = {12, 16, 20, 24, 32};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < n; ++i) {
        myTree.insert(numbers[i]);
    }

    cout << "Bilangan yang diinput: 12, 16, 20, 24, 32\n";
    cout << "==========================================\n";

    cout << "Urutan Pre-order  (Root-Left-Right): ";
    myTree.preOrder();
    cout << endl;

    cout << "Urutan In-order   (Left-Root-Right): ";
    myTree.inOrder();
    cout << endl;

    cout << "Urutan Post-order (Left-Right-Root): ";
    myTree.postOrder();
    cout << endl;

    return 0;
}
