#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > anagrams(const vector<string> &A) {
    unordered_map <string, vector <int> > hash;
    vector <string> arr;
    vector <vector <int> > res;

    for (int i = 0; i < A.size(); i++){
        string str = A[i];
        sort (str.begin(), str.end());
        if (hash.find(str) == hash.end()){
            hash[str] = {i};
            arr.push_back(str);
        }
        else hash[str].push_back(i);
        str.clear();
    }
    for (auto str : arr)
        res.push_back(hash[str]);
    
    return res;
}

int main(){
    string str;
    vector<string> A = {"cat","dog","tit","itt"};
    // getline(cin,str);
    // stringstream ss(str);

    // const vector<string> A;
    // while(1){
    //     ss >> str;
    //     A.push_back(str);
    // }
    vector<vector<int> > res = anagrams(A);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}