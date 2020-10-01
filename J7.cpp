//Author: master19
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first 
#define ss second 
#define pb push_back
#define endl "\n"
#define mod 1000000007LL
#define vis(vct) vector < string > vct
#define vip(vct) vector < pair < ll, ll > > vct
string to_string(ll num){
    string str = "";
    while(num != 0){
        str += (char)(num%10 + '0');
        num = num/10;
    }
    reverse(str.begin(), str.end());
    return str;
}
// pi xy[] = {{-1, 0}, {1, 0} , {0, -1}, {0, 1}};
// pi dig[] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
// bool isValid(ll x, ll y, ll row, ll col){
//     return ((x>=0) && (y >=0)  && (x < row) && (y < col));
// }
int main(){
    ll test = 1;
    cin >> test;
    for(int loop=0; loop<test; loop++){
        double p, s;
        cin >> p >>s;
        double l = (p-sqrt(p*p - 24*s))/12;
		double v = (l*s)/2 - (l*l*p)/4 + l*l*l;
		cout << prec(v, 2) << endl;
    }
}

