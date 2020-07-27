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

int solve(int a[], int pre[], int st, int end, int turn, int dp[5000][5000][2]) {
    if (st == end) {
        dp[st][end][turn] = a[st];
        return a[st];
    }
    if (dp[st][end][turn] != INT_MAX)
        return dp[st][end][turn];
    int x1 = solve(a, pre, st + 1, end, (turn + 1) % 2, dp);
    int x2 = solve(a, pre, st, end - 1, (turn + 1) % 2, dp);
    int ts = st >= 1 ? pre[end] - pre[st - 1] : pre[end];
    int ans = max(ts - x1, ts - x2);
    dp[st][end][turn] = ans;
    return ans;

}

int32_t main() {

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int pre[n];
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];
    int dp[5000][5000][2];
    for (int i = 0; i < 5000; i++) {
        for (int j = 0; j < 5000; j++) {
            dp[i][j][0] = INT_MAX;
            dp[i][j][1] = INT_MAX;
        }
    }
    // cout<<dp[0][0][0]<<"\n";
    int ans = solve(a, pre, 0, n - 1, 1, dp);
    cout << ans;
    return 0;
}
