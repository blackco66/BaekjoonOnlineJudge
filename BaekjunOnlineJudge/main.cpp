///#1002

#include <iostream>
#include<math.h>

int main()
{
	int n;
	int x1, y1, x2, y2;
	int r1, r2;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{

		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double dist = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		if (x1 == x2 && y1 == y2 && r1 == r2)std::cout << -1 << std::endl;
		else if (x1 == x2 && y1 == y2 && r1 != r2)std::cout << 0 << std::endl;
		else if (dist == r1 + r2)std::cout << 1 << std::endl;
		else if (dist > r1 + r2)std::cout << 0 << std::endl;
		else if (dist<r1 + r2 && dist>abs(r1 - r2))std::cout << 2 << std::endl;
		else if (dist == abs(r1 - r2))std::cout << 1 << std::endl;
		else if (dist < abs(r1 - r2))std::cout << 0 << std::endl;
		else std::cout << 0 << std::endl;
	}
	return 0;
}

