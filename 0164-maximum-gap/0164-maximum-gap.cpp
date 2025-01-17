class Solution {
public:
    int getMax(vector<int> arr, int n){
        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
    }

    vector<int> countSort(vector<int> arr, int n, int exp){
        // Output array
        vector<int> output(n);
        int i;
        vector<int> count(10, 0);

        // Store count of occurrences
        // in count[]
        for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        // Change count[i] so that count[i]
        // now contains actual position
        // of this digit in output[]
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // Copy the output array to arr[],
        // so that arr[] now contains sorted
        // numbers according to current digit
        for (i = 0; i < n; i++)
            arr[i] = output[i];
        
        return arr;
    }

    // The main function to that sorts arr[]
    // of size n using Radix Sort
    vector<int> radixsort(vector<int> arr, int n){
        // Find the maximum number to
        // know number of digits
        int m = getMax(arr, n);

        // Do counting sort for every digit.
        // Note that instead of passing digit
        // number, exp is passed. exp is 10^i
        // where i is current digit number
        for (int exp = 1; m / exp > 0; exp *= 10)
            arr = countSort(arr, n, exp);
        
        return arr;
    }

    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 )    return 0;
        if( n == 2 )    return abs( nums[1] - nums[0] );
        nums = radixsort(nums, n);
        int ans = 0;
        for( auto it : nums )   cout << it << " ";
        for( int i = 0; i < n-1; i++ )
            ans = max(ans, nums[i+1] - nums[i]);
        return ans;
    }
};