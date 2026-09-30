#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* CreateTree()
{
    int value;

    cout << "Enter value (-1 for no node): ";
    cin >> value;

    if (value == -1)
        return NULL;

    Node* newNode = new Node;
    newNode->data = value;

    cout << "Enter left child of " << value << endl;
    newNode->left = CreateTree();

    cout << "Enter right child of " << value << endl;
    newNode->right = CreateTree();

    return newNode;
}

void Inorder(Node* root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(Node* root)
{
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = NULL;

    cout << "Create Binary Tree" << endl;
    root = CreateTree();

    cout << "\nInorder Traversal: ";
    Inorder(root);

    cout << "\nPreorder Traversal: ";
    Preorder(root);

    cout << "\nPostorder Traversal: ";
    Postorder(root);

    cout << endl;

    return 0;
}
