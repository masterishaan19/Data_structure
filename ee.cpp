#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo2(i,a,n) for(ll i=n;i>=a;i--)
#define endl "\n"
#define sp " "
#define f first
#define s second
#define pb push_back
#define buffer ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define lower(str) transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) transform(str.begin(), str.end(), str.begin(), ::toupper);
#define init(arr,val) memset(arr,val,sizeof(arr))
#define vecl(v) vector<ll> v
#define vecs(v) vector<string> v
#define vecp(v) vector < pair <ll,ll> > v

ll gcdExtended(ll a, ll b, ll *x, ll *y); 
  

// Function to find modulo inverse of a 
ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y);  
    ll res = (x%m + m) % m; 
    return res; 
} 
  

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

ll sumOfSquares(ll n){
	ll res=0;
	ll a = (n%mod);
	ll b = (2*n+1)%mod;
	ll c= (n + 1)%mod;
	ll val = modInverse(6,mod);
	res = (a*b)%mod;
	res = (res*c)%mod;
	res = (res*val)%mod;
	return res; 
}



int main()
{
	ll t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;
		// cout<<"here 0"<<endl;
		ll xo = (ll)cbrt((long double)n);
		bool flag[1000010];
		init(flag,false);
		vector<ll> v; 
	    for (ll i = 2; i * i * i <= xo; i++) { 
	        ll j = i * i; 
	        while (j * i <= xo) {   
	            j *= i;
	            ll s = sqrtl(j); 
	            if (s * s != j){ 
	                v.push_back(j);
	                flag[j] = true;
	            } 
	        } 
	    } 
	  	// cout<<"here 1 "<<endl;
	    sort(v.begin(), v.end()); 
	    v.erase(unique(v.begin(), v.end()), v.end()); 
	    ll number = 1; 
   

	    ll n2 = number * number; 
	  

	    number = (number * 2) + 1; 
	  

	    while ((n2 >= 1 && n2 <= xo)) {
	        v.pb(n2);
	        flag[n2] = true;
	  		n2 = n2 + number;
	        number += 2; 
	    }

	    vecl(req);
	   	

	    for(ll i=2;i<= xo;i++){
	    	if(flag[i] == false){
	    		req.pb(i);
	    	}
	    }

	    ll val = xo*xo ;
	    ll sum=0;
	    cout << "size = " <<req.size() << sp << xo  <<endl ;
	   	for(auto it:req){
	   		ll temp = it*it;
	   		ll j=2;
	   		while(temp <= n){
	   			if(j%2 == 0 && temp >val)
	   			{
	   				// cout<<" it of 1 : "<<it<<sp;
	   				// cout<< temp <<endl;
	   				if(temp <= (n/it))
	   					temp *= it;
	   				else{
	   					break;
	   				}
	   				// cout<<" in1 "<<endl;
	   			}
	   			else{
	   				// cout<<" it of 2 : "<<it<<sp;
	   				// cout<< temp <<endl;
	   				// cout<< temp * (n/temp) <<endl;
	   				sum = (sum%mod + ( temp * (n/temp) )%mod)%mod ;
	   				

	   				if(temp <= (n/it))
	   					temp *= it;
	   				else{
	   					break;
	   				}
	   				// cout<<" in2 "<<endl;
	   			}
	   			j++;
	   		}

	   	}
		cout << "sum before = " << sum << endl ;
	   	ll yossa = n;
	   	ll counter = 1;
	   	ll dattebayo = sumOfSquares(xo);
	   	while( (ll)sqrtl(yossa/counter) > xo ){
	   		// cout<<"yossa"<<yossa/counter<<endl;
	   		ll y = (sumOfSquares( (ll)sqrtl(yossa/counter)))%mod ;
	   		

	   		if(y<dattebayo)
	   			y+=mod;

	   		sum = ((sum%mod) + (y - dattebayo)%mod)%mod;
	   		counter++;
	   	}
	   	// cout<<sumOfSquares(1000000000000000000)<<endl;
//	   	cout<<counter<<endl;
	   	cout<<(sum+n)%mod <<endl;
	}

	return 0;
}

