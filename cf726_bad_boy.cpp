#include<bits/stdc++.h>
using namespace std;

bool sortcolumn(const vector<long>& v1, const vector<long>& v2){
	return v1[0] < v2[0];
}

void func(long n, long m, long i, long j){
	vector<vector<long>> vect(4,vector<long> (2,0));
	
	for(int i=0;i<4;i++){
		vect[i][1] = i;
	}
	//sizes
	vect[0][0] = i;
	vect[1][0] = n - i;
	vect[2][0] = j;

	vect[3][0] = m - j;

	sort(vect.begin(), vect.end(),sortcolumn);
	// for(int i=0;i<vect.size();i++){
	// 	cout << vect[i][0] << " " << "i = "<< vect[i][1] << endl;
	// }


	if(n == 1 || m == 1){
		if(n == 1){
			cout << 1 << " " << 1 << " " << 1 << " " << m << endl;
		}
		else{
			cout << 1 << " " << 1 << " " << n << " " << 1 << endl;
		}
	}
	else if(vect[3][1] == 0){
		if(vect[2][1] == 2)
			cout << 1 << " " << 1 << " " << n << " " << m << endl;
		else
			cout << 1 << " " << m << " " << n << " " << 1 << endl;
	}
	else if(vect[3][1] == 1){
		if(vect[2][1] == 2)
			cout << n << " " << 1 << " " << 1 << " " << m << endl;
		else
			cout << n << " " << m << " " << 1 << " " << 1 << endl;
	}
	else if(vect[3][1] == 2){
		if(vect[2][1] == 0)
			cout << 1 << " " << 1 << " " << n << " " << m << endl;
		else
			cout << 1 << " " << m << " " << n << " " << 1 << endl;
	}
	else if(vect[3][1] == 3){
		if(vect[1][1] == 0)
			cout << 1 << " " << 1 << " " << n << " " << m << endl;
		else
			cout << 1 << " " << m << " " << n << " " << 1 << endl;
	}


	return;
}

int main(){
	int t;
	//integer value range is +- 2.14*10^10
	cin >> t;
	long n,m,i,j;
	while(t>0){
		cin >> n >> m >> i >> j;
		func(n,m,i,j);
		t--;
	}
	return 0;
}