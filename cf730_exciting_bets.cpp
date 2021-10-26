#include<bits/stdc++.h>
using namespace std;

bool prime(long long n){
	for(long long i=2;i<=sqrt(n);i++){
		if(n % i == 0 )
			return 0;
	}
	return 1;
}

// int gcd(long long a, long long b){
// 	if(a < b){
// 		long long temp = a;
// 		a = b;
// 		b = temp;
// 	}

// 	if(b==0)
// 		return a;

// 	if(a==b)
// 		return b;
// 	else
// 		return gcd(a-b,b);
// }

// void fun(long long a, long long b){
// 	if(a < b){
// 		long long temp = a;
// 		a = b;
// 		b = temp;
// 	}
// 	if(a == b){
// 		cout << 0 << " " << 0 << endl;
// 		return;
// 	}
// 	if(a-b == 1){
// 		cout << 1 << " " << 0 << endl;
// 		return;
// 	}
// 	if(a-b == 2){
// 		cout << 2 << " " << 0 << endl;
// 		return 0;
// 	}
// 	else{
// 		if(a < b){
// 			long long temp = a;
// 			a = b;
// 			b = temp;
// 		}
// 		long long gg = gcd(a-b,b);
// 		if((a-b) % gg == 0){
// 			(a-b) / 
// 		}
// 	}
// }

int main(){
	int t;
	cin >> t;

	while(t--){
		long long a,b;
		cin >> a >> b;
		//fun(a,b);

		//cout << gcd(a,b) << endl;
		if(a < b){
			long long temp = a;
			a = b;
			b = temp;
		}

		if(a == b){
			cout << 0 << " " << 0 << endl;
			continue;
		}
		int d=a-b;
		//cout << "d = " << d << endl;
		if(prime(d)){
			cout << d << " ";
			if(d==1){
				cout << 0 << endl;
				continue;
			}
		// 	if(((a+d)/d)*d-a < a-a%d){
		// 		cout << "here1 "<< ((a+d)/d)*d - a << endl;
		// 	}
		// 	else{
		// 		cout << "here2 " << a-a%d << endl;
		// 	}
		}
		else{		//composite
			cout << "here3 "<< a-b << " ";
			long long jmp = (a+d)%d;
			cout << min(jmp, d-jmp);
			
		}
	}
	return 0;
}