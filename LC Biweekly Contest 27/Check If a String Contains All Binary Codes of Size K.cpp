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
ll power(ll x, ll b) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= mod;} b >>= 1; x *= x; x %= mod;} return p % mod;}

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        uset<ll> codes;
        ll n = s.length();
        
        if(n < k) return false;
        
        ll num_codes = n - k + 1;
        
        if((1 << k) > num_codes) return false;
        
        ll x = 0;
        
        for(int i = 0;i < k; i++){
            x = (x << 1) + (s[i] - '0');
            //cout << x << " ";
        }
        
        codes.insert(x);
        
        for(int i = k;i < n; i++){
            x = (x << 1) + (s[i] - '0');
            x = x - ((1 << k) * (s[i - k] - '0'));
            //cout << x << " ";
            codes.insert(x);
        }
        
        return (codes.size() == (1 << k)) ? true : false;
    }
};