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
        cout << l << " ";
        return l;
    }

    int binarySearch(vector<int>& arr, int target, int l, int h){
        while( l <= h ){
            int mid = l + (h-l)/2;
            if( arr[mid] == target )    return mid;
            if( arr[mid] < target ) l = mid + 1;
            else    h = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0, h = n-1;
        int ind = findPivot(arr);
        if( ind == -1 ) return binarySearch(arr, target, 0, n-1);
        int left = binarySearch(arr, target, 0, ind - 1);
        if( left != -1 )    return left;
        int right = binarySearch(arr, target, ind, n-1);
        return right;
    }
};