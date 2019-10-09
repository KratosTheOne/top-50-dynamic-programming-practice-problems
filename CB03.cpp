// https://www.codechef.com/CBUZZ101/problems/CB03

#include<bits/stdc++.h>
using namespace std;

long long dp(long long i, long long j, string s, vector <vector <long long>> &cnt)
{
	if(i > j)
		return cnt[i][j] = 0;

	if(cnt[i][j] != 0)
		return cnt[i][j];
	
	if(i == j)
		return cnt[i][j] = 1;

	if(s[i-1] == s[j-1])
		return cnt[i][j] = dp(i+1, j, s, cnt) + dp(i, j-1, s, cnt) + 1;
	else
		return cnt[i][j] = dp(i+1, j, s, cnt) + dp(i, j-1, s, cnt) - dp(i+1, j-1, s, cnt);
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	long long t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		long long n = s.size();
		vector < vector <long long>  > cnt (n+1, vector <long long>(n+1, 0));
		cout << dp(1, n, s, cnt) << endl;		
	}
	return 0;
}