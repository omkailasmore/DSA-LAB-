#include <iostream>
#include <queue>
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

void LevelOrder(Node* root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}

Node* CopyTree(Node* root)
{
    if (root == NULL)
        return NULL;

    Node* newNode = new Node;
    newNode->data = root->data;

    newNode->left = CopyTree(root->left);
    newNode->right = CopyTree(root->right);

    return newNode;
}

int Height(Node* root)
{
    if (root == NULL)
        return -1;

    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;

    return rightHeight + 1;
}

void PrintLeafNodes(Node* root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }

    PrintLeafNodes(root->left);
    PrintLeafNodes(root->right);
}

int main()
{
    Node* root = NULL;
    Node* copyRoot = NULL;

    int choice;

    do
    {
        cout << "\n========================================";
        cout << "\n        BINARY SEARCH TREE MENU";
        cout << "\n========================================";
        cout << "\n1. Insert Node";
        cout << "\n2. Display Original BST (Level Order)";
        cout << "\n3. Copy BST";
        cout << "\n4. Display Copied BST (Level Order)";
        cout << "\n5. Find Height of BST";
        cout << "\n6. Print Leaf Nodes";
        cout << "\n7. Exit";
        cout << "\n========================================";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int value;

                cout << "Enter value: ";
                cin >> value;

                root = Insert(root, value);
                break;
            }

            case 2:
                cout << "Original BST (Level Order): ";
                LevelOrder(root);
                cout << endl;
                break;

            case 3:
                if (root == NULL)
                {
                    cout << "Tree is Empty. Nothing to copy." << endl;
                }
                else
                {
                    copyRoot = CopyTree(root);
                    cout << "BST Copied Successfully." << endl;
                }
                break;

            case 4:
                cout << "Copied BST (Level Order): ";
                LevelOrder(copyRoot);
                cout << endl;
                break;

            case 5:
                cout << "Height of BST = " << Height(root) << endl;
                break;

            case 6:
                cout << "Leaf Nodes: ";
                PrintLeafNodes(root);
                cout << endl;
                break;

            case 7:
                cout << "Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid Choice." << endl;
        }

    } while (choice != 7);

    return 0;
}
