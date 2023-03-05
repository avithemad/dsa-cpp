#include<stdio.h>

int main()
{
	int n = 10;
	int a[10] = {3, 2, 5, 7, 6, 10, 8, 1, 4, 9};
	
	printf("Current arrary\n");
	for (int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	// heapify
	// start with lower nodes, leaf nodes later h-1 level
	// preserve heap property for each node
	
	for(int ci = n-1; ci>=0; ci--)
	{
		int curr_index = ci;
		int greater_index = 2*(curr_index+1) - 1;
		if (a[2*(curr_index+1)] > a[greater_index])
			greater_index = 2*(curr_index+1);
		while (greater_index < n && (a[curr_index] < a[greater_index]))
		{
			int temp = a[curr_index];
			a[curr_index] = a[greater_index];
			a[greater_index] = temp;
			
			curr_index = greater_index;
			greater_index = 2*(curr_index+1)-1;	
			if (a[2*(curr_index+1)] > a[greater_index])
				greater_index = 2*(curr_index+1);
		}
	}

	printf("After heapifying\n");
	for (int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

}
