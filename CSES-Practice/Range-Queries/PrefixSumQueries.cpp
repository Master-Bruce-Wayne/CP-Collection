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


struct Node {
    ll mps,tsum;
    Node() { mps=0, tsum=0;  }
    Node(ll val) { mps=max(0LL,val); tsum=val; }
    Node(ll v1,ll v2) { mps=v1; tsum=v2; }
};

Node merge(Node a, Node b) {
    Node res;
    ll s1=a.mps,  s2=a.tsum+b.mps;
    res.mps=max({0LL,s1,s2}); res.tsum=a.tsum+b.tsum; 
    return res;
}

ll N=2*100000;
ll a[2*100000];
Node seg[8*100000];

void build(ll index,ll l,ll r){
    if(l==r){ seg[index]=Node(a[l]); return; }

    ll mid=(l+r)/2;
    build(2*index, l,mid);
    build(2*index+1, mid+1,r);
    seg[index] = merge(seg[2*index],seg[2*index+1]);
}

Node query(ll ind,ll l,ll r,ll lq,ll rq){
    if(l>rq || lq>r) { return Node(0); }
    if(lq<=l && r<=rq){
        // lq <= l <= r <= rq
        return seg[ind];
    }

    ll mid=(l+r)/2;
    return merge(query(2*ind,l,mid,lq,rq),query(2*ind+1,mid+1,r,lq,rq)); 
}

void update(ll ind,ll l,ll r,ll pos,ll val){
    if(pos<l || pos>r)  return;
    if(l==r) { 
        seg[ind]=Node(val); a[l]=val; return;
    }

    ll mid=(l+r)/2;
    update(2*ind,l,mid,pos,val);
    update(2*ind+1,mid+1,r,pos,val);
    seg[ind] = merge(seg[2*ind],seg[2*ind+1]);
}

void solve() {
    ll n,q; cin>>n>>q;
    for(ll i=0; i<n; i++) cin>>a[i];
    build(1,0,n-1);

    for(ll i=0; i<q; i++) {
        char ch; cin>>ch;
        if(ch=='1') {
            ll pos,val; cin>>pos>>val;
            update(1,0,n-1,pos-1,val);
        }
        else {
            ll l,r; cin>>l>>r;
            Node x=query(1,0,n-1,l-1,r-1);
            ll ans=x.mps;
            cout<<ans<<endl;
        }
    }

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
