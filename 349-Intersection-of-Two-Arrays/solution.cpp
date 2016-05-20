class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> numSet;
        for( int n:nums1){
            numSet.insert(n);
        }
        for( int n:nums2){
            if(numSet.find( n) != numSet.end()){
                result.push_back(n);
            }
        }
        return reuslt;
    }
};