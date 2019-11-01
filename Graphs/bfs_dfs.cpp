//working code

#include <bits/stdc++.h>

using namespace std;

//graph indices starting from 0
class Graph {
	public:
	int numberOfVertices;
	//represents array of list
	//you can take vector of vetors also
	list<int> *edges;
	
	Graph(){}
	Graph(int v) {
		numberOfVertices = v;
		edges = new list<int>[numberOfVertices];
	}
	
	void addEdge(int a, int b) {
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
};

//1. BFS traversal using queues
void bfs(int n, Graph graph) {
	list<int> queue;
	queue.push_back(n);
	
	int visited[graph.numberOfVertices];
	for(int i=0;i<graph.numberOfVertices;i++) visited[i]=false;
	
	while(!queue.empty()) {
		int nodeValue = queue.front();
		cout<<nodeValue<<" ";
		queue.pop_front();
		visited[nodeValue]=true;
		for(auto it=graph.edges[nodeValue].begin();it!=graph.edges[nodeValue].end();it++) {
			if(!visited[*it]) queue.push_back(*it);
		}
	}
}

//2. DFS using stack
void dfs(int n, Graph graph) {
	int visited[graph.numberOfVertices];
	for(int i=0;i<graph.numberOfVertices;i++) visited[i]=false;
	
	stack<int> stk;
	
	stk.push(n);
	while(!stk.empty()) {
		int nodeValue = stk.top();
		stk.pop();
		cout<<nodeValue<<" ";
		visited[nodeValue]=true;
		for(auto it=graph.edges[nodeValue].begin();it!=graph.edges[nodeValue].end();it++) {
			if(!visited[*it]) stk.push(*it);
		}
		
	}
}

//3. DFS using recursion stack
void dfs_recursive(int n, Graph graph, bool visited[]) {
	cout<<n<<" ";
	visited[n]=true;
	for(auto it=graph.edges[n].begin();it!=graph.edges[n].end();it++) {
		if(!visited[*it]) dfs_recursive(*it, graph, visited);
	}
}

int main() {
	
	Graph graph = Graph(5);
	graph.addEdge(1,2);
	graph.addEdge(2,4);
	graph.addEdge(0,3);
	graph.addEdge(3,2);
	
	cout<<"BFS: ";
	bfs(2, graph);
	
	//for DFS
	cout<<"\nDFS(Stacks): ";
	dfs(0, graph);
	
	cout<<"\nDFS(Recursive): ";
	bool visited[graph.numberOfVertices];
	for(int i=0;i<graph.numberOfVertices;i++) visited[i]=false;
	dfs_recursive(0, graph, visited);
	
	
	return 0;
}