class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = (int)floor(sqrt(c)); i > 0; i--){
            int remain = c - i * i;
            double b;
            double frac = modf(sqrt(remain), &b);
            if(frac == 0) return true;
        }
        return false;
    }
};