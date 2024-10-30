class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 1) return s;

        int maxLength = INT_MIN;
        int idx = 0;
        for(int i = 0; i < s.length(); i++){
            int length = 0;
            // odd
            while(((i - length) >= 0 && (i + length) < s.length())){
                if((s[i - length] == s[i + length])) length++;
                else break;
            }
            length--;
            if(2 * length + 1 > maxLength){
                maxLength = 2 * length + 1;
                idx = i;
            }

            // even same with right
            if((i + 1) < s.length()){
                length = 0;
                while(((i - length) >= 0 && (i + 1 + length) < s.length())){
                    if((s[i - length] == s[i + 1 + length])) length++;
                    break;
                }
                length--;
                if(2 * length + 2 > maxLength){
                    maxLength = 2 * length + 2;
                    idx = i;
                }
            }

            // even same with left
            if((i - 1) >= 0){
                length = 0;
                while( ((i - 1 - length) >= 0 && (i + length) < s.length())){
                    if((s[i - 1 - length] == s[i + length])) length++;
                    else break;
                }
                length--;
                if(2 * length + 2 > maxLength){
                    maxLength = 2 * length + 2;
                    idx = i;
                }
            }
        }

        //cout << idx << " " << maxLength << endl;
        string ans = "";
        if(maxLength % 2 != 0){
            // odd case
            for(int start = idx - maxLength / 2; start <= idx + maxLength / 2; start++) ans += s[start];
            return ans;
        }
        else{
            // same with right
            if(idx + 1 < s.length()){
                if(s[idx] == s[idx + 1]) for(int start = idx + 1 - maxLength / 2; start <= idx + maxLength / 2; start++) ans += s[start];
                return ans;
            }
            // same with left
            if(idx - 1 >= 0){
                if(s[idx] == s[idx - 1]) for(int start = idx - maxLength / 2; start <= idx - 1 + maxLength / 2; start++) ans += s[start];
                return ans;
            }
        }
    }
};