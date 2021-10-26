#include<bits/stdc++.h>

using namespace std;

class Graph{
	int V;
	list<int> *adj;	//pointer to lists	//therefore adj is adjencency matrix
public:
	Graph(int V);
	void addedge(int v, int w);
	void bfs(int s);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];//[this->V];		//adj points to total of 'V' lists
}

void Graph::addedge(int v, int w){		//undirected graph
	adj[v].push_back(w);
	//adj[w].push_back(v);
}

void Graph::bfs(int s){
	list<int> queue;
	vector<bool> visited(V,false);

	queue.push_back(s);
	visited[s] = true;
	list<int>::iterator it;

	while(!queue.empty()){

		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		for(it = adj[s].begin(); it!=adj[s].end();++it){
			if(!visited[*it]){
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
	}
}

int main(){
	ifstream file("graph_file.txt");
	string str;
	getline(file,str);
	int n = stoi(str);
	Graph g(n);
	
	int v,w;
	for(int i=0;i<n;i++){
		getline(file,str);
		stringstream ss(str);
		ss >> v >> w;
		cout << v << " " << w << endl;
		g.addedge(v,w);
	}
	g.bfs(1);
	return 0;
}