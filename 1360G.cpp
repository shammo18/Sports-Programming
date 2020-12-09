#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;++i)



int value[505];
int weight[505];
int dp[10001];

int minval(int weight_, int n)
{
	if(weight_<0) return INT_MAX;
	if(dp[weight_]!=INT_MAX) return dp[weight_];
	int minvalue=1e9 + 5;
	FOR(i, 1, n+1)
	{

			minvalue = min(minvalue, dp[weight_-weight[i]]+value[i]);
		
	}


		dp[weight_] = minvalue;
	
	return dp[weight_];
}

int main()
{
	int t,e,f,types;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d",&e,&f);
		scanf("%d", &types);
		FOR(i,1,types+1)
		{
			scanf("%d %d", &value[i], &weight[i]);
		}
		FOR(i,0,10001)
		{
			dp[i] = INT_MAX;
		}
		dp[0] = 0;
		int weight_ = f-e;
		int res = minval(weight_, types);
		if(res == INT_MAX)
		{
			printf("This is impossible.\n");
		}
		else
		{
			printf("The minimum amount of money in the piggy-bank is %d.\n",res);
		}
	}
}