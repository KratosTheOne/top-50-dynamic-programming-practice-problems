// https://www.spoj.com/problems/FIBEZ/

#include<bits/stdc++.h>
using namespace std;

#define MOD 100000007
unordered_map <int, long long> lookup;

void fib()
{
	lookup[1] = 1;
	lookup[2] = 1;
	for(int i = 3; i <= 500000; i++)
		lookup[i] = (lookup[i-1] + lookup[i-2]) % MOD;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	fib();
	
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", lookup[n]);
	}

	return 0;
}