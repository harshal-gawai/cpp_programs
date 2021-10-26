#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> present(m+1,0);

	for(int i=0;i<=m;i++){
		cout << n << " " << i << " " << (n^i) << endl;
		present[(n^i)] = 1;
	}
	cout << min_element(present.begin(),present.end()) - present.begin()<< endl;
	return;
}

int main(){
	int tc;
	cin >> tc;
	cout << (3^5) << endl;
	while(tc--){
		int n,m;
		cin >> n >> m;
		vector<int> present(m+1,0);

		for(int i=0;i<=m;i++){
			cout << n << " " << i << " " << (n^i) << endl;
			present[(n^i)] = 1;
		}
		cout << min_element(present.begin(),present.end()) - present.begin()<< endl;
		present.erase(present.begin(),present.end());
	}
	return 0;
}