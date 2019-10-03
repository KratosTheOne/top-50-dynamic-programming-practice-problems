// https://practice.geeksforgeeks.org/problems/lcs-of-three-strings/0

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
		int p, q, r;
		string x, y, z;

		cin >> p >> q >> r;

		cin >> x >> y >> z;

		int LCS[p+1][q+1][r+1];

		memset(LCS, 0, sizeof(LCS));


		for(int i = 1; i <= p; i++)
		{
			for(int j = 1; j <= q; j++)
			{
				for(int k = 1; k <= r; k++)
				{
					if(x[i-1] == y[j-1] and y[j-1] == z[k-1])
					{
						LCS[i][j][k] = 1 + LCS[i-1][j-1][k-1];
					}
					else
						LCS[i][j][k] = max(LCS[i-1][j][k], max(LCS[i][j-1][k], LCS[i][j][k-1]));
				}
			}
		}

		cout << LCS[p][q][r] << endl;
	}
	return 0;
}