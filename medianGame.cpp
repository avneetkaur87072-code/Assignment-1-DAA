#include<iostream>
using namespace std;

void sort(int arr[], int n){
	for(int i=1; i<n; i++){
		int key = arr[i];
		int j = i-1;
		
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main(){
	int arr[5] = {1,3,2,4,5};
	int n = 5;
	int k = 1;
	
	int minMedian = INT_MAX;
	
	for(int op=0; op<k; op++){
		
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				int len = j-i+1;
			
		    	if(len>1 && len%2==1){
		    		int temp[100];
				    int idx=0;
				
				    for(int p=i; p<=j; p++){
						temp[idx++] = arr[p];
					}
					sort(temp, len);
				
					int median = temp[len / 2];
					if(median < minMedian){
						minMedian = median;
					}
				}
				
			}
		}
		
		for(int i=0; i<n; i++){
			if(arr[i] == minMedian){
				for(int j=i; j<n-1; j++){
					arr[j] = arr[j+1];
				}
				n--;
				break;
			}
		}
		
	}
	int sum = 0;
	for(int i=0; i<n; i++){
		sum+=arr[i];
	}
	cout << sum << endl;
	
	return 0;
}
