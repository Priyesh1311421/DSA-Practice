#include<bits/stdc++.h>
using namespace std;


class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node){
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int p_u = findParent(u);
        int p_v = findParent(v);

        if (p_u == p_v) return;

        if (rank[p_u] < rank[p_v]) {
            parent[p_u] = p_v;
        }
        else if (rank[p_v] < rank[p_u]) {
            parent[p_v] = p_u;
        }
        else {
            parent[p_v] = p_u;
            rank[p_u]++;
        }
    }

    void unionBySize(int u, int v){
        int p_u = findParent(u);
        int p_v = findParent(v);

        if (p_u == p_v) return;

        if (size[p_u] < size[p_v]) {
            parent[p_u] = p_v;
            size[p_v] += size[p_u];
        }
        else {
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
    }
};

int main(){
    int n = 7;
    DisjointSet ds(n);

    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {4, 5},
        {5, 6},
        {6, 7}
    };

    vector<vector<int>> graph(n + 1);

    for (const auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
        ds.unionBySize(u, v);
    }

    cout << "Graph after DSU operations:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    cout << "\nChecking connectivity before connecting 3 and 7:" << endl;
    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same" << endl;
    } else {
        cout << "Not Same" << endl;
    }

    cout << "After connecting 3 and 7 -----> " << endl;
    ds.unionBySize(3, 7);

    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same" << endl;
    } else {
        cout << "Not Same" << endl;
    }

    return 0;
}

