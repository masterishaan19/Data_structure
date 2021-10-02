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
#define mod 998244353
#define lower(str) transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) transform(str.begin(), str.end(), str.begin(), ::toupper);
#define mset(a,b) memset(a,b,sizeof(a))
#define crap ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI acos(-1)

// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
ll fastpower(ll x,ll y,ll p){  
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0){  
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p;  
    }  
    return res;  
} 

void kardeBhai(ll ml){
//    cout << "kb for " << ml endl;
    int i ;
//    return ans ;
}
ll sumlaundae(ll n){
    ll i,j,k ;
    i = n ;
    j = n+1 ;
    k = 2*n+1 ;
    if( i%2 == 0 )
        i /= 2 ;
    else
        j /= 2 ;
    if( i%3 == 0 )
        i /= 3 ;
    else if( j%3 == 0 )
        j /= 3 ;
    else
        k /= 3 ;
    i = i%mod ;
    j = j%mod ;
    k = k%mod ;
    n = ((i*j)%mod)*k ;
    n %= mod ;
    return n ;
}
// Function to find modulo inverse of a 
ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y);  
    ll res = (x%m + m) % m; 
    return res; 
} 
ll su(ll n){
	ll a = (n%mod),b = (2*n+1)%mod, c= (n + 1)%mod;
	ll val = modInverse(6,mod);
	ll res = (((a*b)%mod)*c)%mod;
	res = (res*val)%mod;
	return res; 
}
ll suuum(ll a,ll b){
    ll ans=0 ;
    return ans ;
}
  
class noody{
public:
		ll a=1,b=1,c=1,d=1;
		ll den = 4;
};
ll almostPrimes(int n) 
{ 
    // to store required answer 
    int ans = 0; 
  
    // 6 is first almost prime number 
    for (int i = n-1; i <= n; i++) { 
        // to count prime factors 
        int c = 0; 
        for (int j = 2; j * j <= 4; j++) { 
            if (i % j == 0) { 
                // if it is perfect square 
                if (j * j == i) { 
                    // if (prime[j]) 
                        c++; 
                } 
                else { 
                    // if (prime[j]) 
                        c++; 
                    // if (prime[i / j]) 
                        c++; 
                } 
            } 
        } 
  
        // if I is almost prime number 
        if (c == 2) 
            ans++; 
    } 
    return ans; 
}
void sorbae(){
	ll i,j,k,n ;

	string str;
	cin>>str;
	i = modInverse(str.length(),mod);
	if(str.length() == 1)
		cout << "748683265 748683265 748683265 748683265" endl;
	else{
		stack<char> stk;
		stack<noody> stknode;
		i = almostPrimes(str.length()) ;
		j = almostPrimes(str.length()/2) ;
		n = str.length() ;
		li(){
			if(str[i] == '#'){
				noody newNode;
				stk.push('#');
				stknode.push(newNode);
			}
			else if(str[i] != ')'){
				stk.push(str[i]);
			}
			else{
				stk.pop();
				char ch = stk.top();
				stk.pop();
				stk.pop();
				stk.pop();
				if(ch == '&'){
					noody val1 = stknode.top();
					stknode.pop();
					noody val2 = stknode.top();
					stknode.pop();
					noody newNode;
					newNode.a = ((val1.a)*(val2.a + val2.b + val2.c + val2.d) + (val2.a)*(val1.b + val1.c + val1.d) + (val1.c * val2.d) + (val1.d * val2.c))%mod;
					newNode.b = (val1.b * val2.b)%mod;
					newNode.c = ((val1.c * val2.b) + (val1.c * val2.c) + (val1.b * val2.c))%mod;
					newNode.d = ((val1.d * val2.b) + (val1.d * val2.d) + (val1.b * val2.d))%mod;
					newNode.den = (val1.den * val2.den)%mod;
					stknode.push(newNode);
				}
				else if(ch == '|'){
					noody val1 = stknode.top();
					stknode.pop();
					noody val2 = stknode.top();
					stknode.pop();
					noody newNode;
					newNode.a = (val1.a%mod * val2.a%mod)%mod;
					newNode.b = (((val1.b%mod)*(val2.a%mod + val2.b%mod + val2.c%mod + val2.d%mod))%mod + (val2.b%mod)*(val1.a%mod + val1.c%mod + val1.d%mod) + (val1.c * val2.d) + (val1.d * val2.c))%mod;
					newNode.c = ((val1.a * val2.c) + (val1.c * val2.c) + (val1.c * val2.a))%mod;
					newNode.d = ((val1.a * val2.d) + (val1.d * val2.a) + (val1.d * val2.d))%mod;
					newNode.den = (val1.den * val2.den)%mod;
					stknode.push(newNode);
				}
				else{
					noody val1 = stknode.top();
					stknode.pop();
					noody val2 = stknode.top();
					stknode.pop();
					noody newNode;
					newNode.a = ((val1.a * val2.a) + (val1.b * val2.b) + (val1.c * val2.c) + (val1.d * val2.d))%mod;
					newNode.b = ((val1.a * val2.b) + (val1.b * val2.a) + (val1.d * val2.c) + (val1.c * val2.d))%mod;
					newNode.c = ((val1.c * val2.a) + (val1.d * val2.b) + (val1.b * val2.d) + (val1.a * val2.c))%mod;
					newNode.d = ((val1.d * val2.a) + (val1.c * val2.b) + (val1.b * val2.c) + (val1.a * val2.d))%mod;
					newNode.den = (val1.den * val2.den)%mod;
					stknode.push(newNode);
				}
				stk.push('#');
			}
		}
		kardeBhai(69) ;
		i = almostPrimes(str.length()) ;
		j = almostPrimes(str.length()/2) ;
		noody ans = stknode.top();
        cout<< ((ans.a)*modInverse(ans.den,mod))%mod spp ((ans.b)*modInverse(ans.den,mod))%mod spp ((ans.c)*modInverse(ans.den,mod))%mod spp ((ans.d)*modInverse(ans.den,mod))%mod endl;
        // cout << ans.a spp ans.b spp ans.c spp ans.d spp ans.den endl;
	}
}

int main()
{
	ll timer;
	cin>>timer;
	kardeBhai(69) ;
	while(timer--){
		sorbae() ;
	}
	return 0;
}
