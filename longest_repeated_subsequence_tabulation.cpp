// https://www.geeksforgeeks.org/longest-repeated-subsequence/

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
		string x;
		cin >> x;
		int LRS[n+1][n+1];
		memset(LRS, 0, sizeof(LRS));

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(x[i-1] == x[j-1] and i != j)
					LRS[i][j] = 1 + LRS[i-1][j-1];
				else
					LRS[i][j] = max(LRS[i-1][j], LRS[i][j-1]);
			}
		}
		cout << LRS[n][n] << endl;		
	}
	return 0;
}