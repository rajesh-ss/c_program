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

// defining structure
struct stack
{
    float val;
    struct stack *next;
};

// alias name as node for struct
typedef struct stack node;

/**
 * Function prototype
 */

// push new ele to the stack
void insert_last(node **head);
void insert_begin(node **head);
void ins_pos(node **head);
int count_nodes(node **head);
void delete_start(node **head);
void delete_last(node **head);
void delete_pos(node **head);
void search(node **head);
void dis(node *head);

/*
 *  main program 
 */

int main()
{

    // var declaration
    int option = -1;
    node *head = NULL;
    int cont = 1;
    int sub_opt = 0;

    // get options from user
    // continue the loop until the user enters 0 as the input
    while (cont)
    {
        printf("\n-----------------------------------------------------------------------------\n");
        printf("Enter: \n\t1. Insert\n\t2. Delete\n\t3. Display\n\t4. count the number of nodes created\n\t5. Search fo element");
        printf("\n-----------------------------------------------------------------------------\n");
        scanf("%d", &option);
       
        switch (option)
        {
            // case 1: Has insert at begining, at end and by position
        case 1:
            printf("\n-----------------------------------------------------------------------------\n");
            printf("\nEnter: \n\t1. Insert at first\n\t2. Insert at Last\n\t3. Insert by position\n");
            printf("\n-----------------------------------------------------------------------------\n");
            scanf("%d", &sub_opt);
            
            switch (sub_opt)
            {
            case 1:
                printf("\nInserting node at start ....\n");
                insert_begin(&head);
                break;
            case 2:
                printf("\nInserting node at end ....\n");
                insert_last(&head);
                break;
            case 3:
                printf("\nInserting node by position\n");
                ins_pos(&head);
                break;
            default:
                printf("\nInvalid option\tTry again :(");
                break;
            }
            break;

            // case 2: has delete at start, at end and by position
        case 2:
            printf("\n-----------------------------------------------------------------------------\n");
            printf("\nEnter \n\t1. Delete at first\n\t2. Delete at Last\n\t3. Delete by position\n");
            printf("\n-----------------------------------------------------------------------------\n");
            scanf("%d", &sub_opt);

            switch (sub_opt)
            {
            case 1:
                printf("\nDeleting node at start ....\n");
                delete_start(&head);
                break;
            case 2:
                printf("\nDeleting node at end ....\n");
                delete_last(&head);
                break;
            case 3:
                printf("\nDeleting node by position\n");
                delete_pos(&head);
                break;
            default:
                printf("\nInvalid option\tTry again :(");
                break;
            }
            break;
            // case 3: call display fun for displaying all elements in the linked list
        case 3:
            dis(head);
            break;
            // case 4: Displays the number of nodes in the linked list
        case 4:
            printf("\nThe number of nodes created are: %d\n", count_nodes(&head));
            break;
            // case 5: search for the element in the linked list
        case 5:
            search(&head);
            break;
        default:
            printf("\nInvalid option\tTry again :(");
        }

        //clrscr();
        printf("\nEnter \n0 to exit \n1. to continue\n");
        scanf("%d", &cont);
    }

    printf("\nThank you :)\n\n");
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
    float val = 0;

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
        scanf("%f", &val);

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
    float val = 0;

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
        scanf("%f", &val);

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
            scanf("%f", &new_node->val);
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
 *   delete the 1st node of the linked list
 *   Validation:    
 *              1. check if there is atleast one single node
 */
void delete_start(node **head)
{
    // temp var for deleting 1st node
    node *tmp = *head;

    // to check if the linked list is empty or not
    if (tmp != NULL)
    {

        /**
         * __Note__
         *  Reason why it's not tmp = tmp-> next is because the local tmp val will be changed bu the *node val will not be  
         */
        *head = tmp->next;
        free(tmp);
        printf("\nsuccesfully deleted first node\n");
    }
    else
    {
        printf("\nSince it's empty no node is deleted, first insert some node\n");
    }
}

/**
 * Delete the 1st node of the linked list
 * Validation:
 *            1. check if there is atleast one single node. 
 *            2. if there is only one node: deleting that node
 */

void delete_last(node **head)
{

    node *cur = *head;
    node *pre = *head;

    // to check if the linked list is empty or not
    if (cur != NULL)
    {

        // if there is only one node delete that node
        if (cur->next == NULL)
        {
            *head = NULL;
        }
        else
        {
            while (cur->next != NULL)
            {
                pre = cur;
                cur = cur->next;
            }
            pre->next = cur->next;
            free(cur);
        }
    }
    else
    {
        printf("\nSince it's empty, no node is deleted, first insert some node\n");
    }
}

/**
 *  delete node by position
 */

void delete_pos(node **head)
{

    // var declaration
    int count = 1;
    int pos = 0;
    int total_nodes = 0;
    node *cur = *head;
    node *pre = *head;

    total_nodes = count_nodes(head);

    // get pos input from user
    printf("\nEnter the position in which you want to delete:\t");
    scanf("%d", &pos);

    if (pos == 1)
    {
        delete_start(head);
    }

    else if (pos == total_nodes)
    {
        delete_last(head);
    }

    // check if the pos is invalid or valid
    else if (pos > total_nodes || pos < 0)
    {
        printf("\nInvalid postion !!");
    }
    else
    {
        //Traverse to the delete node
        while ((count < pos) && (NULL != cur))
        {
            pre = cur;
            cur = cur->next;
            count += 1;
        }
        pre->next = cur->next;
        free(cur);
    }
}

/**
 *  Search for a element in linked list 
 */

void search(node **head)
{

    float ele_ser = 0;
    int pos = 1;
    node *tmp = *head;

    if (tmp == NULL)
    {
        printf("\nThe linked list is empty");
    }
    else
    {
        printf("\nEnter the element that you wan to search:\t");
        scanf("%f", &ele_ser);

        while (NULL != tmp)
        {
            if (tmp->val == ele_ser)
            {
                printf("\n-----------------------------------------------------------------------------\n");
                printf("Element %f found in the position %d", ele_ser, pos);
                printf("\n-----------------------------------------------------------------------------\n");
                return;
            }
            else
            {
                tmp = tmp->next;
                pos += 1;
            }
        }
        printf("\nElement not found !!");
    }
}

/**
 *  Display the contents of the linked List 
 */
void dis(node *head)
{

    node *tmp = head;
    printf("\n");

    if (tmp == NULL)
    {
        printf("\nThe linked list is empty");
    }
    else
    {
        printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
        while (NULL != tmp)
        {
            printf(" -->|_%f_| ", tmp->val);
            tmp = tmp->next;
        }
        printf("\n\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    }
}