// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int price[n+1];
	for(int i = 1; i <= n; i++)
		cin >> price[i];

	int profit[n+1];
	memset(profit, 0, sizeof(profit));

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
			profit[i] = max(profit[i], price[j] + profit[i - j]);
	}
	
	cout << profit[n] << endl;
	return 0;
}