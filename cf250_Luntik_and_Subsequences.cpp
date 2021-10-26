#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
	int t,x=INT_MAX,temp;
	cin >>  t;
	while(t--){
		int n;
		cin >> n;
		ll ones = 0, zeros = 0;
		// vector<int> v;
		for(int i=0;i<n;i++){
			temp = x;
			cin >> x;
			if(x == 1 && temp != 1)	ones++;
			if(x == 0 && temp != 0)	zeros++;
		}
		// cout << ones << " " << zeros << endl;
		if(zeros == 0 && ones == 0)
			cout << 0 << endl;
		else if(zeros == 0 &&	ones)
			cout << ones << endl;
		else
			cout << ones*pow(2,zeros) << endl;
		// v.clear();
	}
	return 0;
}