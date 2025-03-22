#include <stdio.h>
#include <stdlib.h>
void enqueue(int* queue,int* rear,int* front,int n,int x){
    if(*rear==-1){
        *rear = 0;
        queue[*rear] = x;
        return;
    }
else if(((*rear+1)%n)== *front){
        printf("Queue is full\n");
        return;
    }
    else{
    *rear = (*rear + 1)%n;
    queue[*rear] = x;
    }
}
void dequeue(int* queue,int* front,int *rear,int n){
    if(*rear == -1){
        printf("Queue is empty\n");
        return;
    }
    if(*front == *rear){
  *front = 0;
  *rear = -1;
  return;
    }
    *front = (*front + 1)%n;
}
    

int main(){
    int n;
    printf("Enter the number of elements in the queue: ");
    scanf("%d",&n);
    int queue[n];
    int front = 0;

    int rear = -1;
    int *rear2 = &rear;
    enqueue(queue,&rear,&front,n,5);
   
    enqueue(queue,&rear,&front,n,10);
    
    enqueue(queue,&rear,&front,n,15);
    
    enqueue(queue,&rear,&front,n,20);
    
    enqueue(queue,&rear,&front,n,25);
     
    enqueue(queue,&rear,&front,n,30);
     
    enqueue(queue,&rear,&front,n,35);
    printf(" FINAL REAR VALUE : %d\n",rear);

   
     dequeue(queue,&front,&rear,n);
     
     dequeue(queue,&front,&rear,n);
     
    dequeue(queue,&front,&rear,n);
     
     dequeue(queue,&front,&rear,n);
     
     dequeue(queue,&front,&rear,n);
    
     dequeue(queue,&front,&rear,n);
     
      dequeue(queue,&front,&rear,n);

     printf("FINAL front value : %d\n",front);
     printf(" FINAL REAR VALUE : %d\n",rear);
    for(int i = front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
     
    enqueue(queue,&rear,&front,n,25);
     
    enqueue(queue,&rear,&front,n,30);

for(int i = front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
     printf("FINAL front value : %d\n",front);
     printf(" FINAL REAR VALUE : %d\n",rear);
}