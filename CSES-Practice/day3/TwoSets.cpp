// Intro -> Two Sets

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
 
 
 
// self done -> 
// void solve() {
//     ll n; cin>>n;
//     ll tsum = (1LL*n*(n+1))/2;
//     if(tsum&1)  { cout<<"NO"; return; }

//     ll cnt=0;
//     map<ll,ll> mpp1;
//     ll me=n, target=tsum/2;
//     while(target>0) {
//         cnt++;
//         if(target>=me) {  target-=me; mpp1[me]++; me--; }
//         else { mpp1[target]=1; break; }
//     }

//     cout<<"YES"<<endl;
//     cout<<cnt<<endl;
//     for(ll i=1; i<=n; i++) { if(mpp1[i]) cout<<i<<" "; }
//     cout << "\n" << n-cnt<<endl;
//     for(ll i=1; i<=n; i++) { if(!mpp1[i]) cout<<i<<" "; }

// }


// editorial version ->
void solve() {
    ll n; cin>>n;
    ll tsum = (1LL*n*(n+1))/2;
    if(tsum&1)  { cout<<"NO"; return; }

    set<ll> st1; set<ll> st2;
    ll target = tsum/2, sum=0;
    for(ll i=n; i>0; i--) {
        if(sum+i<=target)  { st1.insert(i); sum+=i; }
        else st2.insert(i);
    }

    cout<<"YES"<<endl;
    cout<<st1.size()<<endl;
    for(auto& x:st1)  cout<< x << " ";
    cout<<"\n" << st2.size() << endl;
    for(auto& x:st2)  cout<<x<<" ";

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