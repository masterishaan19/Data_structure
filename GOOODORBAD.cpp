#include<bits/stdc++.h>
using namespace std;
#define lli long long int
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		string str;
		cin>>n>>k>>str;
		
		int count1=0,count2=0;
		for(int i=0;i<n;i++)
		{
			if(isupper(str[i]))
				count2++;
			else
				count1++;
		}
		
		int max = count1 > count2 ? count1 : count2;
		int min = count1 < count2 ? count1 : count2;
		
		if(k >= max)
			cout<<"both\n";
		else if(k >= min)
		{
			if(min == count1)
				cout<<"brother\n";
			else
				cout<<"chef\n";
		}
		else 
			cout<<"none\n";
	}
}
