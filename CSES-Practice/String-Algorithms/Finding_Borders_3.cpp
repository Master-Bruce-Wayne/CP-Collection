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


ll p1=31, p2=37;

void solve() {
    string s; cin>>s;
    ll n=s.length();

    // rolling hash 

    ll pow1[n], pow2[n]; pow1[0]=1, pow2[0]=1;
    for(ll i=1; i<n; i++)  { pow1[i]=(pow1[i-1]*p1)%MOD,  pow2[i]=(pow2[i-1]*p2)%MOD; }

    ll t1=0,t2=0,t3=0,t4=0;
    for(ll i=0; i<n-1; i++) {
        ll lo=s[i]-'a', hi=s[n-1-i]-'a';
        t1=(t1+lo*pow1[i])%MOD; t2=(t2+lo*pow2[i])%MOD;
        t3=(t3*p1+ hi)%MOD, t4=(t4*p2+ hi)%MOD;
        if(t1==t3 && t2==t4)  {  cout<<i+1<<" ";  }
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
        cout << endl;
    } 
 
    // for(int i=1;i<=tc;i++)
    // {
    //   cout<<"Case #"<<i<<": ";
    //   solve();
    // }
 
    return 0;
}
