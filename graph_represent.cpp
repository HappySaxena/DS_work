#include<bits/stdc++.h>
using namespace std;

// void addEdge(unordered_map<int,vector<int>>& graph,const int u,const int v){
//     graph[u].push_back(v);
//     graph[v].push_back(u);
// }
// void printGraph(const unordered_map<int, vector<int>>& graph) {
//     for (const auto& pair : graph) {
//         cout << pair.first << " <-> ";
//         for (const auto& neighbor : pair.second) {
//             cout << neighbor << " ";
//         }
//         cout << endl;
//     }
// }
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

int main(){
    unordered_map<int,vector<pair<int,int>>>graph;
addEdge(graph, 0, 1,10);
addEdge(graph, 0, 2,5);
addEdge(graph, 1, 2,9);
addEdge(graph, 1, 3,12);
addEdge(graph, 2, 4,13);
addEdge(graph, 3, 4,16);
addEdge(graph, 4, 5,18);
addEdge(graph, 5, 6,20);
printGraph(graph);
int arr[7][7];

for(int i=0;i<7;i++){
    for(int j=0;j<7;j++){
        if(find(graph[i].begin(), graph[i].end(), j) != graph[i].end()){
            arr[i][j] = 1;
    }
        else{
            arr[i][j] = 0;
        }
    }}
for(int i=0;i<7;i++){
    for(int j=0;j<7;j++){
        cout << arr[i][j] << " ";
    }
    cout << endl;
}
queue<int> q;
int node = 0;
int i = 0;
vector<int> visited(7,0);
cout<<i;
visited[i] = 1;
q.push(i);
while(!q.empty()){
    int node = q.front();q.pop();
    for(int j =0;j<7;j++){
        if(arr[node][j] == 1 && visited[j] == 0){
            cout<<j;
            visited[j] = 1;
            q.push(j);
        }
    }
}
return 0;


}