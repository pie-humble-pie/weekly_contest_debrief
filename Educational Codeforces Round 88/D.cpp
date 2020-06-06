// Solution Credits : Rupav Jain
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


const ll INF = 1LL<<40;


int main(){
    ll n;
    cin >> n;
    vv(ll) a(n, 0), dpl(n, 0), dpr(n, 0), p(n, 0), s(n, 0);
    stack<ll> stk;

    for(ll i= 0;i < n; i++) cin >> a[i];

    for(ll i = 0;i < n; i++) p[i] = (i > 0) ? p[i-1] + a[i] : a[i];

    for(ll i = n-1;i >= 0; i--) s[i] = (i < n-1) ? s[i+1] + a[i] : a[i];



    for(ll i = 0;i < n; i++){

        while(!stk.empty() and a[stk.top()] <= a[i]){
            ll x = stk.top();
            dpl[i] = max(dpl[i], max(p[i-1] - p[x] + a[x] + dpl[x], p[i-1] - p[x] + a[x]));
            stk.pop();
        }
        stk.push(i);
    }
    
    while(!stk.empty()) stk.pop();

    for(ll i = n-1;i >= 0; i--){

        while(!stk.empty() and a[stk.top()] <= a[i]){
            ll x = stk.top();
            dpr[i] = max(dpr[i], max(s[i+1] - s[x] + a[x] + dpr[x], s[i+1] - s[x] + a[x]));
            stk.pop();
        }
        stk.push(i);
    }
    
    ll ans = 0;
    for(ll i = 0;i < n; i++){
        //cout << dpl[i] << " " << dpr[i] << endl;
        ans = max(ans, max(0LL, dpl[i]) + max(0LL, dpr[i]));
    }
    cout << ans;
}