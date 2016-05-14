class Solution {
public:
   
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums,0,nums.size() -1, k);
    }
    int findKthLargest(vector<int>& nums, int left, int right, int k){
        
        int pivot = nums[left];
        int i = left,j=right;
        while( i <j){
            while( i<j &&nums[j] <= pivot) j--;
            nums[i] = nums[j];
            while( i<j&& nums[i] >= pivot) i++;
            nums[j] = nums[i];

        }
        nums[i] = pivot;
        //cout<<i<<' '<<j<<endl;
        if ( i == k-1) return nums[i];
        else if( i> k-1) return findKthLargest(nums,0,i-1, k);
        else return findKthLargest(nums,i+1,right, k);
        
    }
};