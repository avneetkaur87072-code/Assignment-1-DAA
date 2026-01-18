#include<iostream>
#include<vector>
using namespace std;

// specialty (x) : subarray containing elements strictly greater than x.

bool alreadyChecked(vector<int>& checked, int x){
	for(int i=0; i<checked.size(); i++){
		if(checked[i] == x) return true;
	}
	return false;
}

int main(){
	vector<int> arr = {1,1,1,1};
	int n = arr.size();
	int k = 2;
	
	vector<int> checked;
	int specialty = 0;
	
	for(int i=0; i<n; i++){
		int x = arr[i];
		
		if(alreadyChecked(checked,x)){
			continue;
		}
		checked.push_back(x);
		
		int left = 0;
		int count = 0;
		
		for(int right=0; right < n; right++){
			if(arr[right] > x){
				count ++;
			}
			while(count > k){
				if(arr[left] > k){
					count--;
				}
				left++;
			}
			if(count == k){
				specialty++;
				break;
			}
		}
	}
	
	cout << specialty << endl;
	
	return 0;
}
