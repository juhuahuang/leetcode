class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       if( nums1.size() < nums2.size()) return intersect( nums2,nums1);
       vector<int> result;
       unordered_map<int,int> numCount;
       for( int n : nums1){
           if( numCount.find(n) != numCount.end()) numCount[n]++;
           else numCount[n] = 1;
       }
       for( int n:nums2){
           if( numCount.find(n) != numCount.end() && numCount[n] >0) {
               numCount[n]--;
               result.push_back(n);
            }
        }
    return result;
        
    }
};