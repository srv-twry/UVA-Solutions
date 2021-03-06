#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000000+10
#define EPS 1e-7
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )		cerr << #x << " here "<< x; 
#define endline		"\n"
#define pb push_back
#define mp make_pair
/*----------------------------------------------------------------------*/

const int N = 10000000+10;
ll sum[N],counter[N];
bitset<N> bs;

void sieve(){
	bs.set();
	bs[0]=0;
	bs[1]=0;
	F(i, 2, N){
		if (bs[i])
		{
			for (ll j = i; j <=N; j+=i)
			{
				bs[j]=0;
				sum[i]+=counter[j];
			}
		}
		sum[i]+=sum[i-1];
	}
}

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	int n;
 	cin>>n;

 	memset(counter, 0, sizeof(counter));

 	ll temp;
 	F(i, 0, n){
 		temp = nextll();
 		counter[temp]++;
 	}

 	memset(sum,0,sizeof(sum));

 	sieve();

 	int m;
 	cin>>m;

 	ll l,r;

 	while(m--){
 		l = nextll();
 		r = nextll();
 		if (l>10000000)
 		{
 			l =10000000;
 		}
 		if (r>10000000)
 		{
 			r = 10000000;
 		}
 		cout<<sum[r]-sum[l-1]<<endline;
 	}


 	return 0;	
}