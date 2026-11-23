class ProductOfNumbers {
public:
    // vector<int>arr;
    vector<int>pref;
    ProductOfNumbers() {
        pref.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            pref.clear();
            pref.push_back(1);
        }
        else{
            pref.push_back(pref.back()*num);
        }
    }
    
    int getProduct(int k) {
        int s = pref.size();
        if(k>=s) return 0;
        return pref.back()/pref[s-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */