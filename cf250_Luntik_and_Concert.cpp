#include<bits/stdc++.h>
using namespace std;

#define ll long long

int func(int a,int b, int c){
	if(a%2==1  && b%2==1 && c%2==1 )
		return 0;
	else if(a%2==1  && b%2==1 && c%2==0 )
		return 1;
	else if(a!=1 && a%2==1  && b%2==0 && c%2==1 )
		return 0;
	else if(a==1  && b%2==1 && c%2==1)	return 2;

	else if(a%2==1  && b%2==0 && c%2==0 )
		return 1;
	else if(a%2==0  && b%2==1 && c%2==1 )
		return 1;
	else if(a%2==0  && b%2==1 && c%2==0 )
		return 0;
	else if(a%2==0  && b%2==0 && c%2==1 )
		return 1;
	else if(a%2==0  && b%2==0 && c%2==0 )
		return 0;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		cout << func(a,b,c) << endl;
	}
	return 0;
}