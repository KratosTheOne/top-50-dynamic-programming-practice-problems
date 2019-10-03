// https://practice.geeksforgeeks.org/problems/lcs-of-three-strings/0

#include<bits/stdc++.h>
using namespace std;

int LCS[101][101][101];
string x, y, z;

int lcs_3(int p, int q, int r)
{
	if(p == 0 or q == 0 or r == 0)
	{
		LCS[p][q][r] = 0;
		return 0;
	}
		

	if(LCS[p][q][r] == -1)
	{
		if(x[p-1] == y[q-1] and y[q-1] == z[r-1])
			LCS[p][q][r] = lcs_3(p-1, q-1, r-1) + 1;
		else
			LCS[p][q][r] = max(lcs_3(p-1, q, r), max(lcs_3(p, q-1, r), lcs_3(p, q, r-1)));
	}

	return LCS[p][q][r];
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
		memset(LCS, -1, sizeof(LCS));
		
		int p, q, r;

		cin >> p >> q >> r;

		cin >> x >> y >> z;

		cout << lcs_3(p, q, r) << endl;	
	}
	
	return 0;
}