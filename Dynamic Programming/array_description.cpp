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
	int n, m; cin >> n >> m;
	int a[n];
	int dp[n][m + 1]; memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] != 0)
			dp[i][a[i]] = 1;
	}

	for (int i = 0; i < n; i++) {
		if (a[i] != 0) {
			if (i > 0) {
				dp[i][a[i]] = dp[i - 1][a[i]];
				if (a[i] - 1 >= 1) {
					dp[i][a[i]] += dp[i - 1][a[i] - 1]; dp[i][a[i]] %= mod;
				}
				if (a[i] + 1 <= m) {
					dp[i][a[i]] += dp[i - 1][a[i] + 1]; dp[i][a[i]] %= mod;
				}
			}
		}
		else {
			for (int j = 1; j <= m; j++) {
				if (i == 0)
					dp[i][j] = 1;
				else {
					dp[i][j] = dp[i - 1][j];
					if (j - 1 >= 1) {
						dp[i][j] += dp[i - 1][j - 1]; dp[i][j] %= mod;
					}
					if (j + 1 <= m) {
						dp[i][j] += dp[i - 1][j + 1]; dp[i][j] %= mod;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int j = 1; j <= m; j++) {
		ans += dp[n - 1][j]; ans %= mod;
	}
	cout << ans;
	return 0;
}
