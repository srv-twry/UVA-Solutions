#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 0x3f3f3f3f
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
ll leftChild(ll p ){return p<<1;}
ll rightChild(ll p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x; 
#define endl    "\n"
#define pb push_back
#define mp make_pair
#define all(cc) (cc).begin(),(cc).end()

template<typename T > void modulize(T & a, const T & b) { if (a >= b) { a %= b; } }
/*----------------------------------------------------------------------*/

ll target=0;
ll valid = 0;

void solve(string s, int pos,int curr){

	if (pos==s.size())
	{
		if (curr==target)
		{
			valid++;
		}
		return;
	}

	if (s[pos]=='?')
	{
		s[pos] = '+';
		solve(s,pos+1,curr+1);
		s[pos] = '-';
		solve(s,pos+1,curr-1);
		s[pos] = '?';
	}else{
		if (s[pos]=='+')
		{
			solve(s,pos+1,curr+1);
		}else{
			solve(s,pos+1,curr-1);
		}
	}

	
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    string a,b;
    cin>>a>>b;

    F(i, 0, a.size()){
    	if (a[i]=='+')
    	{
    		target++;
    	}else{
    		target--;
    	}
    }
    int avail = 0;
    F(i, 0, b.size()){
    	if (b[i]=='?')
    	{
    		avail++;
    	}
    }

    solve(b,0,0);

    double prob =  (double)valid/(double) pow(2,avail);
    coud(prob,11);
    return 0;       
}