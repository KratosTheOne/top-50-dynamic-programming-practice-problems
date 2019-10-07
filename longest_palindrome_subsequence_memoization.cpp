// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

#include<bits/stdc++.h>
using namespace std;

string x;
int n;

int dp(string x, int i, int j, vector <vector <int> > & LPS)
    {
        if(i > j)
            return LPS[i][j] = 0;
        
        if(i == j)
            return LPS[i][j] = 1;
        
        if(LPS[i][j] == 0)
        {
            if(x[i] == x[j])
                return (LPS[i][j] = dp(x, i+1, j-1, LPS) + 2);
            else
                return (LPS[i][j] = max(dp(x, i+1, j, LPS), dp(x, i, j-1, LPS)));
        }
        return LPS[i][j];
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
		cin >> x;
		n = x.size();
		vector < vector <int> > LPS(n, vector <int> (n, 0));
		cout << dp(x, 0, n-1, LPS) << endl;
				
	}
	return 0;
}