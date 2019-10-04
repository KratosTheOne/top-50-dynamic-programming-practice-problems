// https://www.spoj.com/problems/TRIP/

#include<bits/stdc++.h> 
#define MAX 100 

using namespace std; 

int lcslen = 0; 
int dp[MAX][MAX]; 
string x, y;
int m, n;

int lcs(int i, int j) 
{

	if (i == m || j == n) 
		return dp[i][j] = 0; 

	if (dp[i][j] != -1) 
		return dp[i][j]; 

	dp[i][j] = 0; 

	if (x[i] == y[j]) 
		dp[i][j] = 1 + lcs(i+1, j+1); 
	else
		dp[i][j] = max(lcs(i+1, j), lcs(i, j+1)); 
	
	return dp[i][j]; 
}

void printAll(string &data, int indx1, int indx2, int currlcs) 
{
	if (currlcs == lcslen) 
	{
		cout << data << endl;
		return; 
	} 

	if (indx1 == m || indx2 == n) 
		return; 
 
	for (char ch = 'a'; ch <= 'z'; ch++) 
	{
		bool done = false; 
		for (int i = indx1; i < m; i++) 
		{ 
			if (ch == x[i]) 
			{ 
				for (int j = indx2; j < n; j++) 
				{
					if (ch == y[j] && lcs(i, j) == lcslen - currlcs) 
					{ 
						data.push_back(ch);
						printAll(data, i+1, j+1, currlcs+1); 
						done = true;
						data.erase(data.length() - 1);
						break; 
					} 
				} 
			} 
			if(done) 
			{
				break; 
			}
		} 
	} 
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
		cin >> x >> y;

		m = x.size();
		n = y.size();

		memset(dp, -1, sizeof(dp)); 
    	lcslen = lcs(0, 0); 

		string data = "";
		printAll(data, 0, 0, 0);
	}
	return 0; 
} 
