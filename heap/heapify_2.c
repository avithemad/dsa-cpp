#include<stdio.h>

void max_heapify(int* arr, int index, int n){
	int left_ind = 2*(index+1) - 1;
	int right_ind = 2*(index+1);
	int greater_ind = index;
	// check if right index is less than n and root is less than right child
	if(right_ind<n && (arr[greater_ind] < arr[right_ind])){
		greater_ind = right_ind;
	}
	if(left_ind<n && (arr[greater_ind] < arr[left_ind])){
		greater_ind = left_ind;
	}
	if(greater_ind != index){
		// swap with greater and max heapify the swapper element
		int temp = arr[greater_ind];
		arr[greater_ind] = arr[index];
		arr[index] = temp;

		max_heapify(arr, greater_ind, n);
	}
}

int main()
{
	int a[10] = {3, 7, 8, 1, 3, 5, 4, 6, 3, 2};
	int n = 10;
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	for(int i=n-1; i>=0; i--){
		max_heapify(a, i, n);
	}
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
