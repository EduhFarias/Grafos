#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

int V;

void print_path(int prev[], int i){
	if(prev[i] == -1){
		cout << i << " ";
		return;
	} 
	print_path(prev, prev[i]);
	cout << i << " ";
}

bool bfs(vector<vector<int>>& resGraph, int s, int t, int prev[]){
    vector<bool> visited(V,false);
 
    queue<int> q;
    q.push(s);
    visited[s] = true;
    prev[s] = -1;
 
    while (!q.empty()) {
        int v = q.front();
        q.pop();
 
        for (int i = 0; i < V; i++) {
            if (visited[i] == false && resGraph[v][i] > 0) {
                q.push(i);
                prev[i] = v;
                visited[i] = true;
            }
        }
    }
	  if(visited[t] == true) return true;
    return false;
}
 
void fordFulkerson(vector<vector<int>>& graph, int s, int t){
	vector<vector<int>> resGraph = graph;
    int prev[V];
 
    int max_flow = 0;
 
    while (bfs(resGraph, s, t, prev) == true) {
		int flow = INT_MAX;
        for (int v = t; v != s; v = prev[v]) {
            int u = prev[v];
            flow = min(flow, resGraph[u][v]);
        }
 
        for (int v = t; v != s; v = prev[v]) {
            int u = prev[v];
            resGraph[u][v] -= flow;
            resGraph[v][u] += flow;
        }
        max_flow += flow;
    }
	  print_path(prev, t);
    cout << "\nO fluxo máximo é de:  " << max_flow << endl;
}

int main(){
	
	int E, src, dest, p;
  cin >> V >> E;
	vector<vector<int>> graph(V,vector<int>(V,0));
	for(int i = 0; i < E; i++){
		cin >> src >> dest >> p;
		graph[src][dest] = p;
	}
	int s, t;
	cout << "Entre com um vértice fonte e outro sumidouro: s t" << endl;
	cin >> s >> t;
    fordFulkerson(graph, s, t);
 
    return 0;
}
