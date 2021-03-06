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

int solve(int n, int dp[]) {
    if (n < 0) {
        // dp[n]=0;
        return 0;
    }
    if (n == 0) {
        dp[n] = 1;
        return 1;
    }
    if (dp[n] != -1)
        return dp[n];
    int sum = 0;
    for (int i = 1; i <= 6; i++) {
        sum += solve(n - i, dp);
        sum %= mod;
    }
    dp[n] = sum;
    return sum;
}


int32_t main() {
    // deepshit();
    int n; cin >> n;
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));
    int x = solve(n, dp);
    cout << x;
    return 0;
}
