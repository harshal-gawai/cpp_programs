#include<bits/stdc++.h>
using namespace std;

int main(){
	cout << "Input day in \"dd mm yyyy\" format" << endl;
	int d,m,y;
	cin >> d >> m >> y;
	//d = 11;m=02;y=2021;

	--y;
	int leap_years = (y/4) - (y/100) + (y/400);
	cout << "leap_years = " << leap_years << endl;
	int days = ( y*365 + leap_years);
	++y;

	bool lc = 0; 	//if current year leap = 1; else 0
	if(y%4==0){
		lc=1;
		if(y%100==0){
			lc=0;
		}
		if(y%400==0){
			lc=1;
		}
	}
	cout << "lc = " << lc << endl;

	int days_in_months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	string day_name[7] = {"Monday", "Tuesday" ,"Wednesday", "Thusrsay", "Friday", "Saturday", "Sunday"};
	//cout << day_name[0] << endl;

	if(lc)
		days_in_months[1] = 29;

	for(int i=0;i<m-1;i++){
		days += days_in_months[i];
	}
	days += d;

	cout << "days = " << days << endl;

	if(days%7 == 0)
		cout << "Sunday" << endl;
	else
		cout << day_name[days%7-1] << endl;
	return 0;
}