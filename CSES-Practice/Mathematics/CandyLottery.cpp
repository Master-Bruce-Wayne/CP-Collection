#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required
// using namespace __gnu_pbds; //required

#define ll long long
// #define fo(i,n)  for(i=0; i<n; i++)
// #define Fo(i,k,n)  for(i=k; k<n?i<n:i>n; k<n?i+=1:i-=1)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x)  x.begin(), x.end()
#define clr(x)  memset(x, 0, sizeof(x))
#define sortall(x)  sort(all(x))
#define revsortall(x)  sort(x.rbegin(),x.rend())
// #define tr(it, a)  for(auto it=a.begin(); it!=a.end(); it++)
#define PI 3.1415926535897932384626
#define endl '\n'
#define yes cout << "YES" << endl
#define no  cout << "NO" << endl
#define in(x)  cin >> x
#define light    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
#define lbnd        lower_bound
#define ubnd        upper_bound
#define cps         CLOCKS_PER_SEC
#define INF 4e18

typedef long double        ld;
typedef pair<int, int>     pii;
typedef pair<ll, ll>       pl;
typedef vector<int>        vi;
typedef vector<ll>         vl;
typedef vector<pii>        vpii;
typedef vector<pl>         vpl;
typedef vector<vi>         vvi;
typedef vector<vl>         vvl;

template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxpq = priority_queue<T>;

// ******** ordered-set ************// 

// template <typename T> using ordered_set =  tree<T, null_type, less<T>,
// rb_tree_tag, tree_order_statistics_node_update>;
 
// All indexing is 0-based
// ordered_set <int> s;
// s.find_by_order(k); returns the (k+1)th smallest element
// s.order_of_key(k); returns the number of elements in s strictly less than k
// To make it an ordered_multiset, use pairs of (value, time_of_insertion)
// to distinguish values which are similar.

#define whatis(x)   cout << #x << " is " << x << "\n";
#define debug(x)     cout << #x << " " << x << endl;
#define debugTwo(x,y)     cout << #x << " " << x << "," << #y << " " << y << endl;
#define debugThree(x,y,z)     cout << #x << " " << x << "," << #y << " " << y << "," << #z << " " << z << endl;
#define debug_p(x)   cout << #x << " " << x.F << " " << x.S << endl;
#define debug_v(x)   {cout << #x << " "; for (auto ioi : x) cout << ioi << " "; cout << endl;}
#define debug_vp(x)  {cout << #x << " "; for (auto ioi : x) cout << '[' << ioi.F << " " << ioi.S << ']'; cout << endl;}
#define debug_v_v(x) {cout << #x << "/*\n"; for (auto ioi : x) { for (auto ioi2 : ioi) cout << ioi2 << " "; cout << '\n';} cout << "*/" << #x << endl;}


const ll MOD = 1e9 + 7;

// +++++++++ mod arithmetic ++++++++++ //
 
//a and b are assumed to be taken modulo p
inline int add(int a, int b, int p = MOD){ int c = a + b; if(c >= p) c -= p; return c;}
inline int sub(int a, int b, int p = MOD){ int c = a - b; if(c < 0) c += p; return c;}
inline int mul(int a, int b, int p = MOD){ return (a * 1ll * b) % p;}
// ************* Code Starts ****************** //
 
 
// *** Sujal Agarwal *** // 
// *** NIT DGP'28  *** // 
 
// Important Points ->
// 1. upper_bound points to first value > val
// 2. lower_bound me equal to bhi aata hai (>=)
// 3. string.split(string, char[" "]) - returns vector of strings


void print6(ld ans) {
    const ll SCALE = 1000000;

    ld val = ans * SCALE;
    ll base = floor(val);
    ld frac = val - base;

    const ld EPS = 1e-12L;

    if (frac > 0.5L + EPS) {
        base++;
    } 
    else if (fabsl(frac - 0.5L) <= EPS) {
        // round half to even
        if (base % 2 == 1) base++;
    }

    cout << base / SCALE << ".";

    ll dec = base % SCALE;
    cout << setw(6) << setfill('0') << dec;
}

ld binexp(ld a, ll b){
    ld result = 1;
    while(b > 0){
        if(b & 1){
            result = (result * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return result;
}

void solve() {
    ll n; ld k; cin>>n>>k;
    ld ans=0;

    // exp_val = sum( i * prob[i] )
    for(ll i=1; i<=k; i++) {
        ld prob_i = binexp(i/k,n) - binexp((i-1)/k,n);
        ld temp = i*prob_i;
        ans+=temp;
    }

    print6(ans);
}
 
int main() {
#ifndef ONLINE_JUDGE 
    // for getting input from input1.txt
    freopen("input1.txt", "r", stdin);
    // for getting output to output1.txt
    freopen("output1.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   
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
