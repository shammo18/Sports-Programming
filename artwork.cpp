//Bismillahir Rahmanir Rahim

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
		
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

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

// using namespace __gnu_pbds;
using namespace std;

///********************************MY CODE STARTS HERE********************************///


#define mxn 1005

int cum[mxn][mxn];
int row , col , q;

int cnt;

struct data{
    int r1 , r2 , c1 , c2;
};

int dx[] = {0, -1, 0,1,1,1,-1,-1};
int dy[] = {-1, 0, 1,0,1,-1,-1,1};

inline bool valid(int x , int y){
	if(x < 0 || y < 0 || x >= row || y >= col) return false;
	return true;
}


int par[mxn * mxn] , rnk[mxn * mxn];


int find_par(int v){

      if(v == par[v]) return v;
      return par[v] = find_par(par[v]);

}



int merge(int u, int v) {
    return par[find_par(u)] = find_par(v);
}


void union_sets(int a, int b){

     a = find_par(a);
     b = find_par(b);

     if(a != b){
        if(rnk[a] < rnk[b]) swap(a,b);
        par[b] = a;
        cnt--;

        if(rnk[a] == rnk[b])
        rnk[a]++;
     }

}

inline int node(int x , int y){
	return (x * col + y);
}

int main(){
       //IOS;
    
    sciii(col , row , q);   cnt = 0;
    vector<data> v(q);

    for(int i = 0;i < q;i++){
       scii(v[i].c1 , v[i].r1); v[i].c1--; v[i].r1--;
       scii(v[i].c2 , v[i].r2); v[i].c2--; v[i].r2--;

       cum[v[i].r1][v[i].c1]++;
       cum[v[i].r2 + 1][v[i].c2 + 1]++;
       cum[v[i].r1][v[i].c2 + 1]--;
       cum[v[i].r2 + 1][v[i].c1]--;
    }

    for(int i = 0;i < row*col;i++) par[i] = i;

    for(int x = 0; x < row; x++) {
        for(int y = 0; y < col; y++) {
        	if(x == 0 && y == 0){;}
        	else if(x == 0){
               cum[x][y] += cum[x][y - 1];
        	}else if(y == 0){
               cum[x][y] += cum[x - 1][y];
        	}else cum[x][y] += cum[x][y-1] + cum[x-1][y] - cum[x-1][y-1];
            
            if(cum[x][y] == 0){
            	cnt++;
            	//error(x , y);
                for(int i = 0;i < 2;i++){
                	int X = dx[i] + x;
                	int Y = dy[i] + y;

                	if(valid(X , Y) && cum[X][Y] == 0){
                		//int o = node(X , Y);
                		//error(o);
                        union_sets(node(x , y) , node(X , Y));
                	}
                }
            }

        	// cout << cum[x][y] << " ";
        }
        // cout << endl;
    }


    //cout << cnt << endl;

   // for(int i = 0;i < row*col;i++) cout << par[i] <<" ";
    vector<int> ans;

    for(int i = q - 1;i >= 0;i--){
    	ans.pb(cnt);
       if(v[i].r1 == v[i].r2){

       	  for(int j = v[i].c1;j <= v[i].c2;j++)
         	cum[v[i].r1][j]--;
         for(int j = v[i].c1;j <= v[i].c2;j++){
         	// cum[v[i].r1][j]--;
         	if(cum[v[i].r1][j] == 0){
         		cnt++;
                
                int x = v[i].r1; int y = j;

         		for(int i = 0;i < 4;i++){
                	int X = dx[i] + x;
                	int Y = dy[i] + y;

                	if(valid(X , Y) && cum[X][Y] == 0){
                        union_sets(node(x , y) , node(X , Y));
                	}
                }

         	}

         }  
       }else{
         for(int j = v[i].r1;j <= v[i].r2;j++)
         	cum[j][v[i].c1]--;
         for(int j = v[i].r1;j <= v[i].r2;j++){
         	// cum[j][v[i].c1]--;
         	if(cum[j][v[i].c1] == 0){
         		cnt++;
                
                int y = v[i].c1; int x = j;

         		for(int i = 0;i < 4;i++){
                	int X = dx[i] + x;
                	int Y = dy[i] + y;

                	if(valid(X , Y) && cum[X][Y] == 0){
                        union_sets(node(x , y) , node(X , Y));
                	}
                }

         	}

         }
       }
       
    }
    
    reverse(all(ans));

    for(int u : ans) printf("%d\n",u );














return 0;}
