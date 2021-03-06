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
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int left(int p ){return p<<1;}
int right(int p ){return (p<<1)+1;}
/*----------------------------------------------------------------------*/

bitset<SIEVELIM> bs;
vll primes;

void sieve(ll LIM){
	bs.set();
	bs[0]=0;
	bs[1]=0;
	F(i, 2, LIM){
		if (bs[i])
		{
			primes.push_back(i);
			for (ll j = i*i; j < LIM; j+=i)
			{
				bs[j]=0;
			}
		}
	}
}

bool checkPrime(ll a){
	if (a<SIEVELIM)
	{
		return bs[a];
	}
	ll range = sqrt(a);
	for (ll i = 0; i < primes.size(); ++i)
	{
		if (primes[i]>range)
		{
			return true;
		}
		if (a%primes[i]==0)
		{
			return false;
		}
	}
	return true;
}

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	sieve(SIEVELIM);
	int t;
	cin>>t;
	ll m,n;

	while(t--){
		cin>>m>>n;
		if (n<SIEVELIM)
		{
			vll::iterator itr = lower_bound(primes.begin(),primes.end(),m);
			ll index = itr-primes.begin();
			while(primes[index]<=n){
				cout<<primes[index]<<"\n";
				index++;
			}
		}else{
			F(i, m, n+1){
				if (checkPrime(i))
				{
					cout<<i<<"\n";
				}
			}
		}
		if (t)
		{
			cout<<"\n";	
		}
	}
	return 0;
}
