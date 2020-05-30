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

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        umap<ll, vv(ll)> adj;
        umap<ll, uset<ll> > prereq;
        vector<ll> deg(n, 0);
        //vector<ll> vis(n, 0);
        vector<bool> res;
        ll Q = queries.size();
        
        for(auto v : prerequisites){
            adj[v[0]].pb(v[1]);
            deg[v[1]]++;
        }
        
        queue<ll> q;
        
        for(ll i = 0;i < n; i++){
            if(deg[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){            
            auto x = q.front();            
            q.pop();            
            for(auto next : adj[x]){
                
                 for(ll c : prereq[x]){
                        prereq[next].insert(c);
                }
                        
                prereq[next].insert(x);
                    
                if(--deg[next] == 0){
                        q.push(next);
                }                
            }           
        }
        
        for(ll i = 0;i < Q; i++){
            
            ll a = queries[i][0];
            ll b = queries[i][1];
            bool ans = prereq[b].count(a);
            res.pb(ans);
        }   
        
        return res;     
    
    }
};