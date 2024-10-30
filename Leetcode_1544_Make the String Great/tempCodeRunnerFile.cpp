class Solution {
public:
    string makeGood(string s) {
        if(s.length() == 0) return s;
        stack<char> st;
        st.push(s[0]);
        char lastChar = s[0];
        for(int i = 1; i < s.length(); i++){
            if(abs(s[i] - lastChar) == 32){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            if(!st.empty()) lastChar = st.top();
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};