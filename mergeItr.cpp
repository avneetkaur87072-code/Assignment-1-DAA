#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> & arr, int lb, int mid, int ub){
	int i = lb;
    int j = mid + 1;
    int k = lb;

    vector<int> b(ub + 1);

    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            b[k++] = arr[i++];
        } else {
            b[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        b[k++] = arr[i++];
    }

    while (j <= ub) {
        b[k++] = arr[j++];
    }

    for (int x = lb; x <= ub; x++) {
        arr[x] = b[x];
    }
}

void mergeSort(vector<int> &arr, int n){
	int p, i, l, mid, h;
	
	for(p=2; p<=n; p=p*2){
		for(i=0; i+p-1<n; i=i+p){
			l=i;
			h=i+p-1;
			mid=(l+h)/2;
			
			merge(arr,l,mid,h);
		}
	}
	if(p/2 < n){
		merge(arr,0,p/2 - 1,n-1);
	}
}

int main(){
	vector<int> arr = {8,3,7,4,9,2,6};
	int n = arr.size();
	
	mergeSort(arr,n);
	
	for(int i : arr){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
