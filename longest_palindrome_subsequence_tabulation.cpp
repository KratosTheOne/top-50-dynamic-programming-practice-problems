// https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

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
		string s;
		cin >> s;
		int n = s.size();

        vector<vector<int>> LPS(n, vector<int>(n, 0));

        for(int i = 0; i < n; ++i)
            LPS[i][i] = 1;

        for(int j = 1; j < n; ++j)
        {
            for(int i = 0; i + j < n; ++i)
            {
                if(s[i] == s[i + j])
                    LPS[i][i + j] = LPS[i + 1][i + j - 1] + 2;
                else
                    LPS[i][i + j] = max(LPS[i + 1][i + j], LPS[i][i + j - 1]);
            }
        }
        cout << LPS[0][n - 1] << endl;	
	}
	return 0;
}