// https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/

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
		int a[n], LLIS[n], RLIS[n];
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			LLIS[i] = 1;
			RLIS[i] = 1;
		}

		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(a[j] < a[i])
					LLIS[i] = max(LLIS[i], LLIS[j] + 1);
			}
		}

		for(int i = n - 2; i >= 0; i--)
		{
			for(int j = n - 1; j > i; j--)
			{
				if(a[j] < a[i])
					RLIS[i] = max(RLIS[i], RLIS[j] + 1);
			}
		}
		int ans = 1;
		for(int i = 0; i < n; i++)
			ans = max(ans, LLIS[i] + RLIS[i] - 1);
		cout << ans << endl;
	}
	return 0;
}