// graphs -> message route

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define setval(x, y) memset(x, y, sizeof(x))
#define sortall(x) sort(all(x))
#define revsortall(x) sort(x.rbegin(), x.rend())
#define lbnd        lower_bound
#define ubnd        upper_bound
#define remin(a, b) (a = min((a), (b)))
#define remax(a, b) (a = max((a), (b)))
#define sz(x) (ll)(x).size()
#define PI 3.1415926535897932384626
#define INF 1e18
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string> vstr;
 
#define whatis(x)   cout << #x << " is " << x << "\n";
#define debug(x)     cout << #x << ": " << x << endl;
#define debugTwo(x,y)   cout << #x << ": " << x << ", " << #y << ": " << y << endl; 
#define debugThree(x,y,z)  cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl; 
#define debug_p(x)   cout << #x << ": " << x.F << " " << x.S << endl;
#define debug_v(x)   {cout << #x << ": "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << ": "; for (auto ioi : x) cout << '[' << ioi.F << " " << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}
 
const ll MOD = 1e9 + 7;
// ************* Code Starts ****************** //
 
 
// *** Sujal Agarwal *** // 
// *** NIT DGP'28  *** // 
 
// Important Points ->
// 1. upper_bound points to first value > val
// 2. lower_bound me equal to bhi aata hai (>=)

ll n,m; 
vector<vector<ll>> g;
vector<ll> dist;
vector<ll> par;

void bfs(ll node) {
    dist=vl(n+1,1e9);
    par=vl(n+1);
    dist[node]=0; par[node]=-1;
    queue<ll> q;
    q.push(node);
    while(!q.empty()) {
        auto pos=q.front(); q.pop();
        for(auto it:g[pos]) {
            if(dist[it]>dist[pos]+1) {  // not visited
                dist[it]=dist[pos]+1;
                par[it]=pos;
                q.push(it); 
            }
        }
    }
}

void printPath(ll n) {
    if(par[n]==-1) {  return; }
    printPath(par[n]);
    cout<<n<<" ";
}

void solve() {
    cin>>n>>m;
    g.resize(n+1);
    for(ll i=0; i<m; i++) {
        ll a,b; cin>>a>>b;
        g[a].PB(b); g[b].PB(a);
    }

    bfs(1);
    if(dist[n]<=n)  {
        cout<<dist[n]+1<<endl; 
        cout<<"1 "; printPath(n);  return;
    }
    cout<<"IMPOSSIBLE";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
        // cout << endl;
    } 
 
    return 0;
}