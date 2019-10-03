// https://www.spoj.com/problems/FIBEZ/

#include<bits/stdc++.h>
using namespace std;

#define MOD 100000007

unordered_map <int, long long> lookup;

long long fib(long long n, auto &lookup)
{
	if(n <= 2)
	{
		lookup[n] = 1;
		return 1;
	}

	if(lookup.find(n) == lookup.end())
		lookup[n] = (fib(n-1, lookup) + fib(n-2, lookup)) % MOD;

	return lookup[n];
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	fib(500000, lookup);
	
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