#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}Node;
Node* createnode(int x)
{
    Node*newnode;
    newnode = (malloc(sizeof(Node)));
    if(newnode==NULL){
        printf("memory allocation failed!!");
    }
    else{
    newnode->next = NULL;
    newnode->data = x;
    return newnode;
    }
}
Node* insert(Node*head,int x,int j,int max){
    int count = 0;
    Node*newnode = createnode(x);
    Node*temp = head;
     if(head==NULL){
        head = newnode;      
}
    else if(j==0){
        newnode->next = head;
        head = newnode;
        

    }
    else if(j==max){
        while(temp->next!=NULL){
            temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
    }
   
else if(j>0 && j<max){
    while(count!=j){
        temp = temp->next;
        count++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
return head;
}
Node* delete(Node*head,int j,int max){
    int count = 0;
    
    Node*temp = head;
    Node*previous = temp;
     if(head==NULL){
        printf("nothing to delete")  ;    
}
    else if(j==0){
        head = head->next;
        free(temp);
    }
    else if(j==max){
        while(temp->next!=NULL){
            previous = temp;
            temp = temp->next;
    }
   previous->next = NULL;
    free(temp);
    
    }
   
else if(j>0 && j<max){
    while(count!=j){
        previous = temp;
        temp = temp->next;
        count++;
    }
    previous->next = temp->next;
    free(temp);
}
return head;
}
void find(Node*head,int x,int max){
    int count = 0;
    Node*temp = head;
    while(temp->data != x && temp->next != NULL){
        temp = temp->next;
count ++;
}
if(temp->data == x){
    printf("%dth element",count + 1);
    }
    else if(temp->next == NULL){
        printf("nhi hai");
    }
}
Node* reverse(Node*head){
    Node*prev = head;
    int count = 0;
    Node*temp = head;
    while(head->next != NULL){
temp = head->next;
        
        
        head->next = prev;
        prev = head;
       head = temp;
        if(count==0){
            prev->next = NULL;
        }
        count++;

    }
    return prev;
}
int main()
{
    int i,j,x;
    Node*newnode,*temp;
    printf("enter how many linked list u want to manage : ");
    int n,count = 0;
    
    scanf("%d",&n);
int arr[n];
    Node** listarray = (malloc(n*sizeof(Node*)));
    if(!listarray){
        printf("memory allocation failed!!");
        return 1;
    }
     for ( i = 0;i<n;i++){
        listarray[i] = NULL;
    }
    int choice = 1;
    int m;
    for ( i = 0;i<n;i++){
        printf("for %d node :\n",i);
        choice = 1;
        while(choice){
printf("enter no. : ");
scanf("%d",&m);
//temp = listarray[i];    accha baar baar 1st node pr hi point kr rha

            newnode = createnode(m);
            if(listarray[i]==NULL){
                temp = listarray[i] = newnode;

            }
            else{
                temp->next = newnode;
                temp = newnode;
                
            }
            printf("\ndo u want to play more : 1 for yes, 0 for no : ");
            scanf("%d",&choice);
        }

    }
      for ( i = 0;i<n;i++){
        
        temp = listarray[i];
        while(temp!= NULL){
            printf("%d ",temp->data);
            temp = temp->next;
count++;
        }
        arr[i] = count;
       printf("\n");
       count = 0;
            
        }
printf("give i ,j ,x for inserting : ");
scanf("%d %d %d",&i,&j,&x);
listarray[i] = insert(listarray[i],x,j,arr[i]);
printf("after insertion : \n");
   for ( i = 0;i<n;i++){
        
        temp = listarray[i];
        while(temp!= NULL){
            printf("%d ",temp->data);
            temp = temp->next;

        }
       printf("\n");
        } 
        printf("\n give i , j for deletion : ");
        scanf("%d %d",&i,&j);
    listarray[i] = delete(listarray[i],j,arr[i]);
printf("after deletion : \n");
   for ( i = 0;i<n;i++){
        
        temp = listarray[i];
        while(temp!= NULL){
            printf("%d ",temp->data);
            temp = temp->next;

        }
       printf("\n");
        }
        printf("\nenter i,x for searching : ");
        scanf("%d %d",&i,&x);
     find(listarray[i],x,arr[i]);

     printf("\ngive i for reversing : ");
     scanf("%d",&i);
        listarray[i] = reverse(listarray[i]);
printf("after reversing : \n");
   for ( i = 0;i<n;i++){
        
        temp = listarray[i];
        while(temp!= NULL){
            printf("%d ",temp->data);
            temp = temp->next;

        }
       printf("\n");
        }
}