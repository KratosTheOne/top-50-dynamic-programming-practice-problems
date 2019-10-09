// https://www.geeksforgeeks.org/longest-common-substring-dp-29/

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
		int m, n;
		cin >> m >> n;

		string x, y;
		cin >> x >> y;

		int LCS[m+1][n+1];
		memset(LCS, 0, sizeof(LCS));
		int ans = 0, idx = 0;
		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= n; j++)
			{

				if(x[i-1] == y[j-1])
					LCS[i][j] = LCS[i-1][j-1] + 1;
				if(LCS[i][j] > ans)
				{
					ans = LCS[i][j];
					idx = i;
				}
			}
		}
		cout << ans << endl;
		cout << x.substr(idx - ans, ans) << endl;
	}
	return 0;
}