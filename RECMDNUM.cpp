#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define endl << "\n"
#define sp << " "
#define spp << " " <<
#define all(v) v.begin(),v.end()
#define a(n) a,a+n
#define lmax 9223372036854775807
#define lmin -9223372036854775808
#define li() for(i=0;i<n;++i)
#define lie(a,b) for(i=a;i<b;++i)
#define lj() for(j=0;j<n;++j)
#define lje(a,b) for(j=a;j<b;++j)
#define ft first
#define sd second
#define pb push_back
#define pf push_pront
#define mod 1000000007
#define lower(str) transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) transform(str.begin(), str.end(), str.begin(), ::toupper);
#define mset(a,b) memset(a,b,sizeof(a))
#define crap ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI acos(-1)

ll smm(ll a){
	ll x=a,y=a+1 ;
	x %= mod , y %= mod ;
	a = (x*y)%mod ;
	return a ;
}


int main(){
//	crap ;
    int timer;
    cin >>timer;
    while(timer--){
    	ll n,i,j,ans,k ;
    	cin >>n >>k ;
    	if( n == 0 ){
    		ans = smm(k-1) ;
    	}
    	else{
    		if( k == 1 ){
    			ans = (smm(n-1) + n)%mod ;
    		}
    		else{
    			k-- ;
    			if( k%2 == 0 ){
    				ans = smm(n+k/2) ;
    				ans -= n ;
    			}
    			else{
    				ans = (smm(n + (k-1)/2 )+n)%mod ;
    			}
    		}
    	}
    	if( ans < 0 )
    		ans += mod ;
    	cout << ans endl ;
    }
}