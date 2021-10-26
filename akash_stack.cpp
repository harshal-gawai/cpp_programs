#include<bits/stdc++.h>
using namespace std;

long func(vector<long> vect, int k, bool flag){
    int n=vect.size();
    if(n==k)
        return 0;
	long sum1=0,sum2=0,sum3=0;
    if(k+3 <n){
        sum1 += vect[k] + func(vect,k+1,!flag);
        sum2 += vect[k] + vect[k+1] + func(vect,k+2,!flag);
        sum3 += vect[k] + vect[k+1] + vect[k+2] + func(vect,k+3,!flag);
    }
    else if(k+2 <n){
    	sum1 += vect[k] + func(vect,k+1,!flag);
        sum2 += vect[k] + vect[k+1] + func(vect,k+2,!flag);
        if(flag==1)
        	sum2 = max(sum1,sum2);
        else
            sum2=0;
    }
    else if(k+3 <n){
        sum1 += vect[k] + func(vect,k+1,!flag);
    }
    if(flag==1)
    	return max(max(sum1,sum2),sum3);
    return 0;
}
    
int main() {
  // Insert code here
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<long> vect(n);
        for(int j=0;j<n;j++){
            cin >> vect[j];
        }
        cout << func(vect,0,1) << endl;
    }
  	return 0;
}