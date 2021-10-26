#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define fo(i,n) for(int i=0;i<n;i++)

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		//cout << "here"<<t << endl;
		ll n,k;
		cin >> n >> k;

		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}

		if(n==2){
			cout << 2-k*(v[0]|v[1])<<endl;
			continue;
		}
		ll marx = LLONG_MIN;

		for(ll i=max((ll)0,n-201);i<n;i++){
			for(ll j=i+1;j<n;j++){
				marx = max(marx,(i+1)*(j+1) - k*(v[i]|v[j]));
			}
		}

		// for(ll i=n-2;i>=0 && i>n-300;i--){
		// 	for(ll j=n-1;j>i;j--){
		// 		marx = max(marx,(i+1)*(j+1) - k*(v[i]|v[j]));
		// 	}
		// }


		cout << marx << endl;
	}
	return 0;
}