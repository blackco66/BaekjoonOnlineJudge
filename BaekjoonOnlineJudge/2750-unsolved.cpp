///#2750
#include<iostream>
int a[1000];

void downheap(int* a, int index, int size) 
{
	int smallest = index;
	int left_index = index * 2 + 1;
	int right_index = index * 2 + 2;
	if (left_index<size&&a[smallest]>a[left_index])
	{
		smallest = left_index;
	}
	if (right_index<size&&a[smallest]>a[right_index])
	{
		smallest = right_index;
	}
	if (smallest != index)
	{
		int temp = a[index];
		a[index] = a[smallest];
		a[smallest] = temp;
		downheap(a, smallest, size);
	}
}
void heapify(int *a, int size) 
{
	for (int i = (size - 1) / 2; i >= 0; i--)
	{
		downheap(a, i, size);
	}
}
void heap_sort(int*a, int size) 
{
	while (size > 0)
	{
		heapify(a, size);
		int temp = a[0];
		a[0] = a[size - 1];
		a[size - 1] = temp;
		size--;
	}
}

int main() 
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		 scanf("%d", &a[i]);
	}
	heap_sort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}
}