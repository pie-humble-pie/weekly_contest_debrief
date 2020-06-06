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

    ll n, m;

    cin >> n >> m;
    
    umap<ll, vector<ll> > adj;
    umap<ll,ll> t, s;
    uset<ll> temp;
    umap<ll, vector<ll> > mp;
    vector<ll> ans;

    for(ll i = 0;i < m; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ll max_color = 0;

    for(ll i = 1;i <= n; i++){
        ll in;
        cin >> in;
        t[i] = in;
        s[i] = 0;
        max_color = max(max_color, t[i]);
        mp[t[i]].pb(i);
    }

    for(ll x = 1;x <= max_color; x++){

        if(!mp[x].size()){
            //cout << "c1\n";
            cout << -1;
            return 0;
        }

        for(auto node : mp[x]){
            bool ok = true;
            temp.insert(0);

            for(auto next : adj[node]){
                if(t[next] == x){
                    //cout << "c2\n";
                    ok &= false;
                    break;
                }
                temp.insert(s[next]);
            }
            ok &= (temp.size() == x);
            temp.clear();
            if(!ok){
                //cout << x << " ";
                //cout << "c3\n";
                cout << -1;
                return 0;
            }
        }
        for(auto node : mp[x]){
            s[node] = t[node];
            ans.pb(node);
        }
    }


    for(auto node : ans){
        cout << node << " ";
    }

}