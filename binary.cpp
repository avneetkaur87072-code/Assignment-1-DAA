#include<iostream>
using namespace std;

int main(){
	int arr[6] = {1,2,3,4,5,6};
	int st=0;
	int end=6;
	int mid;
	int target = 3;
	
	while(st<=end){
		mid=(st+end)/2;
		if(arr[mid]==target){
			cout << "Target found"<< endl;
			break;
		}
		else if(arr[mid] > target){
			end = mid-1;
		}
		else{
			st = mid+1;
		}
	}
	return 0;
}
