#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>val,vector<int>wt,int index,int cap) {
//base case
    if(index>=val.size() || cap==0)
        return 0;
    int inc;
    if(cap>=wt[index])
//call
        inc = val[index] + solve(val,wt,index+1,cap-wt[index]);

    int exc = 0 + solve(val,wt,index+1,cap);
    return max(inc,exc);

}
//Top down
int memo(vector<int> val,vector<int> wt,int index,int cap,vector<vector<int>> dp) {
//base case
    if(index==val.size() || cap==0)
        return 0;
    if(dp[index][cap]!=-1)
        return dp[index][cap];
    int inc;
    if(cap>=wt[index])
//call
        inc = val[index] + memo(val,wt,index+1,cap-wt[index],dp);

    int exc = 0 + memo(val,wt,index+1,cap,dp);
    return dp[index][cap] = max(inc,exc);
}

// Tabular solution
int tab(vector<int>& val,vector<int>& wt,int cap,int n) {
    vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
    for(int index = n-1; index>=0; index--) {
        for(int capacity = 0; capacity<=cap; capacity++) {
            int inc = 0;
            if(capacity>=wt[index])

                inc = val[index] + dp[index+1][capacity-wt[index]];

            int exc = 0 + dp[index+1][capacity];
            dp[index][capacity] = max(inc,exc);
        }
    }
    return dp[0][cap];
}
int main()
{
    int n=3;
    
    
    vector<int>val, wt;
    val.push_back(60);
    val.push_back(100);
    val.push_back(120);

    wt.push_back(10);
    wt.push_back(20);
    wt.push_back(30);
    
    
    int capacity = 50;
    
    vector<vector<int>>dp(n+1,vector<int>(capacity+1,-1));
    cout<<"recursive sol is -> "<<solve(val,wt,0,50)<<endl;
    cout<<"Memoization ans is -> "<<memo(val,wt,0,capacity,dp)<<endl;
    cout<<"Tabular ans is -> "<<tab(val,wt,capacity,n)<<endl;
    return 0;
}
