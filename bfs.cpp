#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 1000;
vector<int> adj[N];
int vis[N];

void bfs(int v){
    queue<int> q;

    q.push(v);
    vis[v] = 1;

    while(!q.empty()){
        int curr_node = q.front();
        cout << curr_node << " ";

        q.pop();

        for(auto neighbor : adj[curr_node]){
            if(vis[neighbor] == -1){
                vis[neighbor] = 1;
                q.push(neighbor);
            }
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
    bfs(vertex);
    cout << endl;
}