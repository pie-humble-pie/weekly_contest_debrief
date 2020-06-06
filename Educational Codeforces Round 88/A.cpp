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

int main(){
    ll T;
    cin >> T;
    for(ll t = 0;t < T; t++){
        ll n, m, k;
        cin >> n >> m >> k;
        ll s = n / k;
        ll fmax = min(m, s);
        ll smax = ((m - fmax) / (k - 1)) + (((m - fmax) % (k - 1)) != 0);
        cout << fmax - smax << endl;
    }
}