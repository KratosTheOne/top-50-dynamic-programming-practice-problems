// https://www.spoj.com/problems/EELCS/

// O(min(n, m)) space

#include<bits/stdc++.h>
using namespace std;

#define N 20
#define M 20

int curr[N];
int pre[N];

int lcs_space_optimized(string x, string y, int m, int n)
{
	for (int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(i == 0 or j == 0)
				curr[j] = 0;
			else
			{
				if(x[i-1] == y[j-1])
					curr[j] = pre[j-1] + 1;
				else
					curr[j] = max(pre[j], curr[j-1]);
			}
		}
		for(int j = 0; j <= n; j++)
			pre[j] = curr[j];
	}
	return pre[n];
}
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

	if(m > n)
		cout << lcs_space_optimized(x, y, m, n) << endl;
	else
		cout << lcs_space_optimized(y, x, n, m) << endl;


	return 0;
}