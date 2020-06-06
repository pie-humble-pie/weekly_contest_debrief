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

        ll n;
        cin >> n;
        vv(ll) a(n, 0);
        uset<ll> s, t;

        for(ll i = 0;i < n; i++){
            ll in;
            cin >> in;
            s.insert(in);
        }

        ll res = -1;

        for(ll k = 1;k < (1 << 10); k++){
            for(auto e : s){
                t.insert(e ^ k);
            }
            bool ok = true;
            for(auto e : s){
                if(!t.count(e)) ok &= false;
            }
            t.clear();
            if(ok){
                res = k;
                break;
            }
        }

        cout << res << endl;
        
    }
}
