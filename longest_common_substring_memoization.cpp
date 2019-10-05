// // https://www.geeksforgeeks.org/longest-common-substring-dp-29/

#include<bits/stdc++.h>
using namespace std;

int m, n;
string x, y;
int LCS[101][101];
int ans;

int dp(int i, int j)
{
	if(i == 0 or j == 0)
		return LCS[i][j] = 0;

	if(LCS[i][j] != -1)
		return LCS[i][j];
    
    dp(i-1, j);
    dp(i, j-1);
    	
	if(x[i-1] == y[j-1])
	{
		LCS[i][j] = dp(i-1, j-1) + 1;
		ans = max(ans, LCS[i][j]);
		return LCS[i][j];
	}
    return LCS[i][j] = 0;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		memset(LCS, -1, sizeof(LCS));
		ans = 0;

		cin >> m >> n;
		cin >> x >> y;

		dp(m, n);

		cout << ans << endl;
	}
	return 0;
}