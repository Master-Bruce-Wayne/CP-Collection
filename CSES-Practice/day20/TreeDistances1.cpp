// tree -> tree distances 1

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

int n;
vector<vector<ll>> g;
vector<ll> dis;

void dfs(ll nn, ll pp,ll dd) {
    dis[nn]=dd;
    for(auto v:g[nn]) {
        if(v!=pp) {
            dfs(v,nn,dd+1);
        }
    }
}

void solve() {
    cin>>n;
    g.clear(); g.resize(n+1); dis.resize(n+1);
    for(ll i=0; i<n-1; i++)  {
        ll a,b; cin>>a>>b;
        g[a].push_back(b);  g[b].push_back(a);
    }

    // 2 bfs solution
    dfs(1,0,0);
    ll max1=1;
    for(ll i=2; i<=n; i++) {
        if(dis[max1]<dis[i])  max1=i;
    }

    dfs(max1,0,0);
    ll max2=1;
    for(ll i=2; i<=n; i++) {
        if(dis[max2]<dis[i]) max2=i;
    }

    // max1, max2-> ednpoints of diamter
    vl temp1=dis; // max1 array
    dfs(max2,0,0);
    vl temp2=dis; // max2 array

    for(ll i=1; i<=n; i++) { cout<<max(temp1[i],temp2[i])<<" "; }

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
 
    // for(int i=1;i<=tc;i++)
    // {
    //   cout<<"Case #"<<i<<": ";
    //   solve();
    // }
 
    return 0;
}