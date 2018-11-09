//#2042
#include<iostream>
long long a[1000000];
long long tree[2000000];
class SegmentTree
{
public://methods
	long long Init(int treeIndex, int begin, int end);
	long long GetSum(int begin, int end);
private://methods
private://member variables
	long long a[1000000];
	long long tree[200000];
};
long long SegmentTree::Init(int treeIndex, int begin, int end)
{
	if (begin > end)
	{
		int temp = begin;
		begin = end;
		end = temp;
	}
	if (begin == end)
	{
		return tree[treeIndex] = a[begin];
	}
	else
	{
		int leftChildEnd = (begin + end) / 2;
		return tree[treeIndex] = Init(treeIndex * 2 + 1, begin, leftChildEnd) + Init(treeIndex * 2 + 2, leftChildEnd + 1, end);
	}
}

long long SegmentTree::GetSum(int begin, int end)
{

}