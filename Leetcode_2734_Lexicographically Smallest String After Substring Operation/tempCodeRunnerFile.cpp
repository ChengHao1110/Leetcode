class Solution {
public:
    string smallestString(string s) {
        int length = 0, maxIdx = 0, offset = 0;
        int *sumMax_dp = new int[s.length()];
        while(s[offset] == 'a' && offset < s.length()) offset++;
        if(offset == s.length()){
            s[s.length() - 1] = 'z';
            return s;
        }
        
        sumMax_dp[0] = (s[0] == 'a') ? -25 : 1;
        sumMax_dp[offset] = 1;
        int maxSum = sumMax_dp[offset];
        
        for(int i = offset + 1; i < s.length(); i++){
            int curValue = (s[i] == 'a') ? -25 : 1;
            int curSumValue = curValue + sumMax_dp[i-1];
            sumMax_dp[i] = max(curSumValue, curValue);
            if(sumMax_dp[i] > maxSum){
                maxSum = sumMax_dp[i];
                maxIdx = i;
            }
        }
        //cout << maxSum << " " << maxIdx << endl;
        int idx = maxIdx, value = 0;
        while(maxSum > 0){
            value = (s[idx] == 'a') ? -25 : 1;
            maxSum -= value;
            idx--;
        }
        for(int i = idx + 1; i <= maxIdx; i++){
            s[i] = (s[i] == 'a') ? 'z' : s[i] - 1;
        }
        return s;
    }
};