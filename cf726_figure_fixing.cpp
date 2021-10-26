#include<bits/stdc++.h>
using namespace std;

// bool sortcol(const vector<int> &v1, const vector<int> &v2){
// 	return v1[0] < v2[0];
// }

// void func(int m,int n, vector<int> init, vector<int> final, vector<vector<int> > edges){
// 	for(int i=0;i<edges.size();i++)
// 		sort(edges[i].begin(),edges[i].end());
	
// 	sort(edges.begin(),edges.end(), sortcol);
// 	for(int i =0;i<edges.size();i++){
// 		cout << edges[i][0] << " " << edges[i][1] << endl;
// 	}
// 	return;
// }

// vector<int> init;
// vector<int> final;
// vector<vector<int> > adj;
// vector<int> color;
// int r=0,b=0;

bool bfs(int node, vector<int> init, vector<vector<int> > adj, vector<int> color){
		for(auto i:init)
			cout << i << " ";
		cout << endl;
	for(auto i:final)
		cout << i << " ";
	cout << endl;

	cout << "size of adj" << adj.size() << " * " << adj[0].size() << endl; 
	for(int i=0;i<init.size();i++){
		cout << adj[i][0] << " " << adj[i][1] << endl;
	}

	r = 0;b = 0;
	for(int i=0;i<init.size();i++){
		init[i] = init[i] - final[i];
		final[i] = 0;
	}

	queue<pair<int,int> > q;
	q.push({node,0});
	color[node] = 0;	//red
	r += 1;

	while(!q.empty()){
		pair<int,int> p = q.front();
		//cout << "node =" << node << endl;
		q.pop();
		//cout << node << " ";
		node = p.first;
		int c = p.second;

		for(int j:adj[node]){
			if(color[j] == c)
				return 0;
			if(color[j] == -1){
				color[j] = c ? 0:1;
				if(color[j]==0)
					r += 1;
				else
					b += 1;
				q.push( { j,color[j]} );
			}
		}
	}
	
	return 1;
}

int main(){
	int t;
	cin >> t;

	int m,n,a,b;
	// vector<int> init;
	// vector<int> final;
	// vector<vector<int> > edges(n,vector<int>(2));

	while(t-- > 0){
		init.clear();
		final.clear();
		adj.clear();
		color.clear();

		cin >> n >> m;	//n - no. of nodes	//m - no of edges
		color.resize(n+1,-1);

		for(int i=0;i<n;i++){
			cin >> a;
			init.push_back(a);
		}
		for(int i=0;i<n;i++){
			cin >> a;
			final.push_back(a);
		}
		
		adj.resize(m+1);
		for(int i=0;i<m;i++){
			adj[i].resize(2);
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bool ans = bfs(1);
		if(ans && r==b){
			cout << "YES" << endl;
		}
		int sum = 0;
		for(int i: init)
			sum += i;
		if(!ans && sum % 2 == 0)
			cout << "YES" << endl;
		if(!ans && sum % 2 == 1){
			cout << "not bipartite and odd" << endl;
			cout << "NO" << endl;
		}
		else{
			cout << "else NO" << endl;
			cout << "NO" << endl;
		}
	}
	return 0;
}