    string removeKdigits(string num, int k) {
        //memory limit exceeded
        if(num.length() == k) return "0";
        //increasing monotonic stack
        vector<char> st;
        for(int i = 0; i < num.length(); i++){
            while(!st.empty() && st.back() > num[i] && k > 0){
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        // if k still larger than 0 原本就遞增
        while(k > 0){
            st.pop_back();
            k--;
        }
        // remove first 0
        int i = 0; 
        while (st[i] == '0') i++; 
        st.erase(st.begin(), st.begin() + i);

        // vector to string
        string ans = "";
        for(char c : st) ans += c;
        
        // check empty 
        if(ans == "") return "0";
        return ans;
    }