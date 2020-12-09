//Bismillahir Rahmanir Rahim
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
    
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define xx first
#define yy second
#define sci(n) scanf("%d",&n)
#define scii(n,m) scanf("%d%d",&n,&m)
#define sciii(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scl(n) scanf("%lld",&n)
#define scll(n,m) scanf("%lld%lld",&n,&m)
#define sclll(n,m,w) scanf("%lld%lld%lld",&n,&m,&w)
#define pf(a)   printf("%d\n",a)
#define CASE(a) printf("Case %d: ",a)
#define dbg(i) printf("yo %d\n", i)
#define endl '\n'
#define READ  freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout);
#define pi acos(-1)
#define mem(a,b) memset(a,b,sizeof(a))
#define SQR(a) (a)*(a)
#define all(v) v.begin(),v.end()
#define pb push_back
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define inf INT_MAX
#define eps 1e-9
 
using namespace __gnu_pbds;
using namespace std;
 
#define mxn 100005
 
 
ll dp[mxn] , pos[mxn];
 
int main(){
       IOS;

 
int t;
cin >> t;
while(t--){
    
    ll n;
    cin >> n;
    vector<pll> v;
    v.pb({-1 , 0});
 
    for(ll i = 1;i <= n;i++ ){
      ll x;
      cin >> x;
      v.pb({x , i});
    }
    
    sort(v.begin() + 1, v.end());
    
    for(int i = 1;i < v.size();i++){
      pos[v[i].yy] = i;
    }
 
    ll ans = 1;
    for(int i = 1;i <= n;i++){
      ll q = v[i].yy;
      //cout << q << endl;
      // cout << dp[1] << endl;
 
       ll lim = sqrt((double)q + 1.0);
 
       for(ll j = 1;j <= lim;j++){
           if(q == 1){
              dp[q] = 1LL;
              continue;
           }
          
           if(q % j == 0){
             // if(q == 5) cout <<"hi " <<j << endl;  
 
              if(v[i].xx > v[pos[j]].xx)
               { dp[q] = max(dp[j] + 1 , dp[q]);}
             else dp[q] = max(dp[q] , 1LL);
              ans = max(ans , dp[q]);
              
              if(j == 1) continue;
              if(v[i].xx > v[pos[q / j]].xx){
              dp[q] = max(dp[q / j] + 1 , dp[q]);}
              else dp[q] = max(dp[q] , 1LL);
              
              ans = max(ans , dp[q]);
            
 
           }
       }

    }
    
 
    cout << ans << endl;
    
    for(int i = 1;i <= n;i++){
     //cout << dp[i] << " ";
     dp[i] = 0; 
    }
 
    //cout << endl;
 
 
 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
return 0;}