#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int N = 6;
	int W = 3;
	int H = 2;
	int S;
	
	int low=0;
	int high=max(W,H)*N;
	int mid;
	
	while(low<=high){
		mid = low + (high-low)/2;
		int count = (mid/W)*(mid/H);
		if(count >= N){
			S=mid;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	cout << S << endl;
	
	return 0;
}
