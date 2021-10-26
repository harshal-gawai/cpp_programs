#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin  >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long> v(n);
		for(int i=0;i<n;i++)
			cin >> v[i];

		long long marx = v[0] * v[1];
		//long long mini, maxi;
		// long long mini1 = v[1],maxi1 = v[1];
		// if(v[0] < v[1]){
		// 	mini = v[0];
		// 	maxi = v[1];
		// }
		// else{
		// 	mini = v[1];
		// 	maxi = v[0];
		// }


		long long l=0,r=1;
		while(l<n-1 && r <= n-1){
			//cout << v[l] << " " << v[r] << " " << maxi << " " << mini << " " << marx << endl;
			marx = max(marx,v[l]*v[l+1]);
			l++;
		}

		cout << marx << endl;
	}
	return 0;
}