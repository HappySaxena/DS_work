#include<bits/stdc++.h>
using namespace std;
typedef struct edge{
    int data;
    int weight;
    struct edge* next;
}Enode;
Enode* createEdge(int data){
    Enode* node = new Enode();
    node->data = data;
    node->next = NULL;
    return node;
}
typedef struct vertex{
    int data;
    struct edge* next;
    struct vertex* down;
}Vnode;
Vnode* createNode(int data){
    Vnode* node = new Vnode();
    node->data = data;
    node->next = NULL;
    node->down = NULL;
    return node;
}




void addEdge(unordered_map<int,vector<pair<int,int>>>& graph,const int u,const int v,const int weight){
    graph[u].push_back({v,weight});
    graph[v].push_back({u,weight});
}
void printGraph(unordered_map<int,vector<pair<int,int>>>& graph) {
    for (const auto& pair : graph) {
        cout << pair.first << " <-> ";
        for (const auto& neighbor : pair.second) {
            cout << neighbor.first << "(" << neighbor.second << ") ";
        }
        cout << endl;
    }
}
Vnode* represent(unordered_map<int,vector<pair<int,int>>>& graph,Vnode* head){
    int i = 0;
    Vnode* temp = NULL;
    for(auto &pair : graph){
         Vnode* vertex = createNode(pair.first);
        if(temp != NULL){
            temp->down = vertex;
        }
        if(i==0){
            head = vertex;
        }
        
       
        for(auto &neighbor : pair.second){
            Enode * edge = createEdge(neighbor.first);
            edge->weight = neighbor.second;
            if(vertex->next == NULL){
                vertex->next = edge;
            }
            else{
                Enode * temp2 = vertex->next;
                while(temp2->next != NULL){
                    temp2 = tem
                    if(i==0){p2->next;
                }
                temp2->next = edge;
            }
        }
         temp = vertex;
         i++;
    }
    return head;
    }
    void print(Vnode* head)
    {
        Vnode* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            Enode* edge = temp->next;
            while(edge != NULL){
                cout << edge->data <<"(" << edge->weight<< ") "<<" -> ";
                edge = edge->next;
            }
            cout << endl;
            temp = temp->down;
        }
    }

int main(){
unordered_map<int,vector<pair<int,int>>> graph;
addEdge(graph, 0, 1,35);
addEdge(graph, 0, 2,34);
addEdge(graph, 1, 2,78);
addEdge(graph, 1, 3,56);
addEdge(graph, 2, 4,5);
addEdge(graph, 3, 4,3);
addEdge(graph, 4, 5,90);
addEdge(graph, 5, 6,34);


Vnode* head = NULL;
head = represent(graph,head);
print(head);




}
