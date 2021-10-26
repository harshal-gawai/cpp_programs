#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,k,x;
	string s;
	cin>> n>> k>> s;

	if(s.size() == 1){
		while(s.size() < k)
			s = s + s;
		cout << s.substr(0,k) << endl;
		return 0;
	}

	string s1 = "";s1.push_back(s[0]);
	string s2 = "";s2.push_back(s[1]);
	int i=0, j=1;

	while(j <= s.size()-1){
		//cout << "i,j,s1,s2 = " << i <<","<<j << ","<< s1 << "," << s2 << endl;
		x = s1.compare(s2);
		//cout << x << endl;
		if(x > 0){
			//cout << "case1 >" << endl;
			i=0;
			s1 = "";s1.push_back(s[0]);
			s2 = "";s2.push_back(s[j+1]);
			//cout << s1 << " " << s2 << endl;
			++j;
		}
		else if(x == 0){
			//cout << "case2 =" << endl;
			s1.push_back(s[i+1]);
			if(j == s.size()-1){
				s = s.substr(0,j+1-s2.size());
				break;
			}
			s2.push_back(s[j+1]);
			i++;j++;
			//cout << "here i,j = " << i << " " << j <<" " << s1 <<" " << s2 << endl;
			//if(j == s.size()-1)
		}
		else if(x < 0){
			//cout << "case3 <" << endl;
			s = s.substr(0,j+1-s2.size());
		}
		else
			break;
	}
	while(s.size() < k){
		s = s+s;
	}
	cout << s.substr(0,k) << endl;
	return 0;
}