class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0.0) return 0.0;
        if(x == 1.0) return 1.0;
        if(x == -1.0){
            if(abs(n) % 2 == 0) return 1.0;
            else return -1.0;
        }
        if(n == 0) return 1.0;
        double ans = x;
        for(int i = 0; i < abs(n) - 1; i++){
            ans *= x;
        }
        if(n > 0) return ans;
        else return 1.0 / ans;  
    }
};