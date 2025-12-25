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

template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> int lwb(const vector<T>& a, const T& b){return int(lower_bound(all(a),b)-a.begin());}
template<class T> int upb(const vector<T>& a, const T& b){return int(upper_bound(all(a),b)-a.begin());}
 
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
 


void solve() {
    ll n,k; cin>>n>>k;
    ll x,a,b,c; cin>> x>>a>>b>>c;
    ll arr[n+1];
    arr[1]=x; arr[0]=0;
    for(ll i=2; i<=n; i++) {
        arr[i]=(a*arr[i-1]+b)%c;
    }

    // debug_v(arr);

    // Brute Approach :-
    // ll ans=0;
    // for(ll i=0; i<30; i++) {
    //     ll mx=-1;
    //     for(ll j=0; j<n; j++) {
    //         if((arr[j]>>i)&1)  mx=j+k-1;
    //         if(j>=k-1 && j<=mx)  ans^=(1<<i);
    //     }
    // }
    // cout<<ans;

    // Optimal Approach (Blocks-wise)
    ll pref[n+1], suff[n+1];
    ll temp1=0;
    for(ll i=0; i<=n; i++) {
        temp1|=arr[i];  pref[i]=temp1;
        if(i%k==0)  temp1=0;
    }

    temp1=0;
    for(ll i=n; i>=0; i--) {
        if(i%k==0)  temp1=0;
        temp1|=arr[i]; suff[i]=temp1;
    }

    ll ans=0;
    for(ll i=k; i<=n; i++){
        ll temp2=(pref[i]|suff[i-k+1]);
        ans^=temp2;
    }

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

/*   /\_/\
*   (= ._.)
*   / >  \>
*/