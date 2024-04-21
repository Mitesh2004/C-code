#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data); // Create new node if root is NULL
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data); // Recursively insert into left subtree
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data); // Recursively insert into right subtree
    }

    return root;
}

// Function to create a BST based on user input
struct Node *createBST()
{
    struct Node *root = NULL;
    int n, data;

    printf("\nEnter how many nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter data %d: ", i + 1);
        scanf("%d", &data);

        root = insert(root, data); // Insert node into the BST
    }

    return root;
}

// Function to perform inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to perform preorder traversal
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform postorder traversal
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function to interact with the BST
int main()
{
    struct Node *root = NULL;
    int choice;

    while (choice)
    {
        printf("\n--------------------------------------------");
        printf("\n1. Create BST");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Insert a key into the BST");
        printf("\n0. Exit");
        printf("\n--------------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = createBST();
            break;

        case 2:
            printf("\nInorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("\nPreorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("\nPostorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("\nEnter key to insert: ");
            int key;
            scanf("%d", &key);
            root = insert(root, key);
            break;

        case 0:
            printf("\nExiting program.\n");
            return 0;
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}