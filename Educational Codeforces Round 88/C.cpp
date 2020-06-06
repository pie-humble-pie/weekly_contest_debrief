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
        double h, c, t;
        cin >> h >> c >> t;

        //even
        if(2*t <= h + c){
            cout << 2 << endl;
            continue;
        }

        //odd

        ll steps1 = ceil((t - c)/(2*t - (h + c)));
        steps1 = max(1LL, steps1);

        ll steps2 = floor((t - c)/(2*t - (h + c)));
        steps2 = max(1LL, steps2);

        ll ans1 = steps1*(h + c) - c;
        ll ans2 = steps2*(h + c) - c;

        ll s1 = 2*steps1 - 1;
        ll s2 = 2*steps2 - 1;

        if(abs(ans2 - t*s2) * s1 <= abs(ans1 - t*s1) * s2){
            cout << s2 << endl;
        }
        else{
            cout << s1 << endl;
        }
    }
}