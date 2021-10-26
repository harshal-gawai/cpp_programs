#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;

void bfs(int node){
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while(!q.empty()){
		node = q.front();
		//cout << "node =" << node << endl;
		q.pop();
		cout << node << " ";
		for(int i=0;i<adj[node].size();i++){
			if(visited[adj[node][i]] == false){
				q.push(adj[node][i]);
				visited[adj[node][i]] = true;
			}
		}
	}
	cout << endl;
	return;
}

//"graph_file.txt"
int main(){
	ifstream file("graph_file.txt");
	string str;
	getline(file,str);
	int n = stoi(str), u, v;

	adj.resize(n+1);
	visited.resize(n+1);

	while(n--){
		getline(file,str);
		stringstream ss(str);
		ss >> u >> v;

		//cout << "u,v :: " << u << "," << v << endl;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(1);
	return 0;
}