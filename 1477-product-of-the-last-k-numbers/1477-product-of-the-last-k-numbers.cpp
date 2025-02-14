class ProductOfNumbers {
public:
    vector<int> prefix;
    ProductOfNumbers() {
        // prefix.emplace_back(1);
    }
    
    void add(int num) {
        if( num == 0 ){
            prefix.clear();
        }
        else{
            if( prefix.size() == 0 )    prefix.emplace_back(num);
            else prefix.emplace_back( prefix[prefix.size()-1] * num );
        }
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        if( k == n )  return prefix[n-1];
        if( k > n ) return 0;
        return ( prefix[n-1] / prefix[n-k-1] );
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */