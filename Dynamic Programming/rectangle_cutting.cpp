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

int solve(int a, int b, int dp[][501]) {
    if (a == b) {
        dp[a][b] = 0;
        return 0;
    }
    if (dp[a][b] != -1)
        return dp[a][b];
    int ans = INT_MAX;
    for (int k = 1; k <= a - 1; k++)
        ans = min(ans, solve(k, b, dp) + solve(a - k, b, dp));
    for (int k = 1; k <= b - 1; k++)
        ans = min(ans, solve(a, k, dp) + solve(a, b - k, dp));
    dp[a][b] = 1 + ans;
    return 1 + ans;
}


int32_t main() {

    int a, b;
    cin >> a >> b;
    int dp[a + 1][501];
    memset(dp, -1, sizeof(dp));
    int ans = solve(a, b, dp);
    cout << ans;
    return 0;
}
