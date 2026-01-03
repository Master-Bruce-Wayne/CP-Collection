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


// a <= 10^9 , b <= 10^9, M <= 10^9
ll binexp(ll a, ll b, ll m){
    a %= m;   // a <= 10^18, b <= 10^9, M <= 10^9
    ll result = 1;
    while(b > 0){
        if(b & 1){
            result = (1LL * result * a) % m;
            // result = binMultiply(ans, a)  ->If M <= 10^18
        }
        a = (1LL * a * a) % m;
        // a = binMultiply(a, a)  -> If M <= 10^18
        b >>= 1;
    }
    return result;
}

ll modInverse(ll n, ll p)
{
    return binexp(n, p - 2, p);
}

void solve() {
    ll n; cin>>n;

    ll ndiv=1, ndiv_mod=1, sum=1, pr=1, temp=1; ll temp2=1; bool ok=true;
    for(ll i=0; i<n; i++) {
        ll num, pow; cin>>num>>pow;
        temp=(temp*binexp(num,pow,MOD))%MOD;
        ndiv=((ndiv)*(1+pow))%MOD;
        ndiv_mod=((ndiv_mod)*(1+pow))%(MOD-1);
        ll p1=(((binexp(num,pow+1,MOD)-1+MOD)%MOD)*modInverse((num-1+MOD)%MOD,MOD))%MOD;
        sum=(sum*p1)%MOD;
        
        if(pow&1)  ok=false;
        if(ok)  temp2=(temp2*binexp(num,pow/2,MOD))%MOD;
    }

    ll expo=(ndiv*modInverse(2,MOD))%(MOD-1);
    pr=(pr*binexp(temp,expo,MOD))%MOD;
    if(ok)  pr=(pr*temp2)%MOD;

    cout<<ndiv<<" "<<sum<<" "<<pr;
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