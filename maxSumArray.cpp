#include<iostream>
#include<vector>
using namespace std;

int maxCrossSum(vector<int> arr, int l, int mid, int h){
	int sum=0;
	int leftSum = INT_MIN;
	for(int i=mid; i>=l; i--){
		sum = sum + arr[i];
		if(sum > leftSum) leftSum = sum;
	}
	
	sum=0;
	int rightSum = INT_MIN;
	for(int i=mid+1; i<=h; i++){
		sum = sum + arr[i];
		if(sum > rightSum) rightSum = sum;
	}
	
	return (leftSum + rightSum);
}

int maxSum(vector<int> arr, int l, int h){
	if(l>h) return INT_MIN;
	if(l==h) return arr[l];
	int mid = l + (h-l)/2;
	
	int leftSum = maxSum(arr,l,mid);
	int rightSum = maxSum(arr,mid+1,h);
	int crossSum = maxCrossSum(arr,l,mid,h);
	
	if(leftSum >= rightSum && leftSum >= crossSum) return leftSum;
	else if(rightSum >= leftSum && rightSum >= crossSum) return rightSum;
	else return crossSum;
}

int main(){
	vector<int> arr = {2, 3, 4, 5, 7};
	int n = arr.size();
	
	cout << maxSum(arr,0,n-1);
	
	return 0;
}
