#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int sum = A[0],n=A.size(),count=0;
    int l=0,r=0;
    cout << n << endl;
    while(l<n){
        cout << l << " " << r <<" " << sum << endl;
        // if(r==n-1){
        //     sum -= A[l];
        //     l++;
        //     if(sum<B)
        //         count;
        // }
        
        if(sum>=B || r==n-1){
            l++;
            sum=A[l];
            r=l;
            continue;
        }
        else if(sum<B)
            count++;
        r++;
        sum += A[r];
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin >> A[i];
    int B;
    cin >> B;
    cout << solve(A,B);
    return 0;
}