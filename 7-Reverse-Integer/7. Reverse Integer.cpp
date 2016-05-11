class Solution {
public:
    int reverse(int x) {
        int flag , result = 0;
        if( x> 0) flag = 1;
        else {
            flag = -1;
            x = -x;
        }
        while( x>0){
            if( result > INT_MAX/10 ||( result == INT_MAX/10 && x%10 > INT_MAX%10)) return 0;
            result = 10*result + x%10;
            x = x/10;
        }
        return result * flag;
    }
};