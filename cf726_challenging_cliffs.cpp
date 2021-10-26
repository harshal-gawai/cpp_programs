#include<bits/stdc++.h>
using namespace std;

void func(int n, vector<int> v){
	sort(v.begin(),v.end());

	if(v[0] == v[1]){								//case 1
		for(int i=0;i<n;i++){
			if(i==1){continue;}
			cout << v[i] << " ";
		}
		cout << v[1] << endl;
		return;
	}
	else if(v[n-1] == v[n-2]){						//case 2
		cout << v[n-1] << " ";
		for(int i=0;i<n-1;i++){
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}

	if(v.size() == 2){
		cout << v[0] << " " << v[1] << endl;
		return;
	}
	
	int mark, minimal = INT_MAX;

	for(int i=n-1;i>0;i--){
		if(v[i] == v[i-1]){
			mark = i;
			break;
		}
		if(v[i] - v[i-1] < minimal){
			minimal = v[i] - v[i-1];
			mark = i;
		}
	}
													//case 3 and 4
	for(int i=mark;i<n;i++)
		cout << v[i] << " ";
	for(int i=0;i<mark;i++)
		cout << v[i] << " ";
	cout << endl;
	return;
}

int main(){
	int t,n,x;
	cin >> t;
	vector<int> v;
	while(t>0){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> x;
			v.push_back(x);
		}
		func(n,v);
		v.clear();
		t--;
	}
}