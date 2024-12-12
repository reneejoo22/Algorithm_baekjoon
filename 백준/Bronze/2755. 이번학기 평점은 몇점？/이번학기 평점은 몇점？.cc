#include<iostream>
#include<iomanip>

using namespace std;

int main(){

	double scoreSum = 0;
	int haczuamSum = 0;
	int n; cin>>n;
	for(int i = 1 ;i <=n; i++){
		string name; int haczuam; string score;
		cin>>name>>haczuam>>score;
		haczuamSum+=haczuam;
		
		if( score =="A+" ){ scoreSum += 4.3*(double)haczuam; }
		else if( score == "A0"){ scoreSum += 4.0*(double)haczuam;}
		else if( score == "A-"){ scoreSum += 3.7*(double)haczuam;}
		else if( score == "B+"){ scoreSum += 3.3*(double)haczuam;}
		else if( score == "B0"){ scoreSum += 3.0*(double)haczuam;}
		else if( score == "B-"){ scoreSum += 2.7*(double)haczuam;}
		else if( score == "C+"){ scoreSum += 2.3*(double)haczuam;}
		else if( score == "C0"){ scoreSum += 2.0*(double)haczuam;}
		else if( score == "C-"){ scoreSum += 1.7*(double)haczuam;}
		else if( score == "D+"){ scoreSum += 1.3*(double)haczuam;}
		else if( score == "D0"){ scoreSum += 1.0*(double)haczuam;}
		else if( score == "D-"){ scoreSum += 0.7*(double)haczuam;}
		else{ scoreSum += 0.0;}
		
	}
	double ans =  (scoreSum)/(double)haczuamSum ;
	ans += 0.000000000001;
	cout<<fixed<<setprecision(2)<<ans<<"\n";
	
	return 0;
}