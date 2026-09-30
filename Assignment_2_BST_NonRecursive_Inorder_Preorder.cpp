#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* Insert(Node* root, int value)
{
    if (root == NULL)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (value < root->data)
        root->left = Insert(root->left, value);
    else if (value > root->data)
        root->right = Insert(root->right, value);
    else
        cout << "Duplicate value not inserted." << endl;

    return root;
}

Node* CreateBST()
{
    Node* root = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;

        root = Insert(root, value);
    }

    return root;
}

void InorderNonRecursive(Node* root)
{
    Node* stack[100];
    int top = -1;
    Node* current = root;

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];

        cout << current->data << " ";

        current = current->right;
    }
}

void PreorderNonRecursive(Node* root)
{
    if (root == NULL)
        return;

    Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top != -1)
    {
        Node* current = stack[top--];

        cout << current->data << " ";

        // Push right first so that left is processed first.
        if (current->right != NULL)
            stack[++top] = current->right;

        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

int main()
{
    Node* root = CreateBST();

    cout << "\nNon-Recursive Inorder Traversal: ";
    InorderNonRecursive(root);

    cout << "\nNon-Recursive Preorder Traversal: ";
    PreorderNonRecursive(root);

    cout << endl;

    return 0;
}
