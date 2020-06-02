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

string ltrim(const string &);
string rtrim(const string &);

ll power(ll x, ll b) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= mod;} b >>= 1; x *= x; x %= mod;} return p % mod;}


vector<ll> f(105, 1);
vector<ll> g(105, 1);


ll inv_mod(ll x){
    return power(x, mod - 2);
}

void init(){
    
    for(ll i = 1;i < 105; i++){
        f[i] = (i * f[i-1]) % mod;
        f[i] %= mod;
    }
    
    for(ll i = 1;i < 105; i++){
        g[i] = (inv_mod(i) * g[i-1]) % mod;
        g[i] %= mod;
    }
}

ll ncr(ll n, ll r){
    if(n < r) return 0;
    return ((f[n] * g[n - r]) % mod * g[r]) % mod;
}

ll ans(string &s, int k, int n, vector< vector<ll> > &dp, int i = 0){
    if(k > n) return 0;
    
    if(n == 0 or k == 0) return 0;
    
    if(dp[n][k] != -1) return dp[n][k];
    
    ll res = 0;
    if(s[i] != '0'){
        res += ans(s, k - 1, n - 1, dp, i + 1) % mod;

        res %= mod;
        
        //cout << res << " ";

        res += (ncr(n - 1, k) * power(9, k)) % mod;

        res %= mod;
        
        //cout << res << " ";

        res += ((((s[i] - '1') * ncr(n - 1, k - 1) ) % mod) * power(9, k - 1)) % mod;

        res %= mod;
        
        //cout << res << " ";


        res += (k == 1);

        res %= mod;
    }
    else{
        res += ans(s, k, n - 1, dp, i + 1) % mod;
        res %= mod;
    }
    
    //cout << res << endl;
    
    return dp[n][k] = res;
}

int getNumberOfIntegers(string L, string R, int K) {
    init();
    int n = R.size();
    int m = L.size();
    vector< vector<ll> > dpr(n+1, vector<ll>(n+1, -1));
    vector< vector<ll> > dpl(m+1, vector<ll>(m+1, -1));
    
    ll rans = ans(R, K, n, dpr) % mod;

    ll lans = ans(L, K, m, dpl) % mod;
    
    return ((rans - lans) + mod) % mod;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string L;
    getline(cin, L);

    string R;
    getline(cin, R);

    string K_temp;
    getline(cin, K_temp);

    int K = stoi(ltrim(rtrim(K_temp)));

    int ans = getNumberOfIntegers(L, R, K);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
