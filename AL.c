#include <stdio.h>////////////////////////////////////////////////
#include <stdlib.h>

struct node
{
    int data; // vertex
    struct node *next; // edge
};

// Function to create a new node
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a list (adjacency list representation of a graph)
void createList(struct node *list[], int n)
{
    int i, j, ans;
    struct node *temp;
    
    printf("\nEnter Graph:\n");
    
    for (i = 0; i < n; i++)
    {
        list[i] = NULL; 
        
        for (j = 0; j < n; j++)
        {
            printf("Is there an edge between %d and %d vertices? (yes-1, No-0): ", i + 1, j + 1);
            scanf("%d", &ans);
            
            if (ans == 1)
            {
                temp = createNode(j); // Create a new node with data 'j'
                
                // Append the new node to the end of the list[i]
                struct node **ptr = &list[i]; // Pointer to the head pointer of list[i]
                
                // Traverse to the end of the list
                while (*ptr != NULL)
                {
                    ptr = &((*ptr)->next);
                }
                
                *ptr = temp; // Append the new node at the end
            }
        }
    }
}

// Function to display the adjacency list
void displayList(struct node *list[], int n)
{
    struct node *temp;
    int i;
    
    printf("\nAdjacency list:\n");
    
    for (i = 0; i < n; i++)
    {
        printf("v%d->", i + 1);
        temp = list[i];
        
        while (temp != NULL)
        {
            printf("\t%d->", temp->data + 1); // Print adjacent vertex
            temp = temp->next;
        }
        
        printf("\n");
    }
}

int main()
{
    int n;
    
    printf("How many vertices: ");
    scanf("%d", &n);
    
    struct node *list[n]; // Array of pointers to struct node
    
    createList(list, n); // Create the adjacency list
    
    displayList(list, n); // Display the adjacency list
    
    return 0;
}
