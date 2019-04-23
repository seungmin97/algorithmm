//https://www.acmicpc.net/problem/2110

#include <iostream>
#include <algorithm>
#define MAX 200000

using namespace std;

int router;
int home;
int *spot;

void placement()
{
	int left, right, mid;

	left = 1;//최소거리
	right = spot[home - 1] - spot[0];
	int answer = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		int start = spot[0];
		int cnt = 1;
		for (int i = 1; i < home; ++i) {
			int distance = spot[i] - start;
			if (mid <= distance)
			{
				start = spot[i];
				cnt++;
			}
		}

		if (cnt >= router)
		{
			left = mid + 1;
			answer = mid;
		}
		else
		{

			right = mid - 1;
		}
	}
	cout << answer;
}

int main()
{
	cin >> home >> router;
	spot = new int[home];
	for (int i = 0; i < home; ++i)
	{
		cin >> spot[i];
	}
	sort(spot, spot + (home));
	placement();
}