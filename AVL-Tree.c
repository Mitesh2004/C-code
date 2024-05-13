#include <stdio.h>
#include <stdlib.h>

// Structure for BST
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
    int height; // Height of node
};

struct Node *root;

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // New node is initially added at height 1
    return newNode;
}

// height of  node
int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

// balance factor of node
int balanceFactor(struct Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// update the height of node
void updateHeight(struct Node *node)
{
    if (node == NULL)
        return;
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
}

// LL rotation
struct Node *LLrotation(struct Node *root)
{
    struct Node *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

// RR rotation
struct Node *RRrotation(struct Node *root)
{
    struct Node *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

// RL rotation
struct Node *RLrotation(struct Node *root)
{
    root->right = LLrotation(root->right);
    return RRrotation(root);
}

// LR rotation
struct Node *LRrotation(struct Node *root)
{
    root->left = RRrotation(root->left);
    return LLrotation(root);
}

// create AVL tree
struct Node *createAVL()
{
    root = NULL;
    int n, data;
    printf("\nEnter how many nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter data %d: ", i + 1);
        scanf("%d", &data);
        if (root == NULL)
            root = createNode(data);
        else
        {
            struct Node *temp = root;
            struct Node *parent = NULL;
            while (temp != NULL)
            {
                parent = temp;
                if (data < temp->data)
                    temp = temp->left;
                else if (data > temp->data)
                    temp = temp->right;
                else // Duplicate keys are not allowed
                    return root;
            }
            if (data < parent->data)
                parent->left = createNode(data);
            else
                parent->right = createNode(data);
        }
        // Update height of the  temp node
        updateHeight(root);

        // Check balance factor for rotation
        int balance = balanceFactor(root);

        // LL Case
        if (balance > 1 && data < root->left->data)
            root = LLrotation(root);

        // RR Case
        if (balance < -1 && data > root->right->data)
            root = RRrotation(root);

        // LR Case
        if (balance > 1 && data > root->left->data)
            root = LRrotation(root);

        //  RL Case
        if (balance < -1 && data < root->right->data)
            root = RLrotation(root);
    }
    return root;
}

// inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to display the menu
void displayMenu()
{
    printf("\n--------------------------------------------");
    printf("\n1. Create AVL tree.");
    printf("\n2. Inorder Traversal.");
    printf("\n0. Exit.");
    printf("\n--------------------------------------------");
    printf("\nEnter your choice: ");
}

int main()
{
    int choice;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = createAVL();
            break;

        case 2:
            printf("\nInorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 0:
            printf("\n\nExiting program.\n\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}