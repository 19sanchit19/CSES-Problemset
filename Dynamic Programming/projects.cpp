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

bool cmp(pair<pii, int> p1, pair<pii, int> p2) {
    if (p1.ff.ss == p2.ff.ss)
        return p1.ff.ff <= p2.ff.ff;
    return p1.ff.ss <= p2.ff.ss;
}

int32_t main() {

    int n; cin >> n;
    vector<pair<pii, int>> vp;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        vp.pb({{a, b}, c});
    }
    sort(vp.begin(), vp.end(), cmp);
    int e[n];
    for (int i = 0; i < n; i++)
        e[i] = vp[i].ff.ss;
    int dp[n];
    dp[0] = vp[0].ss;
    for (int i = 1; i < n; i++) {
        //find j
        int s = vp[i].ff.ff;
        int k = lower_bound(e, e + n, s) - e - 1;

        int j = k;
        if (j >= 0 && j < n)
            dp[i] = max(dp[i - 1], dp[j] + vp[i].ss);
        else
            dp[i] = max(dp[i - 1], vp[i].ss);
    }
    cout << dp[n - 1];
    return 0;
}
