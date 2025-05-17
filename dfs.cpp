#include<bits/stdc++.h>
using namespace std;

void addEdge(unordered_map<int,vector<int>>& graph,const int u,const int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void printGraph(const unordered_map<int, vector<int>>& graph) {
    for (const auto& pair : graph) {
        cout << pair.first << " <-> ";
        for (const auto& neighbor : pair.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}


int main(){
unordered_map<int, vector<int>> graph;
addEdge(graph, 0, 1);
addEdge(graph, 0, 2);
addEdge(graph, 1, 2);
addEdge(graph, 1, 3);
addEdge(graph, 2, 4);
addEdge(graph, 3, 4);
addEdge(graph, 4, 5);
addEdge(graph, 5, 6);
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
stack<int> s;
int node = 0;
int i = 0;
vector<int> visited(7,0);

visited[i] = 1;
s.push(i);
while(!s.empty()){
    int node = s.top();s.pop();
    cout<<node<<" ";
    for(int j =0;j<7;j++){
        if(arr[node][j] == 1 && visited[j] == 0){
            
            visited[j] = 1;
            s.push(j);
        }
    }
}
return 0;


}