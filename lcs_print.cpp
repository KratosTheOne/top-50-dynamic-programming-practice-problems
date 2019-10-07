// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

#include <bits/stdc++.h>
using namespace std;

stack <int> values;
int n, m;
int a[101];
int b[101];
int lookup[101][101];

void print(int p, int q)
{
	if(p == 0 or q == 0)
		return ;

	if(a[p-1] == b[q-1])
	{
		values.push(a[p-1]);
		print(p-1, q-1);
	}
	else
	{
		if(lookup[p-1][q] > lookup[p][q-1])
			print(p-1, q);
		else
			print(p, q-1);
	}

}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin >> n;
	cin >> m;

	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i-1] == b[j-1])
				lookup[i][j] = lookup[i-1][j-1] + 1;
			else
				lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]);
		}
	}

	print(n, m);

	while(values.size() != 0)
	{
		cout << values.top() << " ";
		values.pop();
	}
	return 0;
}