#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
  	fstream newfile;
	newfile.open("grafo_com_peso.dat", ios::in);  
	int V, E, i, line;
	vector<int> a;
	while(newfile >> line){
		a.push_back(line);
	}
	V = a[0], E = a[1];
	int graph[V][V], pi[V][V];
	
	for(i = 0; i < V; i++){
		for(int j = 0; j<V;j++){
			if(i == j) graph[i][j] = 0;
			else graph[i][j] = INT16_MAX;
			pi[i][j] = 0;
		}
	}
	//Adicionando os pesos as arestas
	for(i = 0; i < E; i++){
		graph[a[2+(i*3)]][a[3+(i*3)]] = a[4+(i*3)];
	}
	//Inicia a matriz pi
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			if(i == j || (graph[i][j] == INT16_MAX)) pi[i][j] = 0;
			else pi[i][j] = i+1;
		}
	}
	// FLOYD-WARSHALL
	for(int k = 0; k < V; k++){
		for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				if(graph[i][k]!=INT16_MAX && graph[k][j]!=INT16_MAX){
					//graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
					if((graph[i][k]!=INT16_MAX && graph[k][j]!=INT16_MAX) && graph[i][j] > graph[i][k] + graph[k][j]){
						graph[i][j] = graph[i][k] + graph[k][j];
						pi[i][j] = k;
					}
				}				
			}
		}
	}
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			if(graph[i][j] == INT16_MAX) cout << "inf ";
			else cout << graph[i][j] << "   ";
		}cout << "\n";
	}cout << "\n";

	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			if(pi[i][j] == 0) cout << "nil ";
			else cout << pi[i][j] << "   ";
		}cout << "\n";
	}
	newfile.close();
}
