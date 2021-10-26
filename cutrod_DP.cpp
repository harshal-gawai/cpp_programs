#include <bits/stdc++.h>
using namespace std;

int cutrod(int price[], int n){
	if(n==0){
		return 0;
	}
	int max_val = INT_MIN;
	for(int i=0;i<n;i++){
		max_val = max(max_val, price[i] + cutrod(price,n-i-1));
	}
	return max_val;
}

int main(){
	int arr[]={3,5,8,9,10,17,17,20};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "max price of cutting rod is " << cutrod(arr,size)<<endl;
	return 0;
}