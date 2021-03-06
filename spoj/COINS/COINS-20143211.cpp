#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

ll dp[1000005];

ll ans(ll n){
	if (n<=1000000)
	{
		if (dp[n]!=-1)
		{
			return dp[n];
		}
		return dp[n]=ans(n/2)+ans(n/4)+ans(n/3);
	}
	return ans(n/2)+ans(n/3)+ans(n/4);
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	memset(dp,-1,sizeof(dp));
	F(i, 0, 12){
		dp[i]=i;
	}
	while(cin>>n){
		cout<<ans(n)<<"\n";
	}

	return 0;
}