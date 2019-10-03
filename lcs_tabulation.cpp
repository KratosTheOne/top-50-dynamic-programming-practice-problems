// https://www.spoj.com/problems/EELCS/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string x, y;
	cin >> x >> y;

	int m = x.size();
	int n = y.size();

	int lookup[m+1][n+1];

	memset(lookup, 0, sizeof(lookup));

	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(x[i-1] == y[j-1])
				lookup[i][j] = lookup[i-1][j-1] + 1;
			else
				lookup[i][j] = max(lookup[i][j-1], lookup[i-1][j]);
		}
	}
	cout << lookup[m][n] << endl;
	return 0;
}