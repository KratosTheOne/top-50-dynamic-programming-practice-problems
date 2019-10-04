// https://www.codechef.com/problems/ORACLCS

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
		int ans = INT_MAX;
		while(n--)
		{
			int a = 0, b = 0;
			string s;
			cin >> s;
			for(char ch : s)
				if(ch == 'a')
					a++;
				else
					b++;
			ans = min(ans, min(a, b));
		}
		cout << ans << endl;
	}
	return 0;
}