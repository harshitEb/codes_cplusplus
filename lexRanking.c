#include <bits/stdc++.h>
using namespace std;

int SmallerThan(string str,char x,int start){
	int res=0;
	for(int i=start;i<str.length();i++){
		if(x > str[i])
			res++;
	}
	return res;
}

int facti(int x){
	int res=1;
	for(int i=x;i>0;i--){
		res = ((res%1000003)*(i%1000003))%1000003;
	}
	return res;
}

int main(){
	string A;
	cin >> A;
	vector <int> smaller;


	// for(int i=0;i<A.length();i++){
	// 	cout << A[i] << " ";
	// }
	// cout << endl;
						

	for(int i=0;i<A.length();i++){
		smaller.push_back(SmallerThan(A,A[i],i));
	}


	// for(int i=0;i<A.length();i++){
	// 	cout << smaller[i] << " ";
	// }
	// cout << endl;
	
	

	// for(int i=0;i<A.length();i++){
	// 	cout << facti(A.length()-i-1) << " ";
	// }
	// cout << endl;


	int rank=1;
	for(int i=0;i<A.length();i++){
		//cout << facti(A.length()-i-1)*(smaller[i]) << " ";
		rank += facti(A.length()-i-1)*(smaller[i]);
	}
	//cout << endl;

	cout << rank << endl;
	return 0;
}