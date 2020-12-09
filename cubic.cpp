#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		long long mid=((1LL<<m)-n-1)/2;
		long long a[n+1];
		for(int i=1;i<=n;i++){
			string str;
			cin>>str;
			a[i]=bitset<65>(str).to_ullong();
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]<=mid){
				mid++;
			}
		}
		cout<<bitset<65>(mid).to_string().substr(65-m)<<"\n";
	}
}