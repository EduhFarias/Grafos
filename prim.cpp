#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

void print(vector<int> custo, vector<int> prev, int v){
	cout << "Custo " << "Prev " << "Vert" << endl;
	for(int i = 0; i < v; i++){
		cout << custo[i] << " " << prev[i] << " " << i << endl;
	}
}

void prim(vector<vector<int>> graph, int v, int src){
	vector<int> custo(v,INT16_MAX);
	vector<int> prev(v,-1);
	vector<bool> set(v,false);
	custo[src] = 0;
	int i, j;
	for(i = 0; i < v; i++){
		int vertex, min = INT16_MAX;
		for(int k = 0; k < v; k++){
			if(set[k] == false && custo[k] <= min){
				min = custo[k];
				vertex = i;
			}
		}
		set[vertex] = true;
		for (j = 0; j < v; j++){  
            if (graph[vertex][j]!=0 && set[j] == false && graph[vertex][j] < custo[j]){
				custo[j] = graph[vertex][j];
				prev[j] = vertex;
			}   
		}	
	}print(custo, prev, v);
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
	prim(graph, V, 0);
	newfile.close();
}
