#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int s,vector<int> init, vector<vector<int> > adj){
	int r=0, b=0, n=init.size();



	vector<int> color(n+1,-1);		//-1 is no color, 0 red, 1 blue
	queue<pair<int,int> > q;

	q.push({s,0});
	color[s] = 0;
	r += 1;

	cout << endl << adj.size() << endl;

	while(!q.empty()){
		cout << "r,b :: " << r << ", " << b << endl; 
		pair<int,int> p = q.front();
		q.pop();
		int x,c;
		x = p.first;
		c = p.second;

		for(int i=1;i<=adj.size();i++){
			cout << "color[i] :: c = " <<color[i] << " "<< c << endl;
			if(color[adj[v]] == c){
				return 0;
			}
			if(color[adj[i]] == -1){
				color[adj[i]] = c ? 0:1;
				if(color[adj[i]]==0)
					r += 1;
				else
					b += 1;
				q.push( { i,color[adj[i]]} );
			}
		}
	}
	cout << "r,b ::" << r << "," << b<<endl;
	if(r == b){
		cout << "r==b  ";
		cout << "YES" << endl;
	}
	else{
		cout << "r!==b ";
		cout << "NO" << endl;
	}

	return true;
}

int main(){
	int t;
	cin >> t;
	while(t-- > 0){
		int n,m;
		cin >> n >> m;

		vector<int> init(n);
		for(int i=0;i<n;i++)
			cin >> init[i];

		vector<int> final(n);
		for(int i=0;i<n;i++)
			cin >> final[i];

		vector<vector<int> > adj(n+1);
		int u,v;
		for(int i=1;i<=m;i++){
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for(int i=1;i<adj.size();i++){
			for(int j=0;j<adj[i].size();j++){
				cout << i <<","<< j<<","<< adj[i][j] << "   ";
			}
			cout << endl;
		}

		for(int i=0;i<n;i++){
			init[i] = init[i] - final[i];
			final[i] = 0;
		}

		if(isBipartite(1,init, adj)){
			continue;
		}
		else{
			int sum = 0;
			for(int i:init)
				sum += i;
			if(sum % 2 == 0){
				cout << "even sum ";
				cout << "YES" << endl;
			}
			else{
				cout << "odd sum ";
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}