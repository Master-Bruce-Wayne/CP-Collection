// lcs

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
vl a, b;

ll rec(ll i,ll j,vvl& dp) {
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)  return dp[i][j];

    ll ans=0;
    if(a[i]==b[j]) {  ans=max(ans, 1+rec(i-1,j-1,dp));  }
    ans=max({ans, rec(i-1,j,dp),rec(i,j-1,dp)}); 
    return dp[i][j]=ans;
}

void solve() {
    cin>>n>>m;
    a.resize(n); b.resize(m);
    for(ll i=0; i<n; i++)  cin>>a[i];
    for(ll i=0; i<m ; i++) cin>>b[i];

    vvl dp(n, vl(m,-1));
    cout<<rec(n-1,m-1,dp)<<endl;

    vl ans;
    ll i=n-1, j=m-1;
    while(i>=0 && j>=0) {
        if(a[i]==b[j]) {
            ans.push_back(a[i]);  i--; j--;
        }
        else if(i==0)  j--;
        else if(j==0)  i--;
        else if (dp[i-1][j]>dp[i][j-1]) {
            i--; 
        }
        else j--;
    }

    if(ans.size()==1)  { cout<<ans[0]; return; }
    for(ll i=ans.size()-1; i>=0; i--)  cout<<ans[i]<<" ";
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