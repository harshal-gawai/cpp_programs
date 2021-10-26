#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s="";
	//cout << "here n = " << n << " " << s << endl; 

	if(n==1)
		cout << "a" << endl;
	else if(n%2 == 0)
		s = string(n/2-1,'a') + "b" + string(n/2,'a');
	else if(n%2==1)
		s = string(n/2,'a') + 'b' + string(n/2-1,'a') + "c";
	cout << s << endl;
	return;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--)
		solve();
	return 0;
}