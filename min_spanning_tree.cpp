#include<bits/stdc++.h>
using namespace std;

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


int main(){
unordered_map<int, vector<pair<int,int>>> graph;
addEdge(graph, 0, 2,8);
addEdge(graph, 0, 5,17);
addEdge(graph, 0, 4,13);
addEdge(graph, 1, 2,20);
addEdge(graph, 1, 6,6);
addEdge(graph, 2, 3,11);
addEdge(graph, 3, 4,12);
addEdge(graph, 4, 5,15);
addEdge(graph, 5, 6,18);
printGraph(graph);
int arr[7][7];
bool found = false;
for(int i=0;i<7;i++){
    for(int j=0;j<7;j++){
        found = false;
        for (const auto& p : graph[i]) {
            if (p.first == j) {
                 found = true;
                break;
            }
        }
        if(found){
            arr[i][j] = graph[i][j].second;
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


    

return 0;


}