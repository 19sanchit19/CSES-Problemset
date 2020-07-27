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

int getbestcandidate(map<int, int>& candidates, int ele) {
    auto it = candidates.lower_bound(ele);
    if (it == candidates.begin())
        return 0;
    it--;
    return it->second;
}
void insert(map<int, int>& candidates, int v, int adv) {
    if (candidates[v] >= adv)
        return;
    candidates[v] = adv;
    auto it = candidates.find(v);
    it++;
    while (it != candidates.end() && it->second <= adv) {
        auto temp = it;
        it++;
        candidates.erase(temp);
    }
}
int solve(int a[], int n) {
    int dp[n]; dp[0] = 1;
    map<int, int> candidates;
    candidates[a[0]] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1 + getbestcandidate(candidates, a[i]);
        insert(candidates, a[i], dp[i]);
    }
    return *max_element(dp, dp + n);
}
int32_t main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = solve(a, n);
    cout << ans;
    return 0;
}
