#include <bits/stdc++.h>
using namespace std;

vector <int> computeLPS(string x){
	vector <int> ans(x.length(),0);
	ans[0] = 0;
	int len=0;
	int i=1;
	while(i<x.length()){
		if(x[i] == x[len]){
			ans[i++] = ++len;
		}
		else{
			if(len == 0)ans[i++] = 0;
			else{
				len = ans[len-1];	
			}
		}
	}
}

int main(){
	string s;
	cin >> s;

	vector <int> lps;

	lps = computeLPS(s);

	for(int i=0;i<lps.size();i++){
		cout << lps[i] << " ";
	}
	cout << endl;

	return 0;
}
