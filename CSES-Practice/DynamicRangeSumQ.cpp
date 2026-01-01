// range queries -> dyn. range sum queries

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
 

// struct Node {
//     ll sum;
//     Node() { sum=0; }
//     Node(ll s) {  sum=s; }
// };

// Node merge (Node n1, Node n2) {
//     return Node(n1.sum+n2.sum);
// }

ll N=2*100000;
ll a[3*100000];
ll seg[12*100000];

void build(ll index,ll l,ll r){
    if(l==r){
        seg[index] =a[l];
        return;
    }
    ll mid=(l+r)/2;
    build(2*index, l,mid);
    build(2*index+1, mid+1,r);
    // To find sum over query -> merge logic
    // seg[index] = merge(seg[2*index],seg[2*index+1]);
    seg[index] = seg[2*index] + seg[2*index+1];
}

ll query(ll ind,ll l,ll r,ll lq,ll rq){
    if(l>rq || lq>r) { return 0; }
    if(lq<=l && r<=rq){
        // lq <= l <= r <= rq
        return seg[ind];
    }
    ll mid=(l+r)/2;
    // return merge(query(2*ind,l,mid,lq,rq),query(2*ind+1,mid+1,r,lq,rq)); 
    return query(2*ind,l,mid,lq,rq)+query(2*ind+1,mid+1,r,lq,rq);
}

void update(ll ind,ll l,ll r,ll pos,ll val){
    if(pos<l || pos>r)  return;
    if(l==r) { 
        seg[ind]=val;
        a[l]=val;  
        return;
    }
    ll mid=(l+r)/2;
    update(2*ind,l,mid,pos,val);
    update(2*ind+1,mid+1,r,pos,val);
    // seg[ind] = merge(seg[2*ind],seg[2*ind+1]);
    seg[ind]=seg[2*ind]+seg[2*ind+1];
}

void solve() {
    ll n,q; cin>>n>>q;
    for(ll i=0; i<n; i++)  cin>>a[i];

    build(1,0,n-1);

    // cout<<"Seg: \n";
    // for(ll i=1; i<35; i++) {
    //     cout<<seg[i].sum<<" ";
    // }

    for(ll i=0; i<q; i++)  {
        char ch; cin>>ch;
        if(ch=='1') {
            ll k,x; cin>>k>>x;
            update(1,0,n-1,k-1,x);
        }
        else {
            ll l,r; cin>>l>>r;
            // cout << rangeQuery() 
            // Node x=query(1,0,n-1,l-1,r-1);
            cout<<query(1,0,n-1,l-1,r-1)<<endl;
        }
    }
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