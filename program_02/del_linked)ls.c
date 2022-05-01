/*
DATA STRUCTURES LAB 2 
Q2. DELETE MULTIPLES OF 10 FROM LINKED QUEUE WITHOUT CHANGING THE ORDER
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node *next;
};
struct node *front;
struct node *rear;


void enqueue();
void dequeue();
void delque();
void display();


void main()
{
	int ch;
	while(ch != 4){
	
	printf("\nLEnter 0. TO exit\n1.enqueue\n2.dequeue\n3.display\n4.DELETE MULTIPLES OF 10\n");
	scanf("%d",&ch);
	switch(ch)
	{
            case 0:
                printf("\nThank you :)");
                break;
		    case 1:  
            {   
                enqueue();  
                break;  
            }  
            case 2:  
            {  
                dequeue();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }   
            case 4:
            {
            	delque();
                display();
            	break;
            }
            default:  
            {  
                printf("please enter correct option");  

            } 
	}
}
	
}

void enqueue()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\noverflow\n");  
        return;  
    }  
    else  
    {   
        printf("\nENTER VALUE: \n");  
        scanf("%d",&item);  
        ptr->x = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void dequeue()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nunder flow\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  


void delque()
{
	struct node *temp,*prev;
	if(front == NULL)
	{
		printf("\nunder flow\n");  
        return; 
	}
	temp = front;
	while((temp!= NULL)&&((temp->x)%10==0))
	{
		front = temp->next;
		free(temp);
		temp =front;
	}
	while(temp!=NULL)
	{
		while((temp!=NULL)&&((temp->x)%10!=0))
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp == NULL)
            return;
 
        prev->next = temp->next;
        free(temp);
        temp = prev->next;
	}
	printf("\nremoving multiples of 10\n");
}


void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEMPTY QUEUE\n");  
    }  
    else  
    {   printf("\nQUEUE ELEMENTS : \n");  
        while(ptr != NULL)   
        {  
            printf("%d->",ptr->x);  
            ptr = ptr -> next;  
        }  
    }  
}  