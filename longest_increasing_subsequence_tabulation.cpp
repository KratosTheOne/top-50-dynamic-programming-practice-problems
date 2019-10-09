// https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		
		int a[n], LIS[n];

		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			LIS[i] = 1;
		}		

		int ans = 1;
		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(a[j] < a[i])
					LIS[i] = max(LIS[i], LIS[j] + 1);
				ans = max(ans, LIS[i]);
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}