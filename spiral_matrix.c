#include <bits/stdc++.h>

using namespace std;

void spiralPrint(vector <vector <int> >&A){
	int top = 0;
	int left = 0;
	int bottom = A.size()-1;
	int right = A[0].size()-1;
	int dir = 0;//0 for ->, 1 for V , 2 for <-, 3 for ^

	while(top <= bottom && left <= right){
		switch(dir){
			case 0 : 
				for(int i=left;i<=right;i++){
					cout << A[top][i] << " ";
				}
				top++;
				break;

			case 1 :
				for(int i=top;i<=bottom;i++){
					cout << A[i][right] << " ";
				}
				right--;
				break;

			case 2 :
				for(int i=right;i>=left;i--){
					cout << A[bottom][i] << " ";
				}
				bottom--;
				break;

			case 3 :
				for(int i=bottom;i>=top;i--){
					cout << A[i][left] << " ";
				}
				left++;
				break;	
		}
		dir = (dir+1)%4;
	}
}

int main(){
	int n=0,m=0;
	cin >> n >> m;
	vector <vector <int> > mat;
	for(int i=0;i<n;i++){
		vector <int> tmp;
		for(int j=0;j<m;j++){
			int t;
			cin >> t;
			tmp.push_back(t);
		}
		mat.push_back(tmp);
	}

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout << mat[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	spiralPrint(mat);
	
	return 0;
}