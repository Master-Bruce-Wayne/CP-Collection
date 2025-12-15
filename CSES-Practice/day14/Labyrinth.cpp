// graphs -> labyrinth

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
vector<string> arr;
vector<vector<ll>> dist;
vector<vector<pair<ll,ll>>> par;
ll dx[]={1,0,-1,0};
ll dy[]={0,1,0,-1};

bool check(ll x,ll y) {
    if(x>=0&&x<n&&y>=0&&y<m && arr[x][y]!='#')  return 1;
    return 0;
}

void bfs(ll x,ll y) {
    dist=vvl(n, vl(m,1e9));
    par=vector<vpl>(n, vpl(m));

    dist[x][y]=0;
    par[x][y]={-1,-1};
    queue<pl> q;
    q.push({x,y});
    while(!q.empty()) {
        auto it=q.front();  q.pop();
        for(ll i=0; i<4; i++) {
            ll nx=it.ff+dx[i], ny=it.ss+dy[i];
            if(check(nx,ny) && dist[nx][ny]>dist[it.ff][it.ss]+1) {
                dist[nx][ny]=dist[it.ff][it.ss]+1;
                par[nx][ny]=MP(it.ff,it.ss);
                q.push({nx,ny});
            }
        }
    }
}

void printPath (ll x,ll y) {
    if(par[x][y]==MP(-1LL,-1LL)) {
        return;
    }
    printPath(par[x][y].ff, par[x][y].ss);
    ll px=par[x][y].ff, py=par[x][y].ss;
    if(px==x) {
        if(py<y)  cout<<"R";
        else cout<<"L";
    }
    else {
        if(px>x)  cout<<"U";
        else cout<<"D";
    }

    return;
}

void solve() {
    cin>>n>>m;
    arr.resize(n);
    for(ll i=0; i<n ;i++)  cin>>arr[i];

    pl st,en;
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<m; j++) {
            if(arr[i][j]=='A')  st=MP(i,j);
            if(arr[i][j]=='B')  en=MP(i,j);
        }
    }
    bfs(st.ff, st.ss);

    if(dist[en.ff][en.ss]>n*m) {
        cout<<"NO"; return; 
    }

    cout<<"YES\n";
    cout<<dist[en.ff][en.ss]<<endl;
    printPath(en.ff,en.ss);
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