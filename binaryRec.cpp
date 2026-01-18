#include<iostream>
#include<vector>
using namespace std;

bool binaryRec(vector<int> arr, int target, int l, int h){
	int mid;
	if(l>h) return false;
	mid  = l + (h-l)/2;
	if(arr[mid] == target) return true;
	else if(arr[mid] > target) return binaryRec(arr,target,l,mid-1);
	return binaryRec(arr,target,mid+1,h);
}

int main(){
	vector<int> arr = {1,2,3,4,5,6,7,8,9};
	int target = 10;
	int n=arr.size();
	if(binaryRec(arr,target,0,n-1)){
		cout << "Element found" << endl;
	}
	else{
		cout << "Element not found" << endl;
	}
	return 0;
}
