#include<bits/stdc++.h>
using namespace std;

void func(int v,vector<long long> init, vector<vector<int> > adj){
	/////////////////////////

	// cout << "init vector:" << endl;
	// for(int i=0;i<init.size();i++){
	// 	cout << init[i] << " ";
	// }
	// cout << endl << endl;


	// cout << "adj vector:"<< endl;
	// for(int i=0;i<adj.size();i++){
	// 	cout << "i = " << i << " ";
	// 	for(int j=0;j<adj[i].size();j++){
	// 		cout << adj[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	//////////////////////////
	vector<int> color(init.size(),-1);	//no colors

	queue<pair<int,int> > q;
	q.push({v,0});
	color[v] = 0;

	while(!q.empty()){
		pair<int,int> p = q.front();
		q.pop();
		int v = p.first;
		int c = p.second;

		for(int j:adj[v]){
//			cout << "adj[v]..., v = " << j << " " << c << endl; 
			if(color[j] == c){
				//not bipartite
				long sum = 0;
				for(auto i:init)
					sum += i;

				if(sum % 2 == 0){
					cout << "YES" << endl;
					return;
				}
				else if(sum % 2 == 1){
					cout << "NO" << endl;
					return;
				}
			}
			if(color[j] == -1){
				if(c==0){
					//color 1 for this adj[v][i]
					color[j] = 1;
					q.push( {j,1} );
				}
				else{//(c==1)
					color[j] = 0;
					q.push( {j,0} );
				}
			}
		}
	}
	//graph is bipartite

	long long r=0,b=0;
	for(int i=0;i<color.size();i++){
		if(color[i]==0)
			r += init[i];
		if(color[i]==1)
			b += init[i];
	}
	//cout << "r,b" << r << " " << b << endl;
	if(r==b){
		cout << "YES" << endl;
		return;
	}
	else{
		cout << "NO" << endl;
	}
	return;
}


int main(){
	// ifstream file("graph_file.txt");
	// string str;
	// getline(file,str);
	// int t = stoi(str);

	// while(t--){
	// 	getline(file,str);
	// 	int n,m;
	// 	stringstream ss(str);
	// 	ss >> n >> m;

	// 	vector<long long> init(n);
	// 	vector<long long> final(n);

	// 	getline(file,str);
	// 	stringstream ss1(str);
	// 	for(int i=0;i<n;i++)
	// 		ss1 >> init[i];
		
	// 	getline(file,str);
	// 	stringstream ss2(str);
	// 	for(int i=0;i<n;i++)
	// 		ss2 >> final[i];

	// 	int x,y;
	// 	string s1,s2;
	// 	vector<vector<int> > adj(n);
	// 	for(int i=0;i<m;i++){
	// 		getline(file,str);
	// 		stringstream ss(str);
	// 		ss >> s1 >> s2;
	// 		//cout << "s1,s2 " << s1 << " " << s2 << endl;
	// 		x = stoi(s1);
	// 		y = stoi(s2);
	// 		//cout << "x,y " << x << " " << y << endl;
	// 		adj[x-1].push_back(y-1);
	// 		adj[y-1].push_back(x-1);
	// 	}

	// 	for(int i=0;i<init.size();i++){
	// 		init[i] = init[i] - final[i];
	// 		final[i] = 0;
	// 	}
	// 	func(adj[0][0],init,adj);
	// }


	int t;
	cin >> t;

	while(t--){
		int n,m;
		cin >> n >> m;
		vector<long long> init(n);
		vector<long longS> final(n);

		for(int i=0;i<n;i++)
			cin >> init[i];
		for(int i=0;i<n;i++)
			cin >> final[i];

		int x,y;
		vector<vector<int> > adj(n);

		for(int i=0;i<m;i++){
			cin >> x >> y;
			//cout << "here " << endl;
			adj[x-1].push_back(y-1);
			adj[y-1].push_back(x-1);
			//cout << "here1" << endl;
		}

		for(int i=0;i<init.size();i++){
			init[i] = init[i] - final[i];
			final[i] = 0;
		}
		func(adj[0][0],init,adj);
	}
	return 0;
}