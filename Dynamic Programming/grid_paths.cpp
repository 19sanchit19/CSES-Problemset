#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqmax             priority_queue<int>
#define pqmin             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             2e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FastIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//if infinite loop====> tools-> cancel build


struct hash_pair {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const
	{
		auto hash1 = hash<T1> {}(p.first);
		auto hash2 = hash<T2> {}(p.second);
		return hash1 ^ hash2;
	}
};



int32_t main() {

	int n; cin >> n;
	vector<string> grid(n);
	for (int i = 0; i < n; i++)
		cin >> grid[i];

	int dp[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '.')
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}
	for (int i = 1; i < n; i++) {
		if (dp[i][0] == 1 && dp[i - 1][0] == 0)
			dp[i][0] = 0;
	}
	for (int j = 1; j < n; j++) {
		if (dp[0][j] == 1 && dp[0][j - 1] == 0)
			dp[0][j] = 0;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (dp[i][j] == 1) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
			}
		}
	}
	if (dp[0][0] == 0)
		cout << 0;
	else
		cout << dp[n - 1][n - 1];

	return 0;
}
