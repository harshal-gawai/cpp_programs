/*Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.
*/

#include<bits/stdc++.h>
using namespace std;


//memoization or top-down method
int lcs_print(string A, string B){
// string lcs_print(vector<int> A, vector<int> B){
	int m=A.size(), n=B.size();
	//fill matrix
	int matrix[m+1][n+1];

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				matrix[i][j]=max(i,j);
			else if(B[j-1]==A[i-1])
				matrix[i][j] = matrix[i-1][j-1];
			else													//not equal
				matrix[i][j]=min(min(matrix[i-1][j],matrix[i][j-1]),matrix[i-1][j-1])+1;
		}
	}
	// for(int i=0;i<=m;i++){
	// 	for(int j=0;j<=n;j++){
	// 		cout << matrix[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return matrix[m][n];
}
int main(){
	string A,B;
	A = "bbbaabaa";
	B = "aababbabb";


	//cin >> A >> B;
	int lcs = lcs_print(A,B);
	cout << "lcs = " << lcs << endl;
	return 0;
}