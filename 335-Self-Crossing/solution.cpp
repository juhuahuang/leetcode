class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int i ;
        for( i=2;i<x.size()&&x[i] > x[i-2];i++);
        if( i > 2 && x[i] >= x[i-2] - i==3?0:x[i-4] ) x[i-1] -=x[i-3];
        for( i +=1;i<x.size() && x[i] < x[i-2];i++);
        return i<x.size();
    }
};