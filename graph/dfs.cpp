#include<iostream>
#include<vector>
using namespace std;

void insertEdge(vector<int> *graph, int edge[2]) {
	bool present = false;
	for(int ver: graph[edge[0]]) 
		if (ver == edge[1]) present = true;

	if (!present) graph[edge[0]].push_back(edge[1]);

	present = false;
	for(int ver: graph[edge[1]]) 
		if (ver == edge[0]) present = true;

	if (!present) graph[edge[1]].push_back(edge[0]);
}

void printGraph(vector<int> *graph, int v){
	for (int i=0; i<v; i++){
		cout << i << "->";
		for (int ver: graph[i])
			cout << ver << " ";
		cout << "\n";
	}
}

void dfs(vector<int> *graph, int vertex, bool* visited){
	visited[vertex] = true;
	cout << vertex << " ";
	
	for(int v: graph[vertex]) {
		if (!visited[v]){
			dfs(graph, v, visited);
		}
	}
}

bool allNotVisited(bool *visited, int size){
	for(int i=0; i< size; i++) if (!visited[i]) return true;
	return false;
}

int main() {
	int e, v;
	cout << "Number of edges: ";

	cin >> e;
	cout << "Number of vertex: ";
	
	cin >> v;
	int edges[e][2];

	for (int i=0; i<e; i++){
		cin >> edges[i][0] >> edges[i][1];
	}

	vector<int> graph[v];

	for (int i=0; i<e; i++){
		insertEdge(graph, edges[i]);
	}

	cout << "Graph in adjacency list: \n";
	printGraph(graph, v);

	bool visited[v];
	for (int i=0; i<v; i++) visited[i] = false;

	cout << "Graph in DFS:";

	while(allNotVisited(visited, v)){
		int nodeToVisit = 0;
		for (int i=0; i<v; i++){
			if (visited[i] == false) {
				nodeToVisit = i;
				break;
			}
		}
		dfs(graph, nodeToVisit, visited);
		cout << "\nNext island\n";
	}
}