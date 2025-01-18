//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int largest_2_power(int n){
        int ans = 0;
        while( (1 << ans) <= n )    ans++;
        return ans-1;
    }
    
    int countSetBits(int n){
        if( n == 0 )    return 0;
        if( n == 1 )    return 1;
        int nearest_2_pow = largest_2_power(n);
        int y = nearest_2_pow * ( 1 << (nearest_2_pow-1) );
        int z = n - (1 << nearest_2_pow );
        return y + z + 1 + countSetBits(z);
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  
cout << "~" << "\n";
}
	  return 0;
}

// } Driver Code Ends