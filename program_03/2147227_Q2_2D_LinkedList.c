/*
 *  
 *  NAME:       Rajesh S - MCA-B
 *  ROLL_NO:    2147227 
 *  DATE:       23/03/22
 * --> Question 01: Implement the ADT functions INSERT, DELETE,
 *  and SEARCH for a singly linked list data structure.
 * --> Question 02: Create and traverse the 2D linked list as represented in the image
 * 
 */

/*
*   Header files
*/
#include <stdio.h>
#include <stdlib.h>

#define max 5

// defining structure
struct stack
{
    int val;
    struct stack *next;
};

// alias name as node for struct
typedef struct stack node;

/**
 * Function prototype
*/
void insert_last(node **head);
void insert_begin(node **head);
void ins_pos(node **head);
void dis(node *head);
int count_nodes(node **head);

/*
 *  main program 
 */

int main()
{
    int sz = 0;
    int i = 0;
    int j = 0;
    int cont = 1;
    int sub_opt = 0;
    node *arr[max];
    //node *head = NULL;

    printf("\nEnter the Array size:\t");
    scanf("%d", &sz);

    // to initialize all the ptr of arr to be null

    for (i = 0; i < sz; i += 1)
    {
        arr[i] = NULL;
    }

    for (i = 0; i < sz; i += 1)
    {

        while (cont)
        {
            printf("\n-----------------------------------------------------------------------------\n");
            printf("\nEnter for Arr[%d]: \n\t1. Insert at first\n\t2. Insert at Last\n\t3. Insert by position\n", i);
            printf("\n-----------------------------------------------------------------------------\n");
            scanf("%d", &sub_opt);

            switch (sub_opt)
            {
            case 1:
                printf("\nInserting node at start ....\n");
                insert_begin(&arr[i]);
                break;
            case 2:
                printf("\nInserting node at end ....\n");
                insert_last(&arr[i]);
                break;
            case 3:
                printf("\nInserting node by position\n");
                ins_pos(&arr[i]);
                break;
            default:
                printf("\nInvalid option\tTry again :(");
                break;
            }

            printf("\nEnter \n\t0. to exit \n\t1. To continue insert\n");
            scanf("%d", &cont);
        }

        // reset so that for indexes of arrays, the loop can be continued
        cont = 1;
    }

    // display the array created --> traversing in the array of linked lists
    printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
    for (i = 0; i < sz; i += 1)
    {
        printf("\n\narr[%d]:", i);
        dis(arr[i]);
    }
    printf("\n\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");

    printf("\n\nThank you :)\n\n");

    return 0;
}

/**
 * insert a node at last in the linked list 
 */
void insert_last(node **head)
{

    //allocating space from heap
    node *new_node = (node *)malloc(sizeof(node));
    // temp pointer for traversal
    node *tmp = *head;
    int val = 0;

    // if it's null then return
    if (NULL == new_node)
    {
        printf("\nSomething went wrong! :(");
        return;
    }
    else
    {

        // getting input from user and assigning to the new node
        printf("\nEnter the value of the node:\t");
        scanf("%d", &val);

        //printf("\nInside the insert_last linked list");

        new_node->val = val;

        // since it's last node insert_last at last
        new_node->next = NULL;

        if (NULL == *head)
        {
            // for the 1st node
            *head = new_node;
        }
        else
        {
            // traverse to last node
            while (NULL != tmp->next)
            {
                tmp = tmp->next;
            }
            tmp->next = new_node;
        }
    }
}

/**
 * insert a node at begining in the linked list 
 */
void insert_begin(node **head)
{

    //allocating space from heap
    node *new_node = (node *)malloc(sizeof(node));
    // temp poiter for traversal
    node *tmp = *head;
    int val = 0;

    // if it's null then return
    if (NULL == new_node)
    {
        printf("\nSomething went wrong! :(");
        return;
    }
    else
    {

        // getting input from user and assigning to the new node
        printf("\nEnter the value of the node:\t");
        scanf("%d", &val);

        //printf("\nInside the insert_last linked list");

        new_node->val = val;
        new_node->next = NULL;

        if (NULL == tmp)
        {
            // for the 1st node
            *head = new_node;
        }
        else
        {

            // printf("\nmore than one insert ");
            new_node->next = tmp;
            tmp = new_node;
            *head = tmp;
            //tmp->next = tmmp;
        }
    }
}

/**
 *  Insert the new node by position 
 */

void ins_pos(node **head)
{

    // var declaration
    int count = 1;
    int pos = 0;
    int total_nodes = 0;
    node *tmp = *head;
    node *new_node = NULL;

    total_nodes = count_nodes(head) + 1;

    // get pos input from user
    printf("\nEnter the position in which you want to insert:\t");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insert_begin(head);
    }

    else if (pos == total_nodes)
    {
        insert_last(head);
    }

    // check if the pos is invalid or valid
    else if (pos > total_nodes)
    {
        printf("\nInvalid postion !!");
    }
    else
    {
        //Traverse to the insering node
        while ((count < pos - 1) && (NULL != tmp))
        {
            tmp = tmp->next;
            count += 1;
        }
        // create a mem space from heap
        new_node = (node *)malloc(sizeof(node));

        // if it has some error in mem space preservation
        if (NULL == new_node)
        {
            printf("Something went wrong!!!!\nTry again\n");
        }
        else
        {
            new_node->next = NULL;
            printf("\nEnter the node value:\t");
            scanf("%d", &new_node->val);
            new_node->next = tmp->next;
            tmp->next = new_node;
        }
    }
}

// count number of nodes created
int count_nodes(node **head)
{

    node *tmp = *head;
    int count = 0;
    //printf("\n count nodes: before while()");

    while (NULL != tmp)
    {
        //printf("\n%f", tmp->val);
        tmp = tmp->next;
        count += 1;
    }

    return count;
}

/**
 *  Display the contents of the linked List 
 */
void dis(node *head)
{

    node *tmp = head;

    if (tmp == NULL)
    {
        printf("\tThe linked list is empty");
    }
    else
    {
        while (NULL != tmp)
        {
            printf(" -->|_%d_| ", tmp->val);
            tmp = tmp->next;
        }
    }
}