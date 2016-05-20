class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int> &nums) {
        sum.resize( nums.size()+1);
        sum[0] = 0;
        for( int i = 0;i< nums.size();i++){
            sum[i+1] = nums[i] + sum[i];
        }
    }

    void update(int i, int val) {
        int diff = val - sum[i+1] + sum[i];
        for( i = i+1 ;i<sum.size();i++){
            sum[i] = sum[i] + diff;
        }
    }

    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);