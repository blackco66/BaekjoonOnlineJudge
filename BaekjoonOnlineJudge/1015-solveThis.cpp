//1015
#include<iostream>
int OriginalArray[50];
int CopiedArray[50];
int p[50];

void CopyArray(int A[], const int B[], int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		A[i] = B[i];
	}
	return;
}

void MergeSort(int A[], int B[], int n)
{
	CopyArray(A, B, 0, n);
	SplitMerge(B, A, 0, n);
}
void SplitMerge(int A[], int B[], int begin, int end)
{
	if (end - begin < 2)
	{
		return;
	}
	int middle = (begin + end) / 2;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		p[i] = i;
	}
	MergeSort(0, n - 1);
	PrintArrayP(n);
	return 0;
}