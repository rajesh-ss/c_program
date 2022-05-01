
#include <stdio.h>
#include <stdlib.h>



// since 9 indexes

#define max 10


// struct structure
struct nd{
	
	int in_data;
	char ch_data;
	struct nd* next;
};

typedef struct nd node;


struct nod{
	
	char ch;
	int index;
	struct nod * next;
};

typedef struct nod linked;



void insertIntoArray(node arr[]);
void displayArray(node arr[]);
linked* convertArrayToLinkedList(node arr[], int list, int available);

void display(linked *ls);


int main(){
	
	node arr[max];
	
	linked* linkedList = NULL;
	
	int opt = 0;
	int list = 0;
	int available = 0;
	
	printf("\nselect the option");
	printf("\n1. insert ele into array\t");
	scanf("%d", &opt);
	
	switch(opt){
		case 1:
			insertIntoArray(arr);
			displayArray(arr);
			break;
			
		case 2:
			displayArray(arr);
			break;
		default:
			printf("\ninvalid option sleected\n");
			break;
	}
	
	printf("\nEnter the list value for converting the array tot linked list\n");
	scanf("%d", &list);
	printf("\nEnter the available value for converting the array tot linked list\n");
	scanf("%d", &available);
	
	linkedList = convertArrayToLinkedList(arr, list, available);
    display(linkedList);
	
	return 0;
}

void insertIntoArray(node arr[]){
	
	int i=0;
	
	//printf("\ninseide insert array\n");
	for(i=0;i<max; i+=1){
		
	
			
			// getting inputs from users
			printf("\nEnter the data %d values\n", i);
			printf("-----------------------------------\n");
			

			printf("\nEnter the integer data:\t");
			scanf(" %d",&arr[i].in_data);
            
			while(getchar()!='\n');
			printf("\nEnter the character data:\t");
			//scanf("%c ", &arr[i].ch_data);
            arr[i].ch_data = getchar();
			

			//fflush(stdin);
			// assigning default val as specified in qn
			arr[i].next = &arr[arr[i].in_data];
	

	}
}

void displayArray(node arr[]){
	
	int i=0;
	
	for(i=0;i<max; i+=1){
	
		printf("\nData value:\t%c ", arr[i].ch_data);
		fflush(stdin);
		printf("\nIndex value:\t%d", arr[i].in_data);
			
	}	
}


linked *convertArrayToLinkedList(node arr[], int list, int available){
		
	
	linked *head; 
		
	linked *temp;
	linked *newNode;
	int count = 0;
	
	while(count > available){
		
		if(count == 1){
			head = (linked *) malloc(sizeof(linked));
			head->next = NULL; 
			head->index = arr[list].in_data;
			head->ch = arr[list].ch_data;
			temp = head;
		}
		
		newNode = (linked *) malloc(sizeof(linked));
		newNode->ch = arr[temp->index].ch_data;
		newNode->index = arr[temp->index].in_data;
		temp->next = newNode;
		temp = temp->next;
        temp->next = NULL;
		count+=1;
	}		
	
	return head;
}


void display(linked *ls){
	
	while(ls!=NULL){
		printf("\n%c", ls->ch);
		ls = ls->next;
	}
}

