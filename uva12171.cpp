//Bismillahir Rahmanir Rahim
 
#include<bits/stdc++.h>
 
#define ll long long int
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
 

using namespace std;



///********************************MY CODE STARTS HERE********************************///

 
int dx[] = { 1, 0, 0, -1, 0, 0 };
int dy[] = { 0, 1, 0, 0, -1, 0 };
int dz[] = { 0, 0, 1, 0, 0, -1 };
 
struct info{
    int x , y , z , a , b , c;
};

struct point{
    int x , y , z;
};


int real_x[1111] , real_y[1111], real_z[1111] , remap_y[1111], remap_x[1111] , remap_z[1111];


int grid[111][111][111];

bool valid(int x , int y , int z){
	if(x < 0 || y < 0 || z < 0 || x > 100 || y > 100 || z > 100) return false;
	return true;
}



void bfs(){

	queue<point > q;
	point s;
	s.x = 0;
	s.y = 0;
	s.z = 0;

	q.push(s);

	grid[0][0][0] = 2;

	while(!q.empty()){
		point u = q.front();
		q.pop();
		int x = u.x;
		int y = u.y;
		int z = u.z;


		for(int k = 0;k < 6;k++){

		      	int X = dx[k] + x;
		      	int Y = dy[k] + y;
		      	int Z = dz[k] + z;
                
                if(valid(X , Y , Z) && grid[X][Y][Z] == 0){

		      		grid[X][Y][Z] = 2;

		      		point temp;
		      		temp.x = X;
		      		temp.y = Y;
		      		temp.z = Z;
		      	    q.push(temp);

		      	}
		} 
	}
	
    
}


 
void solve(){
    
    int n;
    sci(n);

    vector<struct info> v;
    vector<int> st[4];

    for(int i = 0;i < n;i++){
    	int X , Y , Z , A , B  , C;

    	sciii(X , Y , Z);
    	sciii(A , B , C);


    	struct info temp;
    	temp.x = X;
    	temp.y = Y;
    	temp.z = Z;
    	temp.a = X + A;
    	temp.b = Y + B;
    	temp.c = Z + C;

        v.pb(temp);

    	st[0].pb(X);
    	st[0].pb(X + A);
    	st[1].pb(Y);
    	st[1].pb(Y + B);
    	st[2].pb(Z);
    	st[2].pb(Z + C);


    }

    for(int i = 0;i < 3;i++){

    	sort(all(st[i]));
    	auto ip = unique(all(st[i]));
    	st[i].resize(distance(st[i].begin() , ip));
        

    }

        int cnt = 1;
    	for(int j = 0;j < st[0].size();j++){
           remap_x[st[0][j]] = cnt;
           real_x[cnt] = st[0][j];
           cnt++;
    	}

        cnt = 1;
    	for(int j = 0;j < st[1].size();j++){
           remap_y[st[1][j]] = cnt;
           real_y[cnt] = st[1][j];
           cnt++;
    	}

        cnt = 1;
    	for(int j = 0;j < st[2].size();j++){
           remap_z[st[2][j]] = cnt;
           real_z[cnt] = st[2][j];
           cnt++;
    	}


    

    for(int i = 0;i < n;i++){
       int X , Y , Z , A , B , C;
       X = remap_x[v[i].x];
       Y = remap_y[v[i].y];
       Z = remap_z[v[i].z];

       A = remap_x[v[i].a];
       B = remap_y[v[i].b];
       C = remap_z[v[i].c];



       for(int j = X;j < A;j++){
       	  for(int k = Y;k < B;k++){
       	  	 for(int l = Z;l < C;l++){
       	  	 	grid[j][k][l] = 1;
       	  	 }
       	  }
       }
   	



    }


    bfs();

    
    ll vol = 0 , area = 0;

    for(int i = 0;i <= 100;i++){
    	for(int j = 0;j <= 100;j++){
    		for(int k = 0;k <= 100;k++){
    			ll x = real_x[i + 1] - real_x[i];
    			ll y = real_y[j + 1] - real_y[j];
    			ll z = real_z[k + 1] - real_z[k];

                if(grid[i][j][k] != 2){
                    vol += x * y * z;
                    continue;
                }

		        for(int l = 0;l < 6;l++){
		      		int X = dx[l] + i;
		      		int Y = dy[l] + j;
		      		int Z = dz[l] + k;
                
              	  if(valid(X , Y , Z) && grid[X][Y][Z] != 2){
              	  	if(dx[l] != 0) area += y * z;
              	  	else if(dy[l] != 0) area += x * z;
              	  	else area += x * y;
		     	  } 
		        } 


    		}
    	}
    }

    printf("%lld %lld\n", area , vol);





}
 
 
int main(){
       //IOS;
    
    int T = 1;
    sci(T);
    while(T--){

    	mem(grid , 0);
    	mem(real_x , 0);
    	mem(real_y , 0);
    	mem(real_z , 0);
    	mem(remap_x , 0);
    	mem(remap_y , 0);
    	mem(remap_z , 0);


        solve();
    }
 
return 0;
}