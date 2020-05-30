#define ll long long int
#define pi 3.1415926535897932385
#define mod 1000000007
#define db double
#define pp(x) pair<x,x>
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vv(x) vector<x >
#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define pq priority_queue
#define all(x) x.begin(), x.end()
ll power(ll x, ll b) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= mod;} b >>= 1; x *= x; x %= mod;} return p % mod;}
using namespace std;

class Solution {
public:
    
    const ll INF = 1e12;
    
    ll go(ll x, ll y, ll z, ll n, ll m, vv(vv(ll)) &a, vv(vv(vv(ll))) &dp){
        if(x == n) return 0;;
        if(y < 0 or z < 0 or y >= m or z >= m){
            return -INF;
        }
        if(dp[x][y][z] != -1) return dp[x][y][z];

        ll res = 0;

        if(y == z) res += a[x][y];

        if(y != z) res += a[x][z] + a[x][y];

        ll ans = -INF;
        for(ll i = -1;i <= 1; i++){
            for(ll j = -1;j <= 1; j++){
                ans = max(ans, go(x + 1, y + i, z + j, n, m, a, dp));
            }
        }
        if(ans == -INF) res = -INF;
        else{
            res += ans;
        }
        return dp[x][y][z] = res;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vv(vv(vv(ll))) dp(n, vv(vv(ll))(m, vv(ll)(m, -1)));
        vv(vv(ll)) a(n, vv(ll)(m, 0));
        
        for(ll i = 0;i < n; i++) for(ll j = 0;j < m; j++) a[i][j] = grid[i][j];
        
        return go(0, 0, m-1, n, m, a, dp);
    }
};