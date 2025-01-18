//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int recursive( int n, int pow ){
        if( pow == 0 )  return 1;
        if( pow == 1 )  return n;
        else    return n * recursive( n, pow-1 );
    }
  
    int reverseExponentiation(int n) {
        int m = n == 10 ? 1 : n;
        int answer = recursive( n, m );
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T; // test cases

    while (T--) {
        int n;
        cin >> n; // input N

        Solution ob;
        // power of the number to its reverse
        int ans = ob.reverseExponentiation(n);
        cout << ans << endl;
    }

    return 0;
}

// } Driver Code Ends