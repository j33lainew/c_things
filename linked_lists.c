#include <stdlib.h>
#include <stdio.h>


//define linked list
struct node {
	//entry
	int key;
	//pointer to next node
	struct node *next;
};

void print_ll(struct node *a) {
	printf("Location of head: %p\n", a);
	//%p prints point data
	while(a != NULL) {
		//for pointers to structures, we use ->
		printf("%d ",a->key);
		a=a->next;
		printf("\n");
		printf("Location of head: %p\n", a);
	}
}

int length(struct node *a) {
	int len=0;
	while(a!=NULL) {	
		len++;
		a=a->next;
	}
		
	return len;
}
int main() {
	int i,len;
	int N=10;
	struct node *t,*head;	

	//allocate structure
	t=(struct node *) malloc(sizeof *t);
	//set the key to be 1. Remember t->key is equivalent to *(t).key 
	t->key=1;
	//point x to initial t
	head=t;
	for(i=2;i<=N;i++) {
		// set next pointer to a new node
		t->next=(struct node*) malloc(sizeof *t);
		// switch to the new node
		t=t->next;
		t->key=i;
	}
	t->next=NULL;
	printf("Before printing ll: %d\n",head->key);
	printf("Location of head: %p\n", head);
	print_ll(head);
	printf("\n");
	printf("After printing ll: %d\n",head->key);

	len=length(head);	
	printf("length:%d\n",len);
	return 0;
	
}
