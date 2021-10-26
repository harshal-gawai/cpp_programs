#include<bits/stdc++.h>
using namespace std;

void func(int n, vector<int> A){
	int sum = accumulate(A.begin(),A.end(),0);
	// 0 for int sum, 0.0 or 0.0f for float
	if(sum == n){
		cout << 0 << endl;
	}
	else if(sum < n){
		cout << 1 << endl;
	}
	else if(sum > n){
		cout << sum - n << endl;
	}
	return;
}

int main(){
	int t,n,x;
	vector<int> A;
	cin >> t;
	while(t>0){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> x;
			A.push_back(x);
		}
		t--;
		func(n,A);
		A.clear();
	}
	return 0;
}