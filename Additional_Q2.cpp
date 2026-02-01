#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int> arr = {1, 5, 3, 8, 12, 10, 9};
	sort(arr.begin(), arr.end());
	
	int n = arr.size();
	
	int left=0;
	int maxlen=0;
	
	for(int right=0; right<n; right++){
		while(arr[right] - arr[left] > 10){
			left++;
		}
		maxlen = max(maxlen, right-left+1);
	}
	
	cout << maxlen << endl;
	
	return 0;
}
