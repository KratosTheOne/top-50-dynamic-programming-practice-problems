// https://www.spoj.com/problems/IOIPALIN/

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
	string x, y;
	cin >> x;
	y = x;
	reverse(y.begin(), y.end());

	int lcs[n+1][n+1];

	memset(lcs, 0, sizeof(lcs));

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(x[i-1] == y[j-1])
				lcs[i][j] = lcs[i-1][j-1] + 1;
			else
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}
	
	cout << n - lcs[n][n] << endl;

	return 0;
}