#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> graph[INT8_MAX];

void print(vector<int>& prev, vector<int>& cost, int V){
	cout << "Aresta  Peso\n";
	for(int i = 1; i < V; i++){
		cout << prev[i] << " -> " << i << "\t " << cost[i] << endl;
	}
}

void prim(int V, int src){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p_q;
	vector<int> cost(V,INT16_MAX);
	vector<int> prev(V,-1);
	vector<bool> set(V,false);
	pair<int,int> p;
	int v;
	int v_aux;
	int w_aux;

	cost[src] = 0;
	p_q.push(make_pair(src, 0));

	while(!p_q.empty()){
		p = p_q.top();
		p_q.pop();
		v = p.first;
		set[v] = true;
		for(int i = 0; i < graph[v].size(); i++){
			v_aux = graph[v][i].first;
			w_aux = graph[v][i].second;
			if(set[v_aux] == false && (w_aux < cost[v_aux]) ){
				prev[v_aux] = v;
				cost[v_aux] = w_aux;
				p_q.push(graph[v][i]);
			}
		}
	}
	print(prev, cost, V);
}

int main() {
	int V, E, src, dest, w;
	cin >> V >> E;
	
	for(int i = 0; i < E; i++){
		cin >> src >> dest >> w;
		graph[src].push_back(make_pair(dest,w));
		graph[dest].push_back(make_pair(src,w));
	}
	
	prim(V, 0);
}
