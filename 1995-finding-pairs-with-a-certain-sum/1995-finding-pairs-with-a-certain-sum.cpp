class FindSumPairs {
private:
    vector<int> arr1, arr2;
    unordered_map<int, int> freq1, freq2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->arr1 = nums1;
        this->arr2 = nums2;
        for( auto n : nums1 )   freq1[n]++;
        for( auto n : nums2 )     freq2[n]++;
    }
    
    void add(int index, int val) {
        int n = arr2[index];
        freq2[n]--;
        if( freq2[n] == 0 ) freq2.erase(n);
        arr2[index] += val;
        freq2[ arr2[index] ]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for( auto [n, f] : freq1 ){
            int target = tot - n;
            if( freq2.find( target ) != freq2.end() )   ans += f * freq2[target];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */