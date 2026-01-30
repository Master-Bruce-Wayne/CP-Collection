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
#define rall(x) (x).rbegin(), (x).rend()
#define clr(x) memset(x, 0, sizeof(x))
#define setval(x, y) memset(x, y, sizeof(x))
#define sortall(x) sort(all(x))
#define revsortall(x) sort(x.rbegin(), x.rend())
#define lbnd        lower_bound
#define ubnd        upper_bound
#define swap(a,b)   a ^= b; b ^= a; a ^= b;
#define nodig(N)  floor(log10(N)) + 1;
#define ppc      __builtin_popcountll
#define trail0      __builtin_ctzll
#define lead0     __builtin_clzll
#define leftmost_bit(x) (63 - __builtin_clzll(x))
#define tot_bits(x) (64 - __builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x) __builtin_popcountll(x)
#define pow2(i) (1LL << (i))
#define is_on(x, i) ((x)&pow2(i))      // state of the ith bit in x
#define set_on(x, i) ((x) | pow2(i))   // returns integer x with ith bit on
#define set_off(x, i) ((x) & ~pow2(i)) // returns integer x with ith bit off
#define prec(x)   fixed<<setprecision(x)
#define remin(a, b) (a = min((a), (b)))
#define remax(a, b) (a = max((a), (b)))
#define sz(x) (ll)(x).size()
#define PI 3.1415926535897932384626
#define INF 4e18
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vstr;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;
 
#define whatis(x)   cout << #x << " is " << x << "\n";
#define debug(x)     cout << #x << ": " << x << endl;
#define debugTwo(x,y)   cout << #x << ": " << x << ", " << #y << ": " << y << endl; 
#define debugThree(x,y,z)  cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << endl; 
#define debug_p(x)   cout << #x << ": " << x.ff << " " << x.ss << endl;
#define debug_v(x)   {cout << #x << ": "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << ": "; for (auto ioi : x) cout << '[' << ioi.ff << " " << ioi.ss << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}
 
const ll MOD = 1000000007;
// ************* Code Starts ****************** //
 
 
// *** Sujal Agarwal *** // 
// *** NIT DGP'28  *** // 
 
// Important Points ->
// 1. upper_bound points to first value > val
// 2. lower_bound me equal to bhi aata hai (>=)


ll n,m;
vector<vpl> graph;
vvl dist;

void bfs() {
    set<pair<pl,ll>> st;  // cost,dest,used/not-used-coup
    st.insert({{0,1},0});  
    dist[1][0]=0, dist[1][1]=0;

    while(!st.empty()) {
        auto it=*(st.begin());  st.erase(st.begin());
        ll cost=it.ff.ff, par=it.ff.ss,used=it.ss;
        for(auto npl:graph[par]) {
            ll nn=npl.ff, costnn=npl.ss;
            if(dist[nn][used]>cost+costnn) {
                st.erase({{dist[nn][used],nn},used}); 
                st.insert({{cost+costnn,nn},used});
                dist[nn][used]=cost+costnn;
            } 
            if(!used && dist[nn][1]>cost+(costnn/2)) {
                st.erase({{dist[nn][1],nn},1});
                st.insert({{cost+(costnn/2),nn},1});
                dist[nn][1]=cost+(costnn/2);
            }
        }
    }
}

void solve() {
    cin>>n>>m;
    graph.clear(); graph.resize(n+1); 
    dist=vvl(n+1, vl(2,INF));

    for(ll i=0; i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        graph[a].PB({b,c});
    }

    bfs();

    cout<<dist[n][1];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("cowqueue.in", "r", stdin);
    // freopen("cowqueue.out", "w", stdout);

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
