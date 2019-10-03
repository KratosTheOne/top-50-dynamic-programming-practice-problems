// https://www.spoj.com/problems/EELCS/

#include<bits/stdc++.h>
using namespace std;

#define M 20
#define N 20

int lookup[M + 1][N + 1];

int LCSLength(string X, string Y, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	if (lookup[m][n] == 0)
	{
		if (X[m - 1] == Y[n - 1])
			lookup[m][n] = LCSLength(X, Y, m - 1, n - 1) + 1;
		
		else
			lookup[m][n] = max(LCSLength(X, Y, m, n - 1), LCSLength(X, Y, m - 1, n));
	}
	return lookup[m][n];
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

	cout << LCSLength(x, y, m, n) << endl;

	return 0;
}