class Solution {
public:
    int findPivot(vector<int>& arr){
        int n = arr.size();
        int l = 0, h = n-1;
        if( arr[l] < arr[h] )   return -1;
        while( l < h ){
            int mid = l + (h-l)/2;
            if( arr[mid] > arr[h] ) l = mid + 1;
            else    h = mid;
        }
        return l;
    }

    int findMin(vector<int>& arr) {
        int n = arr.size();
        int pivot = findPivot(arr);
        if( pivot == -1 )   return arr[0];
        return arr[pivot];
    }
};