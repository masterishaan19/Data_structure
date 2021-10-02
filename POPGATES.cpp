#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define fo(i,s,e) for(int i=s;i<e;++i)
#define endl << "\n"
#define sp << " "
#define ft first
#define sd second
#define pb push_back
#define pf push_pront
#define mod 1000000007
#define crap ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.14159265358979323846264338327950288419716939937510

int main(){
	crap ;
	int timer ;
	cin>>timer ;
	while(timer--){
		int n,k,i,h=0,t=0,c=0;
		cin >>n >>k ;
		char dta[n] ;
		fflush(stdin) ;
		for(i=0;i<n;++i)
			cin >> dta[i];
		for(i=0;i<n-k;++i){
			if( dta[i] == 'H' )
				h++;
			else
				t++;
		}
		bool flag = true ;
		for(i=n-1;i>=n-k;--i){
			if(flag && dta[i] == 'H'){
				c++;
				flag = false;
			}
			if( !flag && dta[i] == 'T' ){
				c++;
				flag = true ;
			}
		}
		if( c%2 == 0 )
			cout << h endl ;
		else
			cout << t endl ;
	}
	return 0;
}
