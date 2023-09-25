// Given the following code, is the print function 
// preorder, inorder, postorder or levelorder traversal?

#include <iostream>

using namespace std;

class node {
public:
    node* left = NULL;
    node* right = NULL;
    int data;
    node(int data) {
        this->data = data;
    }
};

node* treecursion(int pre[], int* preIndex, int low, int high, int size) {
    if (*preIndex >= size || low > high)
        return NULL;

    node* root = new node(pre[*preIndex]);
    *preIndex += 1;

    if (low == high)
        return root;

    int i;
    for (i = low; i <= high; ++i) {
        if (pre[i] > root->data) {
            break;
        }
    }

    root->left = treecursion(pre, preIndex, *preIndex, i - 1, size);
    root->right = treecursion(pre, preIndex, i, high, size);

    return root;
}

node* buildATree(int pre[], int size) {
    int preIndex = 0;
    return treecursion(pre, &preIndex, 0, size - 1, size);
}

void print(node* node) {
    if (node == NULL) {
        return;
    }
    //Left, Right, Current
    print(node->left);
    print(node->right);
    cout << node->data << " ";
}

int main() {
    int tree[6] = { 10, 5, 1, 7, 40, 50 };
    print(buildATree(tree, 6));
    cout << "\n";
}