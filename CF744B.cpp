//Author: master19
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define ff first 
#define ss second 
#define pb push_back
#define endl "\n"
#define mod 1000000007LL // fixed...
#define modd 1000000007LL // Can be changed for global use
#define all(arr) arr.begin(),arr.end()
#define x(arr) arr.begin(),arr.end()
#define ulli unsigned long long int
#define assign(x,val) memset(x,val,sizeof(x))
#define prec(val, dig) fixed << setprecision(dig) << val
#define Sort(arr) sort(arr.begin(), arr.end())
#define time() std::chrono::high_resolution_clock::now();
#define lower(str) transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) transform(str.begin(), str.end(), str.begin(), ::toupper);
#define crap ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define get(arr, num) vector < ll > arr(num); for(int i=0; i<num; i++)cin >> arr[i];
#define put(arr, num) for(int i=0; i<num; i++)cout << arr[i] << " "; cout << endl;
#define Time(start, finish) std::chrono::duration<double> elapsed = finish - start; cout << elapsed.count() << endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > new_ds; 
void debug_out() { cerr << endl; }
template <typename HeadStart, typename... TailEnd>
void debug_out(HeadStart H, TailEnd... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ll lets_do_it();
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
pair < ll, ll > dig[] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
bool isValid(ll x, ll y, ll row, ll col){
    return ((x>=0) && (y >=0)  && (x < row) && (y < col));
}
int main(int argc, const char** argv) {
    // crap;
    ll test = 1;
    cin >> test;
    auto start = std::chrono::high_resolution_clock::now();
    for(int loop=0; loop<test; loop++){
        // cout << "Case #" << (loop+1) << ": "; 
        lets_do_it();
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    cerr << "Game is on :-> " << elapsed.count() << "s"<< endl;
    return 0;
}
ll lets_do_it(){
    // Your life is ruined !! Just Code :) !!
    ll num;
    cin >> num;
    get(arr, num);
    vector < ll > temp(x(arr));
    Sort(temp);
    vector < pair < pair < ll, ll >, ll > > ans;
    for(int i=num-1; i>0; i--){
        ll value = -1;
        if(temp[i] == arr[i])
            continue;
        for(int j=i; j>=0; j--){
            if(temp[i] == arr[j]){
                ans.pb({{(ll)(j+1), (ll)(i+1)}, (ll)1});
                // cout << j+1 << " " << i+1 << " " << 1 << endl;
                value = j;
                break;
            }
        }
        for(int m=value; m<i; m++){
            arr[m] = arr[m+1];
        }
        arr[i] = temp[i]; 
    }
    cout << ans.size() << endl;
    for(auto it: ans){
        cout << it.ff.ff << " " << it.ff.ss << " " << it.ss << endl;
    }
    // cout << "-----------\n";




    return 0;
}
