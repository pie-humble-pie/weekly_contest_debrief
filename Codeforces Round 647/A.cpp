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
    FIO;

    ll T;
    cin >> T;
    
    for(ll tc = 0;tc < T; tc++){
        ll a, b;
        cin >> a >> b;
        ll x = min(a, b);
        ll y = max(a, b);
        ll z = y/x;
        if((y % x) != 0){
            cout << -1 << endl;
            continue;
        }
        if(z && ((z & (z-1)) != 0)){
            cout << -1 << endl;
            continue;
        }

        ll ans = 0;

        while((z % (1 << 3)) == 0){
            z >>= 3;
            ans++;
        }

        while((z % (1 << 2)) == 0){
            z >>= 2;
            ans++;
        }

        while((z % (1 << 1)) == 0){
            z >>= 1;
            ans++;
        }

        cout << ans << endl;
    }
}
