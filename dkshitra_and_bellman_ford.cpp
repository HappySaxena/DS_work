#include<bits/stdc++.h>
using namespace std;

void addEdge(unordered_map<int,vector<pair<int,int>>>& graph,const int u,const int v,const int weight){
    graph[u].push_back({v,weight});
    
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
void printpath(vector<int>& parent,int node){
    if(node == -1){
        return;
    }
    printpath(parent,parent[node]);
    cout << node << " ";
}

int main(){
    unordered_map<int,vector<pair<int,int>>>graph;
addEdge(graph, 0, 1,7);
addEdge(graph, 0, 2,6);
addEdge(graph, 1, 4,-3);
addEdge(graph, 1, 3,9);

addEdge(graph, 2, 1,8);
addEdge(graph, 2, 3,-4);
addEdge(graph, 2, 4,5);
addEdge(graph, 3, 4,7);
addEdge(graph, 3, 0,2);
addEdge(graph, 4, 2,-2);

printGraph(graph);
int arr[5][5];

for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
        auto it = std::find_if(graph[i].begin(), graph[i].end(),
[j](const std::pair<int, int>& p) {
    return p.first == j;

});
if(it != graph[i].end()){
            arr[i][j] = it->second;
        }
        else{
            arr[i][j] = 0;
        }
    }}
for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
        cout << arr[i][j] << " ";
    }
    cout << endl;
}

vector<int> parent(5,-1);
vector<int> dist(5,INT_MAX);
dist[0] = 0;
queue<int> q;
for(int i=0;i<4;i++){
vector<int> visited(5,0);
int node = 0;
q.push(node);

visited[node] = 1;
while(!q.empty()){
    node = q.front();
    q.pop();
   
    for(int j = 0;j<5;j++){
        if(arr[node][j] != 0){
            if((dist[node] + arr[node][j]) < dist[j]){
                dist[j] = dist[node] + arr[node][j];
                parent[j] = node;
            }
            if(visited[j] !=1){
                
            
            q.push(j);

            visited[j] = 1;
            }
        }
    }
    

}
}
for(int i=0;i<5;i++){
    cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
}

for(int i=0;i<5;i++){
    cout << "Path from 0 to " << i << ": ";
    printpath(parent,i);
    cout << endl;
}
}