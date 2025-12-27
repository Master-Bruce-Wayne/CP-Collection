// Intro -> Grid Path Description

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


ll ans=0;
string s;
vector<vector<ll>> vis(7, vl(7,0));
ll dx[]={-1,0,1,0};
ll dy[]={0,1,0,-1};

bool check(ll x,ll y) {
    return ((x>=0)&&(x<7)&&(y>=0)&&(y<7));
}
void dfs(pl node, pl par, ll ind) {
    if(node==make_pair(6LL,0LL) && ind==48)  {
        ans++; return; 
    }
    if(ind==48)  {
        return;
    }
    if(node==make_pair(6LL,0LL)) return;

    vis[node.ff][node.ss]=1;

    if ((node.ff>0 && vis[node.ff-1][node.ss]) &&
        (node.ff<6 && vis[node.ff+1][node.ss]) &&
        (node.ss>0 && !vis[node.ff][node.ss-1]) &&
        (node.ss<6 && !vis[node.ff][node.ss+1])) {
        vis[node.ff][node.ss]= 0;
        return;
    }

    if ((node.ss>0 && vis[node.ff][node.ss-1]) &&
        (node.ss<6 && vis[node.ff][node.ss+1]) &&
        (node.ff>0 && !vis[node.ff-1][node.ss]) &&
        (node.ff<6 && !vis[node.ff+1][node.ss])) {
        vis[node.ff][node.ss]=0;
        return;
    }

    if(s[ind]=='?') {
        for(ll i=0; i<4; i++) {
            ll nx=node.ff+dx[i], ny=node.ss+dy[i];
            if(check(nx,ny) && !vis[nx][ny]) {
                dfs({nx,ny}, node, ind+1);
            }
        }
    }
    else {
        ll nx=node.ff, ny=node.ss;
        if(s[ind]=='U')  nx--;
        if(s[ind]=='D')  nx++;
        if(s[ind]=='L')  ny--;
        if(s[ind]=='R')  ny++;
        
        if(check(nx,ny) && !vis[nx][ny]) {
            dfs({nx,ny},node,ind+1);
        }
    }

    vis[node.ff][node.ss]=0;
}

void solve() {
    cin>>s;
    dfs({0,0},{-1,-1}, 0);
    cout<<ans;
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