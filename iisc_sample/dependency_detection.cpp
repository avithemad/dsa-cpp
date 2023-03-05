#include <iostream>
#include <unordered_map>
#include <utility>
#include <queue>
using namespace std;

struct Right
{
	int value;
	bool visited;
};

bool allNotVisited(unordered_map<int, Right > graph);
int getNextUnvisitedNode(unordered_map<int, Right> graph);

int main()
{
	// pair, int is for edge 2 and bool is for whether its visited or not
	unordered_map<int, Right> graph;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int e1, e2;
		cin >> e1 >> e2;
		Right right;
		right.value = e2;
		right.visited = false;
		graph[e1] = right;
	}

	while(allNotVisited(graph)) 
	{
		queue<int> dfs_queue;
		int unvisitedNode = getNextUnvisitedNode(graph);
		dfs_queue.push(unvisitedNode);
		int r = graph[unvisitedNode].value;
		dfs_queue.push(r);
		graph[unvisitedNode].visited = true;
		if (dfs_queue.front() == dfs_queue.back()) {
			cout << "Cycle detected";
			return 0;
		}
		while(dfs_queue.front() != dfs_queue.back() 
			&& (graph.find(r) != graph.end())) {\
			dfs_queue.push(graph[r].value);
			graph[r].visited = true;
			r = graph[r].value;

			if(dfs_queue.front() == dfs_queue.back()){
				cout << "Cycle detected";
				return 0;
			}
		}
	}
	cout << "No cycles found";
}

int getNextUnvisitedNode(unordered_map<int, Right> graph){
	for (auto i: graph) {
		if (!i.second.visited) {
			return i.first;
		}
	}
	return -1;
}

bool allNotVisited(unordered_map<int, Right> graph)
{
	bool allVisited = true;
	for (auto i: graph) {
		if (!i.second.visited) {
			allVisited = false;
		}
	}
	return !allVisited;
}