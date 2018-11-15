//10828
#include<iostream>
#include<string>
int stack[10000];
int size = 0;
void Push(int X)
{
	stack[size] = X;
	size++;
}
int Pop()
{
	if (size == 0)return -1;
	size--;
	return stack[size];
}
int Empty()
{
	if (size == 0)return 1;
	return 0;
}
int Top()
{
	if (size == 0)return -1;
	return stack[size - 1];
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		std::string order;
		std::cin >> order;
		if (order == "push")
		{
			int x;
			scanf("%d", &x);
			Push(x);
		}
		else if (order == "pop")
		{
			printf("%d\n", Pop());
		}
		else if (order == "size")
		{
			printf("%d\n", size);
		}
		else if (order == "empty")
		{
			printf("%d\n", Empty());
		}
		else if (order == "top")
		{
			printf("%d\n", Top());
		}
	}
	return 0;
}