class Solution {
    //recursive version will run out of time, but can make recursive version dynamic programming
public:
    int numSquares(int n) {
        vector<int> dp_square(n+1,INT_MAX);
        vector<int> nums;
        dp_square[1] = 1;
        int i = 1;
        while( i*i <= n){
            nums.push_back(i*i);
            dp_square[i*i ] = 1;
            i++;
        }
        for( i = 1;i<n;i++){
          for(int j = 0 ;j<nums.size();j++){
              if(dp_square[i]!=INT_MAX && i+nums[j] <= n){
                  dp_square[i+nums[j]] = min(dp_square[i+nums[j]], dp_square[i] + 1);
              }
          }
        }
        return dp_square[n];
        
    }
};