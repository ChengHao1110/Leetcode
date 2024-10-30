    int maximalRectangle(vector<vector<char>>& matrix) {
        int rowCount = matrix.size(), colCount = matrix[0].size(), ans = 0, h = 0, w = 0;
        vector<int> height(colCount + 1, 0); //last 0
        for(int i = 0; i < rowCount; i++){
            //record current height (row count 1)
            for(int j = 0; j < colCount; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            for(int n : height) cout << n << " "; cout << endl;

            stack<int> st_idx; // store index
            //monotonic stack -> find width (col count 1)
            for(int j = 0; j < colCount + 1; j++){
                while(!st_idx.empty() && height[j] < height[st_idx.top()]){
                    h = height[st_idx.top()];
                    st_idx.pop();
                    if(st_idx.empty()) w = 1;
                    else w = j - st_idx.top() - 1;
                    ans = max(ans , h * w);
                }
                st_idx.push(j);
            }
        }

        return ans;
    }