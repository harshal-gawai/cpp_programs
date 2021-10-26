#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& tail, int l, int r,int key){

	while(r-l>1){
		int m = l + (r-l)/2;
		if(tail[m]>=key)
			r=m;
		else
			l=m;
	}
	return r;
}

void LIS(vector<int> &v){
	pair<int,int> a_pair;
	vector<pair<int,int> > a_card;
	vector< vector<pair<int,int> > >ground_2d;
	vector<int> auxilary(v.size(), 0);
	auxilary[0] = v[0];

	a_pair.first = v[0];
	a_pair.second = -1;
	a_card.push_back(a_pair);
	ground_2d.push_back(a_card);
	int length = ground_2d.size();
	for(int i=1; i<v.size(); i++){
		length = ground_2d.size();
		a_pair.first = v[i];
		a_pair.second = -1;
		a_card.clear();
		a_card.push_back(a_pair);

		if(ground_2d[length-1].back().first < v[i]){
			a_card.back().second = ground_2d[length-1].size() - 1;
			ground_2d.push_back(a_card); //new deck
			auxilary[length] = v[i];
			length++;
		}
		else{//v[i] is smaller find appropriate deck to put this card
			int pos = binary_search(auxilary,-1,length-1,v[i]);
			if(length>1){
				a_pair.second = ground_2d[pos-1].size()-1;
			}
			ground_2d[pos].push_back(a_pair);
			auxilary[pos] = v[i];
		}
	}
	
	int i = ground_2d.size(), j = 0;
	vector<int> lis(i);
	while(i>0){
		lis[i-1] = ground_2d[i-1][j].first;
		j = ground_2d[i-1][j].second;
		i--;
	}
	for(int i=0;i<lis.size();i++)
		cout << lis[i]<< " ";
	cout << endl;

	// cout << "ground_2d is: " << endl;
	// for (int i = 0; i < ground_2d.size(); i++){
	//     for (int j = 0; j < ground_2d[i].size(); j++){
	//         cout << ground_2d[i][j].first << "," << ground_2d[i][j].second << "     ";
	//     }
	//     cout << endl;
	// }
}

int main(){
	//vector<int> v = {1,4,2,3,9,10,11,12,6};
	//vector<int> v = {10,5,8,3,9,4,12,11};
	vector<int> v{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	LIS(v);
	reverse(v.begin(),v.end());
	return 0;
}