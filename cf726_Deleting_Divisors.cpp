#include<bits/stdc++.h>
using namespace std;

//vector<bool> v;

// void func(int n){
// 	bool flag = false;		//Its Alice's turn
// 	if(n == 1)
// 		v.push_back(false);

// 	//find divisors
// 	for(int i=2;i<=n/2;i++){
// 		if(n%i == 0)
// 	}

// 	return;
// }

int main(){
	int t,n;
	cin >> t;
	while(t-- > 0){
		cin >> n;
		if(n%2 == 1)
			cout << "Bob" << endl;
		//even
		else{
			int i=1;
			while(n >= pow(2,i))
				i++;
			i-=1;
			//cout << "i = " << i << endl;
			if(pow(2,i) == n && i % 2 == 1){
				//cout << "i =1 " << i << endl;
				cout << "Bob" << endl;
			}
			else if(pow(2,i) == n && i % 2 == 0){
				//cout << "i =2 " << i << endl;
				cout << "Alice" << endl;
			}
			else
				cout << "Alice" << endl;
		}
	}
	return 0;
}