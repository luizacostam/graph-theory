/*
Euler Circuit: 
    i) Starts and ends at the same node
    ii) Every edge must be visited only once

Euler Graph: a graph having a euler circuit
    i) All edges in a graph must be presented in a single component
    ii) All other components should not have any edge and therefore shoud be of size 1-vertex only
    These conditions can be simplified into a condition: all vertices should have even degree
    !! a graph with no edge is a euler graph !!

Semi-Eulerian Graph: every edge is visited exactly once, but start and end nodes are different
    i) exactly 2 vertices have odd degree (start and end vertex)
    ii) all vertices with non-zero degree are connected

algorithm steps: https://pastebin.com/1F2GmYyH
*/

#include <bits/stdc++.h>
using namespace std;
#define V 5

unordered_map<int, vector<int>> adj;

void DFS(int curr, vector<bool>& visited){
    visited[curr] = true;
    for(auto it: adj[curr]){
        if(!visited[it]){
            DFS(it, visited);
        }
    }
}
bool connected_graph(){
    vector<bool> visited(V+1, false);
    int node = -1; //node that starts DFS
    
    //looking for a node with degree greater than zero
    for(int i = 0; i < V; i++){
        if(adj[i].size() > 0){
            node = i; //node starting DFS
            break;
        }
    }
    if(node == -1) return true; //no start node was found => the graph has no edges => eulerian graph
    DFS(node, visited);
    //checking if all the non-zero vertices are visited
    for(int i = 0; i < V; i++){
        if(visited[i] == false and adj[i].size()>0){
            return false; //the graph has edges in multi-component
        }
    }
    return true;
}
int find_euler(){
    if(!connected_graph()){ //multi-component edged graph
        return 0;
    }
    int odd = 0; //count odd-degree vertices
    for(int i = 0; i < V; i++){
        if(adj[i].size() & 1){
            odd++;
        }
    }
    if(odd > 2) return 0; //only start and end node can have odd degree
    return odd == 0 ? 2 : 1;

} 
void findEuler_Path_Cycle(){
    int ans = find_euler();
    if(ans == 0) cout << "Graph is NOT a euler graph" << endl;
    else if(ans == 1) cout << "Graph is Semi-Eulerian" << endl;
    else if(ans == 2) cout << "Graph is Eulerian (has a euler circuit)" << endl;
}
int main(){
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[1].push_back(2);
    adj[0].push_back(3);
    adj[3].push_back(0);
    adj[3].push_back(4);
    adj[4].push_back(3);

    findEuler_Path_Cycle();
}