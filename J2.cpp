// https://www.codechef.com/NOV09/problems/J2/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 23102009

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
		string x, y;
		cin >> x >> y;

		int m = x.size();
		int n = y.size();

		int lcs[m+1][n+1];
		int cnt[m+1][n+1];

		memset(cnt, 0, sizeof(cnt));
		memset(lcs, 0, sizeof(lcs));

		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(x[i-1] == y[j-1])
					lcs[i][j] = lcs[i-1][j-1] + 1;
				else
					lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
			}
		}

		for(int i = 0; i <= m; i++)
		{
			for(int j = 0; j <= n; j++)
			{
				if(i == 0 or j == 0)
					cnt[i][j] = 1;
				else
				{
					cnt[i][j] = 0;
					if(x[i-1] == y[j-1])
						cnt[i][j] = cnt[i-1][j-1];
					else
					{
						if(lcs[i-1][j] == lcs[i][j])
							cnt[i][j] = (cnt[i-1][j] + cnt[i][j]) % MOD;
						if(lcs[i][j-1] == lcs[i][j])
							cnt[i][j] = (cnt[i][j-1] + cnt[i][j]) % MOD;
						if(lcs[i-1][j-1] == lcs[i][j])
							cnt[i][j] = (cnt[i][j] - cnt[i-1][j-1] + MOD) % MOD;
					}
				}
				
			}
		}
		cout << lcs[m][n] << " " << cnt[m][n] << endl;		
	}
	return 0;
}