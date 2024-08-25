#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(Node *node)
{
    if (node == nullptr)
        return;

    cout << node->data << " ";      // Visit root
    preorderTraversal(node->left);  // Traverse left subtree
    preorderTraversal(node->right); // Traverse right subtree
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(Node *node)
{
    if (node == nullptr)
        return;

    inorderTraversal(node->left);  // Traverse left subtree
    cout << node->data << " ";     // Visit root
    inorderTraversal(node->right); // Traverse right subtree
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(Node *node)
{
    if (node == nullptr)
        return;

    postorderTraversal(node->left);  // Traverse left subtree
    postorderTraversal(node->right); // Traverse right subtree
    cout << node->data << " ";       // Visit root
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
}

int main()
{

    cout << "Creating a sample binary tree:" << endl;
    cout << "     1" << endl;
    cout << "    /  \\ " << endl;
    cout << "   2    3 " << endl;
    cout << "  / \\  / \\ " << endl;
    cout << " 4   5 6  7 " << endl;

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Height of the tree = " << height(root) << endl;
    cout << "Nodes visited in Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Nodes visited in Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Nodes visited in Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
