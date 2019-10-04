// https://www.spoj.com/problems/TRIP/

#include<bits/stdc++.h>
using namespace std;

int lcs[101][101];
string x, y;
int n, m;
int ans_len;
string pos = "";
set <string> pr;

void printLcs(string &ans, int row, int col, int currlen)
{
	if(row > n or col > m)
		return;

	int flag = 0;
	
	for(int ch = 0; ch < 26; ch++)
	{
		for(int i = row; i <= n; i++)
		{
			
			if(x[i-1] == (char)('a' + ch))
			{
				for(int j = col; j <= m; j++)
				{
					if(y[j-1] == (char)('a' + ch) && lcs[i][j] == currlen)
					{
						ans = ans + x[i-1];
						pos = pos + to_string(i-1);
						pr.insert(ans);
						if(currlen == ans_len)
						{
							cout << ans << endl;
							cout << pos << endl;
							pos.erase(pos.length()-1);
							ans.erase(ans.length()-1);
							flag = 1;
							break;
						}
						else
						{
							printLcs(ans, i + 1, j + 1, currlen + 1);	
						}
						pos.erase(pos.length()-1);
						ans.erase(ans.length()-1);
					}
				}
				if(flag)
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
		memset(lcs, 0, sizeof(lcs));

		cin >> x >> y;

		n = x.size();
		m = y.size();

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(x[i-1] == y[j-1])
					lcs[i][j] = lcs[i-1][j-1] + 1;
				else
					lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
		
		ans_len =  lcs[n][m];

		cout << ans_len << endl;

		string ans = "";
		printLcs(ans, 1, 1, 1);
		cout << "END" << endl;
	}
	return 0;
}