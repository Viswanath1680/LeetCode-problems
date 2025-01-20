//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumOfDigits(int n) {
        if( n < 10 )    return n;
        return ( sumOfDigits(n/10) + n%10 );
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.sumOfDigits(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends