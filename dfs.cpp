#include <iostream>
#include <climits>
#include <vector>
#include <stack>
using namespace std;

const int N = 1000;
vector<int> adj[N];
int vis[N]; 

void dfs_iter(int v){
    stack<int> s;

    s.push(v);
    vis[v] = 1;

    while(!s.empty()){
        int curr_node = s.top();
        s.pop();
        cout << curr_node << " ";
        for(auto neighbor : adj[curr_node]){
            if(vis[neighbor] == -1){
                vis[neighbor] = 1;
                s.push(neighbor);
            }
        }
        
    }
}
void dfs(int v){
    vis[v] = 1;

    cout << v << " ";
    vector<int> :: iterator i;
    
    for(i = adj[v].begin(); i != adj[v].end(); i++){
        if(vis[*i] == -1){
            dfs(*i);
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        vis[i] = -1;
    }

    int v, w;
    for(int i = 0; i < m; i++){
        cin >> v >> w;
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    cout << "wich vertex do you want to start?" << endl;
    int vertex;
    cin >> vertex;
    dfs(vertex); // recursive dfs
    dfs_iter(vertex);// dfs using a stack
    cout << endl;
}