//#2042
#include<iostream>

long long theArray[1000000];
long long theTree[3000000];

long long Init(const int node, const int begin, const int end)
{
	if (begin == end)
	{
		return theTree[node] = theArray[begin];
	}
	else
	{
		int leftChildEnd = (begin + end) / 2;
		return theTree[node] = Init(node * 2 + 1, begin, leftChildEnd) + Init(node * 2 + 2, leftChildEnd + 1, end);
	}
}
///(begin, end) <-> node
///(left, right) <-> Range of the Sum 
long long Sum(const int node, const int begin, const int end, const int left, const int right)
{
	if ((end < left) || (right < begin))
	{
		return 0;
	}
	else if ((left <= begin) && (end <= right))
	{
		return theTree[node];
	}
	int leftChildEnd = (begin + end) / 2;
	return Sum(node * 2 + 1, begin, leftChildEnd, left, right) + Sum(node * 2 + 2, leftChildEnd + 1, end, left, right);

}
///Change element in 'index' by amout of 'diff' and update the tree
void Update(const int node, const int begin, const int end, const int index, const long long diff)
{
	if ((index < begin) || (end < index))
	{
		return;
	}
	theTree[node] += diff;
	if (begin != end)
	{
		int leftChildEnd = (begin + end) / 2;
		Update(node * 2 + 1, begin, leftChildEnd, index, diff);
		Update(node * 2 + 2, leftChildEnd + 1, end, index, diff);
	}
}

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &theArray[i]);
	}

	Init(0, 0, N - 1);
	for (int i = 0; i < M + K; i++)
	{
		int choice;
		scanf("%d", &choice);
		if (choice == 1)
		{
			int index;
			long long diff;
			scanf("%d %lld", &index, &diff);
			index -= 1;
			diff = diff - theArray[index];
			theArray[index] = theArray[index] + diff;
			Update(0, 0, N - 1, index, diff);
		}
		else if (choice == 2)
		{
			int begin, end;
			scanf("%d %d", &begin, &end);
			long long sum = Sum(0, 0, N - 1, begin - 1, end - 1);
			printf("%lld\n", sum);
		}
	}
	return 0;
}