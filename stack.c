#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
    int data ;
    struct node* next ;
}Node;
Node* create_node(char x){
    Node* newnode = malloc(sizeof(Node));
newnode->next = NULL;
newnode->data = x;
return newnode;
}

void printlist(Node** head)
{
    Node*temp = *head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
}


void push(Node**head,int x,Node**top){
   
    Node* newnode = create_node(x);
   
    
    if(*top  == NULL){
        *head = *top = newnode;
        return ;
    }
    
    
        (*top)->next = newnode;
        *top = newnode;
        
    
}


int pop(Node**head,Node**top){
    if(*top == NULL){
        return -1;
    }
    Node* temp = *top;
    Node*temp2 = *head;
    int value = (*top)->data;
    if(*top == *head){
        value = (*top)->data;
        *head = *top  = NULL;
        return value;
    }
    else{
        
        while(temp2->next!=*top){
            temp2 = temp2->next;
        }
        *top = temp2;
        (*top)->next = NULL;
        free(temp);
        
       return value;
    }


}
char peek(Node**top){
    if(*top == NULL){
        return -1;
    }
    return (*top)->data;
}
int empty(Node**top){
    if(*top == NULL){
        return 1;
    }
    return 0;
}
void check(Node**head,Node**top,char arr[]){
    int i = 0;
    while(arr[i]!='\0'){
        if(arr[i]=='('){
            push(head,arr[i],top);
        }
        else if(arr[i]==')'){
            if(empty(top)){
               
                return;
            }
            pop(head,top);
        }
        i++;
    
}

if(empty(top)){
    
}
else{
    
}
}
int result(char*ptr,Node**head,Node**top)
{
    int i = 0,o1 = 0,o2 = 0;
    int a = 0;
    while(*(ptr+i)!='\0'){
if (isdigit(*(ptr + i))) {   // preferred for single digit integer
            a = *(ptr + i) - '0'; 
            push(head, a, top);
}
else{
    o2 = pop(head,top);
    
    o1 = pop(head,top);
    
    if(*(ptr+i)=='+'){
        push(head,o1+o2,top);
       
    }
     if(*(ptr+i)=='-'){
        push(head,o1-o2,top);
       
    }
}
i++;
    }
    return pop(head,top);
}
char * infix_to_prefix(char*ptr){
    char post[100];
    char *p = post;
    int i = 0;
    while(*(ptr+i)!='NULL'){
if(*(ptr+i)=='(' ){

    }
}

int main(){
    char inf[] = "(A+B)*C";
    char *ptr = inf;
    char post[100];
    char *p = post;
    Node* head = NULL;
    Node* top = NULL;
    int ans = result(ptr,&head,&top);
    printf("%d",ans);
    

}
