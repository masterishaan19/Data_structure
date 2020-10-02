#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define endl << "\n"
#define sp << " "
#define spp << " " <<
#define allv(v) v.begin(),v.end()
#define lmax 9223372036854775807
#define lmin -9223372036854775807
#define lopi() for(i=0;i<n;++i)
#define loi(a,b) for(i=a;i<b;++i)
#define lopj() for(j=0;j<n;++j)
#define loj(a,b) for(j=a;j<b;++j)
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

int main(){
//  crap ;
    int timer,x,y,l;
    int prime[1000001] = {0} ;
    prime[0] = prime[1] = 1 ;
    for(x=2;x<1000001;x++){
        if( prime[x] == 0 ){
            y = 2*x ;
            for(l=y;l<1000001;l+=x)
                prime[l] = 1 ;
        }
    }
    cin >>timer;
    // timer=1 ;
    while(timer--){
        ll n,m,i,j,k,a,b ;
        cin >> n;
        i = sqrt(n) ;
        if( i*i == n && prime[i] == 0 )
            cout << "YES" endl ;
        else
            cout << "NO" endl ;
    }
}
