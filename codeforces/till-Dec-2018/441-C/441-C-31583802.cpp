#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000000+10
#define MOD 1000000000+7
#define EPS 1e-7
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
/*----------------------------------------------------------------------*/

int n,m,k;

bool check(int x,int y){
	return (x>=1 && x<=n && y>=1 && y<=m);
}

int dir[2]={1,-1};

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	cin>>n>>m>>k;

 	int x=1,y=1,currdir=0;
 	int rem = n*m-(2*k)+2;
 	
 	while(k>1 && k--){
 		int nextx,nexty;
 		if (check(x,y+dir[currdir]))
 		{
 			nexty = y+dir[currdir];
 			nextx = x;
 		}else{
 			nexty = y;
 			nextx = x+1;
 			currdir = 1- currdir;
 		}

		printf("2 %d %d %d %d\n",x,y,nextx,nexty);

		if (check(nextx,nexty+dir[currdir]))
 		{
 			y = nexty+dir[currdir];
 			x = nextx;
 		}else{
 			y = nexty;
 			x = nextx+1;
 			currdir = 1- currdir;
 		}		
 	}


 	printf("%d",rem);
 	while(rem--){
 		printf(" %d %d",x,y);
 		if (check(x,y+dir[currdir]))
 		{
 			y = y+dir[currdir];
 		}else{
 			x = x+1;
 			currdir = 1- currdir;
 		}
 	}
	return 0;
}