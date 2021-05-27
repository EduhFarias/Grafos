#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int getMinDist(vector<int> dist, vector<bool> set, int v){
	int min = INT16_MAX;
	int index;
	for(int i=0; i < v; i++){
		if(set[i] == false && dist[i] <= min){
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void print(vector<int> dist, vector<int> prev, int v){
	cout << "i " << "dist " << "prev\n";
	for(int i = 0; i < v; i++){
		cout << i << " " << dist[i] << " " << prev[i] <<  endl;
	}
}

void dijkstra(vector<vector<int>> graph, int v, int src){
	vector<int> dist(v,INT16_MAX);
	dist[src] = 0;
	vector<int> prev(v, -1);
	vector<bool> set(v,false);
	int i, j;
	for(i = 0; i < v; i++){
		int vertex = getMinDist(dist, set, v);
		set[vertex] = true;
		for(j = 0; j < v; j++){
			if(!set[j] && graph[vertex][j] != 0 && dist[vertex] != INT16_MAX && dist[vertex] + graph[vertex][j] < dist[j]){
				dist[j]=dist[vertex]+graph[vertex][j];
				prev[j] = vertex;
			}
		}
	}
	print(dist, prev, v);
}

int main() {
  	fstream newfile;
	newfile.open("grafo_com_peso.dat", ios::in);  
	int V, E, i, line;
	vector<int> a;
	while(newfile >> line){
		a.push_back(line);
	}
	V = a[0], E = a[1];
	vector<vector<int>> graph; 
	
	for(i = 0; i < V; i++){
		vector<int> row;
		for(int j = 0; j<V;j++){
			if(i == j) row.push_back(0);
			else row.push_back(INT16_MAX);
		}
		graph.push_back(row);
	}	
	//Adicionando os pesos as arestas
	for(i = 0; i < E; i++){
		graph[a[2+(i*3)]][a[3+(i*3)]] = a[4+(i*3)];
	}
	dijkstra(graph, V, 0);
	newfile.close();
}
