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


void solve(){
     
    
     

}



int main(){
       //IOS;
/*       
    #ifndef ONLINE_JUDGE
      READ;
      WRITE;
    #endif 
*/

   
   int t = 1;
   cin >> t;
   while(t--){
     string s;
     cin >> s;
     s = "!" + s;
     int n = s.size();
     n--;

     vector<int> bal(n + 10);
     int mn = 1e9;
     for (int i = 1; i < s.size(); ++i)
     {   
         if(s[i] == '+'){
           bal[i] = bal[i - 1] + 1;
         }else {
           bal[i] = bal[i - 1] - 1;
         }
        mn =  min(bal[i] , mn);
       /* code */
     }


     ll ans = 0;
     ans += n;
map<int , int> mp;
     for(int i = n;i >= 1;i--){
         mp[bal[i]] = i;
     }
     
     for(int i = 0;i < abs(mn);i++){
       // cout << mp[-i - 1] << endl;
        ans += mp[-i - 1];
     }

     cout << ans << endl;
   }













return 0;}
