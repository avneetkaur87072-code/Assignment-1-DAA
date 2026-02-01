#include<iostream>
#include<vector>
using namespace std;

int canDivide(vector<int>& arr, int M, int mid){
	int segement = 1;
	int currOR = 0;
	
	for(int i=0; i<arr.size(); i++){
		if((currOR | arr[i]) > mid){
			segement++;
			currOR = arr[i];
		}
		else{
			currOR |= arr[i];
		}
	}
	
	return segement <= M;
}

int main(){
	vector<int> arr = {1,2,3,6};
	int M = 2;
	int maxElement = INT_MIN;
	int totalOR = 0;
	
	for(int i=0; i<arr.size(); i++){
		if(arr[i] > maxElement) maxElement = arr[i];
		totalOR |= arr[i];
	}
	
	int low = maxElement;
	int high = totalOR;
	int mid;
	int ans;
	
	while(low <= high){
		mid = low + (high - low)/2;
		
		if(canDivide(arr,M,mid)){
			ans = mid;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	
	cout << ans << endl;
	return 0;
}
