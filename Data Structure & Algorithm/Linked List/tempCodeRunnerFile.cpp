//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        long first=-1, second=-1;
        vector<long long> v1 = v;
        reverse(v1.begin(), v1.end());
        
        auto itr = find(v.begin(), v.end(), 3);
        auto itr1 = find(v1.begin(), v1.end(), 3);
        if(itr != v.end() && itr1 != v1.end()){
            first = itr - v.begin();
            second = itr1 - v1.begin();
            second -= 2;
            ++first;
        }
        pair<long, long> p= {first, second};
        return p;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends