#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int a;
    struct node* next ;
}Node;

Node* createnode(int x){
    Node* newnode = malloc(sizeof(Node)); // redundancy here....
    if(newnode==NULL){
        printf("memory allocation failed");
        exit(1);
    }
    newnode->next = NULL;
    newnode->a = x;
return newnode;

}

Node* deletenode(Node*head,Node*previous,int max){

printf("\nenter which node u want to delete : ");
int n;
scanf("%d",&n);
Node*temp = head ;
int count = 0;
if(n>0 && n< (max-1)){
while(temp !=NULL && count!=n){
previous = temp;
temp = temp->next;
count++;
}
if(temp== NULL){
    printf("out of bound");
}
if(count==n){

previous->next = temp->next;
previous = temp;
temp->next = NULL;
free(previous);

}}
else if(n==0){
  
    head = head->next;
    free(temp);
}
else if(n==(max-1))
{
    while(temp->next!= NULL){
        previous = temp;
        temp = temp->next;

    }
    previous->next = NULL;
    free(temp);
}
else{
    printf("out of bound");
}
return head;
}

Node* insertnode(Node*head,Node*newnode,int max)
{
    int count = 0;
    printf("kis pr insert krna chahte hai : ");
    int n;
    scanf("%d",&n);
    Node* temp = head;
    if (head== NULL){
        head = newnode;
    }
    if(n==0){
        newnode->next = head;
        head = newnode ;

    }
    else if(n == max-1){
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
    else if (n>0 && n<(max-1)){
        while(count!=n){
            temp = temp->next;
            count++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        
    }
    else{
        printf("out of bound");
    }
    return head;
}

int main(){
Node *head = NULL,*temp,*newnode,*previous,*extranode;
previous =NULL;

int choice = 1;
int value = 0 ;
while(choice){
    printf("enter a number: ");
scanf("%d",&value);
newnode = createnode(value);
if (head==NULL){
head = temp = newnode;
}
else{
    temp->next = newnode;
    temp = newnode;
}
printf("Do you want to add more ? 1 for yes , 0 for no\n");
scanf("%d",&choice);

}
temp = head;
int count = 0;
while(temp != NULL){
    printf("%d ",temp->a);
    temp = temp->next;
    count++;
}
printf("\nu added %d nodes in linked list",count);
head = deletenode(head,previous,count);
temp = head;
count = 0;
while(temp != NULL){
    printf("%d ",temp->a);
    temp = temp->next;
    count++;
}

printf("\nremaining %d nodes in linked list",count);
printf("\n now inseritng a node :");
int b = 26;
newnode = createnode(b);

head = insertnode(head,newnode,count);
temp = head;
count = 0;
while(temp != NULL){
    printf("%d ",temp->a);
    temp = temp->next;
    count++;
}
printf("\nu added %d nodes in linked list",count);
}