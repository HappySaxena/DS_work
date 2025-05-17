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
void printpath(int i,int j,vector<vector<int>>& arr2){
    if(arr2[i][j] == -1){
        cout << i << " ";
        cout << j <<" ";
        return;
    }
    printpath(i,arr2[i][j],arr2);
    cout << j << " ";
}
int main(){
unordered_map<int,vector<pair<int,int>>>graph;
addEdge(graph, 0, 1,4);
addEdge(graph, 0, 2,5);
addEdge(graph, 1, 0,2);


addEdge(graph, 2, 1,-3);
// addEdge(graph, 2, 3,4);
// addEdge(graph, 2, 4,3);
// addEdge(graph, 3, 4,7);
// addEdge(graph, 3, 0,2);
// addEdge(graph, 4, 2,-2);

printGraph(graph);
int arr[3][3];

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        auto it = std::find_if(graph[i].begin(), graph[i].end(),
[j](pair<int, int>& p) {
    return p.first == j;

});
if(it != graph[i].end()){
            arr[i][j] = it->second;
        }
        else if(i==j){
           arr[i][j] = 0;
        }
        else{
            arr[i][j] = 100000;
        }
    }
}
 vector<vector<int>> arr2(3,vector<int>(3,-1));
for(int i = 0;i<3;i++){
    for(int j = 0;j<3;j++){
        for(int k = 0;k<3;k++){
            if(i!= j && i!=k && j!=k){
                if((arr[j][i] + arr[i][k]) < arr[j][k]){
                    arr[j][k] = arr[j][i] + arr[i][k];
                    arr2[j][k] = i;
                }
            }
        }
    }
}
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cout << arr[i][j] << " ";
    }
    cout << endl;
}
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cout << arr2[i][j] << " ";
    }
    cout << endl;

}

printpath(0,1,arr2);
}