#include <iostream>

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node in BST
Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return new Node(key);
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to search for a node in BST
Node *search(Node *root, int key)
{
    if (root == nullptr || root->key == key)
    {
        return root;
    }

    if (key < root->key)
    {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Function to find the minimum value node in BST
Node *findMin(Node *root)
{
    while (root && root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

// Function to delete a node from BST
Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node *temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Inorder traversal of BST
void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    std::cout << "Inorder traversal of the BST: ";
    inorder(root);

    std::cout << "\nDeleting node 70\n";
    root = deleteNode(root, 70);
    std::cout << "Inorder traversal after deletion: ";
    inorder(root);

    return 0;
}

/*
The `deleteNode` function is responsible for removing a node with a specified key from a Binary Search Tree (BST).
The function handles several cases to ensure that the tree remains a valid BST after deletion.
Let's break down the function step by step.

### Function Signature
```cpp
Node* deleteNode(Node* root, int key);
```
- **Parameters**:
  - `root`: The root node of the BST or subtree where the deletion should occur.
  - `key`: The value of the node to be deleted.
- **Returns**: The new root of the BST (or subtree) after the deletion.

### Steps Involved in the `deleteNode` Function

1. **Base Case (Empty Tree)**:
   - If the tree is empty (`root == nullptr`), there is nothing to delete, so the function returns `nullptr`.
   ```cpp
   if (root == nullptr) {
       return root;
   }
   ```

2. **Recursive Search for the Node**:
   - The function recursively traverses the tree to find the node with the given `key`.
   - If the `key` is less than the root's key, it means the node to be deleted is in the left subtree.
   - If the `key` is greater than the root's key, it means the node to be deleted is in the right subtree.
   ```cpp
   if (key < root->key) {
       root->left = deleteNode(root->left, key);
   } else if (key > root->key) {
       root->right = deleteNode(root->right, key);
   }
   ```

3. **Node Found (root->key == key)**:
   - If the current node (`root`) is the node to be deleted, the function handles three possible cases:

   **Case 1: Node with No Children (Leaf Node)**:
   - If the node has no children (both left and right pointers are `nullptr`), simply delete the node and return `nullptr`.
   ```cpp
   if (root->left == nullptr && root->right == nullptr) {
       delete root;
       return nullptr;
   }
   ```

   **Case 2: Node with One Child**:
   - If the node has only one child, replace the node with its child and delete the node.
   - If the node has a left child but no right child, return the left child.
   - If the node has a right child but no left child, return the right child.
   ```cpp
   if (root->left == nullptr) {
       Node* temp = root->right;
       delete root;
       return temp;
   } else if (root->right == nullptr) {
       Node* temp = root->left;
       delete root;
       return temp;
   }
   ```

   **Case 3: Node with Two Children**:
   - If the node has two children, the function needs to find the node's in-order successor (the smallest node in the right subtree) to replace the current node.
   - The in-order successor ensures that the BST properties are maintained after deletion.
   - The node's key is replaced with the key of the in-order successor.
   - Then, the in-order successor (which is guaranteed to have at most one child) is deleted recursively.
   ```cpp
   Node* temp = findMin(root->right);
   root->key = temp->key;
   root->right = deleteNode(root->right, temp->key);
   ```

4. **Return the Modified Tree**:
   - Finally, the function returns the (possibly new) root of the subtree, ensuring that the entire tree structure remains valid after deletion.
   ```cpp
   return root;
   ```

### Example
Consider the following BST:

```
      50
     /  \
   30    70
   / \   / \
 20  40 60  80
```

- **Deleting Node 20** (Leaf Node):
  - The function finds node 20, deletes it, and returns `nullptr` to its parent node (30).
  - The BST remains balanced.

- **Deleting Node 30** (Node with One Child):
  - The function finds node 30, replaces it with node 40, and deletes node 30.
  - The subtree now has node 40 as the left child of 50.

- **Deleting Node 50** (Node with Two Children):
  - The function finds the in-order successor (node 60), replaces 50 with 60, and deletes node 60.
  - The tree remains valid.

### Conclusion
The `deleteNode` function ensures that the BST maintains its properties after a node is deleted.
It handles different cases depending on whether the node has zero, one, or two children,
and it carefully adjusts the tree structure to keep it balanced and correctly ordered.
*/