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

// Function to display nodes at a specific level
void printNAL(struct Node *root, int level)
{
    if (root == NULL)
        return;

    if (level == 1)
    {
        printf("%d ", root->data);
    }
    else if (level > 1)
    {
        printNAL(root->left, level - 1);
        printNAL(root->right, level - 1);
    }
}

// Function to calculate the height (total levels) of the BST
int TotalLevel(struct Node *root)
{
    if (root == NULL)
        return 0;

    int LL = TotalLevel(root->left);//LL=leftLevels
    int RL = TotalLevel(root->right);//RL=rightLevels

    return (LL > RL ? LL : RL) + 1;
}

// Function to display nodes at each level of the BST
void NBL(struct Node *root)
{
    if (root == NULL)
        return;

    int totalLevels = TotalLevel(root);
    printf("\nNodes at each level:\n");
    for (int i = 1; i <= totalLevels; i++)
    {
        printf("Level %d: ", i);
        printNAL(root, i);
        printf("\n");
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
        printf("\n2. Display Nodes at Each Level");
        printf("\n3. Total Levels");
        printf("\n4. Exit");
        printf("\n--------------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = createBST();
            break;

        case 2:
            NBL(root);
            break;

        case 3:
            // Calculate and display total levels
            printf("\nTotal levels of the tree: %d\n", TotalLevel(root));
            break;

        case 4:
            printf("\nExiting program.\n");
            return 0;
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}