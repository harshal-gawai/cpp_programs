#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int l, int r, int key){
	int m;
	while(l<=r){
		m= l + (r-l)/2;

		if(arr[m]==key)
			return m;
		else if(arr[m]<key)
			l = m+1;
		else
			r = m-1;
	}
	return -1;
}

int less_comparisions(int arr[], int l, int r, int key){
	int m;
	while(r-l>1){
		m= l + (r-l)/2;
		if(arr[m]<=key)
			l=m;
		else
			r=m;
	}
	if(arr[l]==key)
		return l;
	else if(arr[r]==key)
		return r;
	else
		return -1;
}



// *****************************************************************************
int lower_boundage(int arr[], int l, int r, int key){
	int m;
	while(r-l>1){
		m = l + (r-l)/2;
		if(arr[m] <= key)
			l=m;
		else 
			r=m;
	}
	if(l==0 && arr[l] > key){
		cout << "key lesser than all values in array" << endl;
		return -1;
	}
	return arr[l];
}
// *****************************************************************************



int upper_boundage(int arr[], int l, int r, int key){//value in array greater than equal to key
	int m;
	while(r-l>1){
		m = l + (r-l)/2;
		if(arr[m] <= key)
			l=m;
		else
			r=m;
	}
	if(arr[l]==key)
		return arr[l];
	else if(l+1 > sizeof(arr)/sizeof(arr[0])){
		cout << "l=" << sizeof(arr)/sizeof(arr[0]) << endl;
		cout << "key greater than all values in array" << endl;
		return -1;
	}
	else
		return arr[l+1];
}

int main(){
	int arr[] = {1,3,5,6,7,9,11,17};
	int key = 8;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << binary_search(arr, 0, n, key) << endl;
	cout << less_comparisions(arr, 0, n, key) << endl;
	cout << lower_boundage(arr, 0, n, key) << endl;
	cout << upper_boundage(arr, 0, n, key) << endl;


	return 0;
}