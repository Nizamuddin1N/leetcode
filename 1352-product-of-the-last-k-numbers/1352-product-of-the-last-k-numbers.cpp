class ProductOfNumbers {
public:
    vector<int>arr;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int s = arr.size();
        int ans=1;
        for(int i = s-1; i>=0; i--){
            if(k>0){
                ans *= arr[i];
            }
            k--;
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */