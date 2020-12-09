//Bismillahir Rahmanir Rahim

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
		
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

//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};

//ll ncr(ll n,ll r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}

// bit manipulations

bool checkbit(ll mask,ll bit){return mask & (1<<bit);}
int setbit(int mask,int bit){ return mask | (1<<bit) ; }
int clearbit(int mask,int bit){return mask & ~(1<<bit);}
int togglebit(int mask,int bit){return mask ^ (1<<bit);}
int bitno(int mask) {return (int)__builtin_popcount(mask);}

template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template <typename T> T Bigmod(T b,T p,T m){ if(p==0) return 1; else if (!(p&1)) return SQR(Bigmod(b,p/2,m)) % m;else return ((b % m) * Bigmod(b,p-1,m)) % m;}
template <typename T> T Dis(T x1,T y1,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}
template <typename T> T Angle(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}
template <typename T> T DIFF(T a,T b) { T d = a-b;if(d<0)return -d;else return d;}
template <typename T> T ABS(T a) {if(a<0)return -a;else return a;}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T> T euclide(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> void ia (T a[],int n){for (int i=0; i<n; i++) cin >> a[i];}
template <typename T> void pa (T a[],int n){for (int i=0; i<n-1; i++) cout << a[i] << " ";cout << a[n-1] << endl;}
template <typename T> ll isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);}

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

///********************************MY CODE STARTS HERE********************************///


#define mxn 100005

int arr[mxn];
int n;
struct info{
ll sum;   
ll lazy;
}seg[4 * mxn];

int adj[4 * mxn][33];

void build(int node,int b,int e){

     
     if(b == e){
        seg[node].sum  = arr[b];
        seg[node].lazy = 0;
        
        int n = arr[b];

        for(int i = 0;i < 30;i++){
        	if(checkbit(n , i)) adj[node][i] = 1;
        	else adj[node][i] = 0;
        }
        
        return;
     }

     int left = 2 * node;
     int right = left + 1;
     int mid = (b + e) / 2;

     build(left,b,mid);
     build(right,mid + 1,e);

     for(int i = 0;i < 30;i++){
     	adj[node][i] = (adj[left][i] + adj[right][i]);
     }

     seg[node].sum = seg[left].sum + seg[right].sum;

}

void update(int node,int b,int e,int i, int j, int x){

     if(b > j || e < i) return;
     if(b >= i && e <= j){
        //seg[node].sum  += (e - b + 1) * x;
        seg[node].lazy ^= x;
        
        int lazy_xor = seg[node].lazy;
        dbg(lazy_xor); 
        ll n = (e - b + 1);
        seg[node].sum = 0;
        for(int i = 0;i < 30;i++){
           if(checkbit(lazy_xor , i)){
              seg[node].sum += (ll)(n - adj[node][i]) * (1 << i); 
              adj[node][i] = n - adj[node][i];    
           }else{
           	  seg[node].sum += (ll)adj[node][i] * (1 << i);
           }
        }    


        return;
     }

     int left = 2 * node;
     int right = left + 1;
     int mid = (b + e) / 2;


        if(seg[node].lazy != 0){

        seg[left].lazy  ^= seg[node].lazy;
        seg[right].lazy ^= seg[node].lazy;
        seg[left].sum = 0;
        seg[right].sum = 0;
        for(int i = 0;i < 30;i++){
              
           if(checkbit(seg[left].lazy , i)){
              seg[left].sum += (ll)((mid - b + 1) - adj[left][i]) * (1 << i); 
              //adj[left][i] = ((mid - b + 1) - adj[left][i]);    
           }else{
           	  seg[left].sum += (ll)adj[left][i] * (1 << i);
           }

           if(checkbit(seg[right].lazy , i)){
              seg[right].sum += (ll)((e - mid) - adj[right][i]) * (1 << i); 
              //adj[right][i] = ((e - mid) - adj[right][i]);    
           }else{
           	  seg[right].sum += (ll)adj[right][i] * (1 << i);
           }

        }
        
        seg[node].lazy = 0;
     }



     update(left,b,mid,i,j,x);
     update(right,mid + 1,e,i,j,x);

     for(int i = 0;i < 30;i++){
     	adj[node][i] = (adj[left][i] + adj[right][i]);
     }

     seg[node].sum = seg[left].sum + seg[right].sum;

}


//int lazy_xor = 0;

ll query(int node,int b,int e,int i, int j){

   if(b > j || e < i) return 0;
   if(b >= i && e <= j){

        
        return seg[node].sum;
   }

   int left = node * 2;
   int right = left + 1;
   int mid = (b + e) / 2;

     //    if(seg[node].lazy != 0){

     //    seg[left].lazy  ^= seg[node].lazy;
     //    seg[right].lazy ^= seg[node].lazy;
     //    seg[left].sum = 0;
     //    seg[right].sum = 0;
     //    for(int i = 0;i < 30;i++){
              
     //       if(checkbit(seg[left].lazy , i)){
     //          seg[left].sum += (ll)((mid - b + 1) - adj[left][i]) * (1 << i); 
     //          adj[left][i] = ((mid - b + 1) - adj[left][i]);    
     //       }else{
     //       	  seg[left].sum += (ll)adj[left][i] * (1 << i);
     //       }

     //       if(checkbit(seg[right].lazy , i)){
     //          seg[right].sum += (ll)((e - mid) - adj[right][i]) * (1 << i); 
     //          adj[right][i] = ((e - mid) - adj[right][i]);    
     //       }else{
     //       	  seg[right].sum += (ll)adj[right][i] * (1 << i);
     //       }

     //    }
        
     //    seg[node].lazy = 0;
     // }



   ll x = query(left,b,mid,i,j);
   ll y = query(right,mid + 1,e,i,j);
   
    // for(int i = 0;i < 30;i++){
    //  	adj[node][i] = (adj[left][i] + adj[right][i]);
    // }


   return x + y;
}



int main(){
       //IOS;
/*       
    #ifndef ONLINE_JUDGE
      READ;
      WRITE;
    #endif 
*/
   




    sci(n);

    for(int  i = 0;i < n;i++){
    	sci(arr[i]);
    }


    build(1 , 0 , n - 1);
    
   // cout << seg[1].sum << endl;

    for(int i = 0;i < 15;i++){
    	cout << adj[1][i] <<" ";
    }

    int q;
    sci(q);
    //cout << (1 << 0) << endl;

    while(q--){

    	int t;
    	sci(t);
    	if(t == 1){
          int l , r;
          scii(l , r);
          l--; r--;
          //lazy_xor = 0;
          update(1 , 0 , n - 1, l , r , 0);
              for(int i = 0;i < 15;i++){
    	cout << adj[1][i] <<" ";
    }
          ll ans = query(1 , 0 , n - 1, l , r);
          printf("%lld\n", ans);

    	}else{
          int l , r , x;
          sciii(l , r , x);
          l--; r--;
          update(1 , 0 , n - 1, l , r , x);


    for(int i = 0;i < 15;i++){
    	cout << adj[1][i] <<" ";
    }
    	}
    }











return 0;}
