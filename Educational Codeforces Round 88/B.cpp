#include <bits/stdc++.h>
#define ll long long int
#define pi 3.1415926535897932385
#define mod 1000000007
#define db double
#define pp(x) pair<x,x>
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vv(x) vector< x >
#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define file freopen("inp.in","r",stdin); freopen("outp.out","w",stdout)
#define all(x) x.begin(), x.end()

using namespace std;

ll power(ll x, ll b) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= mod;} b >>= 1; x *= x; x %= mod;} return p % mod;}

const ll INF = 1e12;

ll min_cost(ll i, vv(char) & a, vv(ll) & dp, ll x, ll y){
    if(i == a.size()){
        return 0;
    }
    if(dp[i] != -1) return dp[i];

    ll res = INF;

    if(a[i] == '*'){
        res = min(res, min_cost(i + 1, a, dp, x, y));
    } 
    else{
        res = min(res, x + min_cost(i + 1, a, dp, x, y));
        if((i < a.size() - 1) && (a[i+1] == '.')){
            res = min(res, y + min_cost(i + 2, a, dp, x, y));
        }
    }

    return dp[i] = res;
}


int main(){
    FIO;
    ll T;
    cin >> T;
    for(ll t = 0;t < T; t++){
        ll n, m, x, y;
        cin >> n >> m >> x >> y;

        //cout << n << m << x << y << endl;

        vv(vv(char)) a(n, vv(char)(m, 0));
        vv(ll) dp(m, -1);

        ll ans = 0;

        for(ll i = 0;i < n; i++){
            for(ll j = 0;j < m; j++){
                cin >> a[i][j];
            }
            dp.assign(m, -1);
        ans += min_cost(0, a[i], dp, x, y);
        }

        cout << ans << endl;
    }
}