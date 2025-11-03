#include<iostream>
#include<vector>
using namespace std;

// dfs method
bool safeNodes(int V, vector<vector<int>>& adj, int vertex, vector<bool>& visited, vector<bool>& safe, vector<int>& ans){
    if(safe[vertex]){
        return true;
    }
    if(adj[vertex].size() == 0){
        ans.push_back(vertex);
        safe[vertex] = true;
        visited[vertex] = true;
        return true;
    }
    if(visited[vertex]){
        return false;
    }
    visited[vertex] = true;
    bool add = true;
    for(int i = 0; i < adj[vertex].size(); i++){
        
        bool temp = safeNodes(V, adj, adj[vertex][i], visited, safe, ans);
        if(temp == false){
            add = false;
        }
    }
    if(add){
        ans.push_back(vertex);
        safe[vertex] = true;
        return true;
    }
    return false;
}


vector<int> safeNodes(int V, vector<vector<int>>& edges) {
    vector<int>temp;
    vector<vector<int>> adj(V, temp);
    for(int i = 0; i < edges.size(); i++){
        int src = edges[i][0];
        int dest = edges[i][1];
        adj[src].push_back(dest);
    }
    vector<bool>visited(V, false);
    vector<bool>safe(V, false);
    vector<int>ans;
    for(int i = 0; i < V; i++){
        bool add = safeNodes(V, adj, i, visited, safe, ans);
    }
    return ans;
}