// https://www.geeksforgeeks.org/printing-longest-common-subsequence-set-2-printing/

#include<bits/stdc++.h>
using namespace std;

int n, m;
string a, b;
int lookup[101][101];

set <string> print(int p, int q)
{
	set <string> ans, temp1, temp2, temp3;
	
	if(p == 0 or q == 0)
	{
		ans.insert("");
		return ans;
	}
	
	if (a[p-1] == b[q-1])
	{
		temp3 = print(p-1, q-1);
		for (string str : temp3)
			ans.insert(str + a[p-1]);
	}
	else
	{
		if(lookup[p-1][q] >= lookup[p][q-1])
			temp1 = print(p-1, q);
		
		ans.insert(temp1.begin(), temp1.end());
			
		if(lookup[p][q-1] >= lookup[p-1][q])
			temp2 = print(p, q-1);
		
		ans.insert(temp2.begin(), temp2.end());
	}
	
	return ans;
}

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
		memset(lookup, 0, sizeof(lookup));
		
		cin >> a;
		cin >> b;

		n = a.size();
		m = b.size();

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

		set <string> anss = print(n, m);
		
		for(string ans : anss)
			cout << ans << endl;
	}
	return 0;
}