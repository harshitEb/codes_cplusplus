#include <bits/stdc++.h>
using namespace std;


vector <int> merge(vector <int> a,int start,int end){
		
	int mid = start+((end-start)/2);
		
	vector <int> left,right;
	for(int i=start;i<=mid;i++)left.push_back(a[i]);
	for(int i=mid+1;i<=end;i++)right.push_back(a[i]);	

	vector <int> ans;
	int a_i=0,b_i=0;
	while(a_i < left.size() && b_i < right.size()){
		if(left[a_i] >= right[b_i]){
			ans.push_back(right[b_i]);
			b_i++;
		}
		else{
			ans.push_back(left[a_i]);
			a_i++;
		}
	}
	while(a_i < left.size())ans.push_back(left[a_i++]);
	while(b_i < right.size())ans.push_back(right[b_i++]);

	return ans;
}

void mergeSort(vector <int> &a,int start,int end){
	if(start < end){
		int mid = start + ((end-start)/2);

		mergeSort(a,start,mid);
		mergeSort(a,mid+1,end);
		
		a = merge(a,start,end);	
	}
}

int main(){
	int n=0;
	cin >> n;
	vector <int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i]; 
	}

	mergeSort(arr,0,n-1);

	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}