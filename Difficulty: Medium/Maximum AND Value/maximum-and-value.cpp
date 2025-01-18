//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution{
    public:
    int checkBit( int pattern, int arr[], int n ){
        int count = 0;
        for( int i = 0; i < n; i++ ){
            if( (arr[i] & pattern) == pattern ) count++;
        }
        return count;
    }
    
    int maxAND (int arr[], int n){
        int answer = 0;
        for( int bit = 32; bit >= 0; bit-- ){
            int power = pow(2, bit);
            int pattern = answer | power;
            int count = checkBit( pattern, arr, n);
            
            if( count >= 2 )    answer |= (1 << bit);
        }
        return answer;
    }
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends