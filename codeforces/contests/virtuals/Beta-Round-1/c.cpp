#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
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
const ll INF = LONG_LONG_MAX;
const double eps = 1e-4;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x; 
#define endl    "\n"
#define pb push_back
#define mp make_pair
#define all(cc) (cc).begin(),(cc).end()

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

template<typename T > void modulize(T & a, const T & b) { if (a >= b) { a %= b; } }
ll mulmod(ll a, ll b, ll m) { ll q = (ll)(((ld)a*(ld)b) / (ld)m); ll r = a*b - q*m; if (r>m)r %= m; if (r<0)r += m; return r; }
template <typename T, typename S>T expo(T e, S n) { T x = 1, p = e; while (n) { if (n & 1)x = x*p; p = p*p; n >>= 1; }return x; }
template <typename T>T power(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mod(x*p, m); p = mod(p*p, m); n >>= 1; }return x; }
template <typename T>T powerL(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mulmod(x, p, m); p = mulmod(p, p, m); n >>= 1; }return x; }
template <typename T> T InverseEuler(T a, T & m) { return (a == 1 ? 1 : power(a, m - 2, m)); }

inline int two(int n) { return 1 << n; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
/*----------------------------------------------------------------------*/

double gcd(double x, double y)
{
    while (fabs(x) > eps && fabs(y) > eps)
    {
        if (x > y)
                x -= floor(x / y) * y;
        else
                y -= floor(y / x) * x;
    }
    return x + y;
}

double area(double a,double b,double c)
{
    double s=((double)a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    pair<double, double> a[3];
    F(i, 0, 3){
    	scanf("%lf %lf",&a[i].first, &a[i].second);
    }
    double sides[3];
    sides[2] = sqrt((a[0].first - a[1].first)*(a[0].first - a[1].first) + (a[0].second - a[1].second)*(a[0].second - a[1].second));
    sides[0] = sqrt((a[2].first - a[1].first)*(a[2].first - a[1].first) + (a[2].second - a[1].second)*(a[2].second - a[1].second));
    sides[1] = sqrt((a[2].first - a[0].first)*(a[2].first - a[0].first) + (a[2].second - a[0].second)*(a[2].second - a[0].second));
    double radius,areat;
    areat = area(sides[0], sides[1], sides[2]);
    radius = (sides[0]*sides[1]*sides[2])/((4.0)*areat);
    double A,B,C;
    A=acos((sides[1]*sides[1]+sides[2]*sides[2]-sides[0]*sides[0])/(2*sides[2]*sides[1]));
    B=acos((sides[0]*sides[0]+sides[2]*sides[2]-sides[1]*sides[1])/(2*sides[0]*sides[2]));
    C=acos((sides[0]*sides[0]+sides[1]*sides[1]-sides[2]*sides[2])/(2*sides[0]*sides[1]));
    double g=gcd(A,gcd(B,C));
    double n=(PI)/(g);
    double ans=((double)radius*radius*n*sin((2*PI)/n))/2;
    printf("%.6lf\n",ans);

    return 0;          
}/*
    
*/
 