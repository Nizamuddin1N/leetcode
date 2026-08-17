class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
    //     int ans = letters[0];
    //     int low = 0;
    //     int high = letters.size()-1;
    //     while(low<=high){
    //         int mid = low+(high-low)/2;
    //         if(letters[mid]>target){
    //             ans = letters[mid];
    //             high = mid-1;
    //         }
    //         else{
    //             low = mid+1;
    //         }
    //     }
    //     return ans;
        auto it =  upper_bound(letters.begin(), letters.end(), target);
        if(it == letters.end()){
            return letters[0];
        }
        return *it;
    }
    
};