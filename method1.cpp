#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Using kahn Algorithm
vector<int> safeNodes(int V, vector<vector<int>>& edges) {
    vector<int>inDegree(V, 0);
    vector<int>temp;
    vector<vector<int>> revAdj(V, temp);
    for(int i = 0; i < edges.size(); i++){
        int src = edges[i][0];
        int dest = edges[i][1];
        revAdj[dest].push_back(src);
        inDegree[src]++;
    }
    queue<int>q;
    for(int i = 0; i < V; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        for(int i = 0; i < revAdj[q.front()].size(); i++){
            inDegree[revAdj[q.front()][i]]--;
            if(inDegree[revAdj[q.front()][i]] == 0){
                q.push(revAdj[q.front()][i]);
            }
        }
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}