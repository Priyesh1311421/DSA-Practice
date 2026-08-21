#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[]){
    int vis[v] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    vector<int> answer;
    while(!q.empty()){
        int node = q.front();
        answer.push_back(node);
        q.pop();
        for(auto x: adj[node]){
            if(!vis[x]){
                q.push(x);
                vis[x] = 1;
            }
        }
    }

    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v = 5;
    vector<int> adj[v];
    
    // Hardcoded adjacency list from input
    adj[0] = {2, 3, 1};
    adj[1] = {};
    adj[2] = {0, 4};
    adj[3] = {0};
    adj[4] = {2};

    vector<int> ans = bfsOfGraph(v, adj);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}