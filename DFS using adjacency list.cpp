#include <bits/stdc++.h>
#include<string.h>
#include<map>
#include <vector>
#include <list>
#include <algorithm> 
using namespace std;
vector<list<int>> adjList;   
vector<bool> visited;        
void initializeGraph(int nodes) {
    adjList.resize(nodes);
    visited.resize(nodes, false);
}
void addEdge(int src, int dest) {
    adjList[src].push_back(dest);   
    adjList[dest].push_back(src);  
}
void dfs(int vertex) {
    visited[vertex] = true;        
    cout << vertex << " ";          
    for (int adjVertex : adjList[vertex]) {
        if (!visited[adjVertex]) {
            dfs(adjVertex);
        }
    }
}
void resetVisited(int nodes) {
    fill(visited.begin(), visited.begin() + nodes, false);
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> edges;
    initializeGraph(nodes);
    cout << "Enter the edges :"<<endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    int startNode;
    cout << "Enter the start node: ";
    cin >> startNode;
    cout << "DFS Traversal: "<<endl;
    dfs(startNode);

    return 0;
}

