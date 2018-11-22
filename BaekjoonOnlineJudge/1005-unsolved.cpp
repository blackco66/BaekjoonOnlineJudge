//1005
#include<iostream>
#include<vector>

int timeOfConstruction[1001];
int time[1001];
void FindConstructionTime(std::vector<int> order[], const int to, const int from)
{
	if (to != -1)
	{
		//find max
		timeOfConstruction[from] =
			timeOfConstruction[from] > timeOfConstruction[to] + time[from] ?
			timeOfConstruction[from] : timeOfConstruction[to] + time[from];
	}
	else // ���� �ǹ� W�� ���
	{
		timeOfConstruction[from] = time[from];
	}

	
	for (int i = 0; i < order[from].size(); i++) 
	{
		FindConstructionTime(order, from, order[from][i]);
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++)
	{
		//�Է�--------------------------
		int n, k;
		scanf("%d %d", &n, &k);
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &time[i]);
			timeOfConstruction[i] = 0;
		}

		std::vector<int> order[1001];

		for (int i = 0; i < k; i++)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			from--;
			to--;
			order[to].push_back(from);
		}
		int w;
		scanf("%d", &w);
		w--;
		//����ð� ���----------------------
		FindConstructionTime( order, -1, w);

		//���� ����ð� �� critical pass�� ã�´�. 
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			if (max < timeOfConstruction[i])
			{
				max = timeOfConstruction[i];
			}
		}
		printf("%d\n", max);
	}
	return 0;
}