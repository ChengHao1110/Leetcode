class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        //horizontal: y-axis
        int line = 0;
        sort(rectangles.begin(), rectangles.end(), cmp_hor);
        /*
        sort(rectangles.begin(), rectangles.end(), [](auto &a, auto &b) {
            return (a[0] < b[0] || (a[0] == b[0] && a[2] < b[2]));
        });
        */
        int cur_y = rectangles[0][3];
        for(int i = 1; i < rectangles.size(); i++){
            if(rectangles[i][1] >= cur_y){
                line++;
            }
            cur_y = max(cur_y, rectangles[i][3]);
            if(line == 2) return true;
        }
        
        //vertical: x-axis
        line = 0;
        sort(rectangles.begin(), rectangles.end(), cmp_ver);
        /*
        sort(rectangles.begin(), rectangles.end(), [](auto &a, auto &b) {
            return (a[1] < b[1] || (a[1] == b[1] && a[3] < b[3]));
        });
        */
        int cur_x = rectangles[0][2];
        for(int i = 1; i < rectangles.size(); i++){
            if(rectangles[i][0] >= cur_x){
                line++;
            }
            cur_x = max(cur_x, rectangles[i][2]);
            if(line == 2) return true;
        }

        return false;
    }

    static bool cmp_hor(const vector<int> &r1, const vector<int> &r2){
        if(r1[1] < r2[1]) return true;
        else return false;
        /*
        else if(r1[1] > r2[1]) return false;
        else{
            if(r1[3] < r2[3]) return true;
            else if(r1[3] > r2[3]) return false;
            else return true;
        }
        */
    }

    static bool cmp_ver(vector<int> &r1, const vector<int> &r2){
        if(r1[0] < r2[0]) return true;
        else return false;
        /*
        else if(r1[0] > r2[0]) return false;
        else{
            if(r1[2] < r2[2]) return true;
            else if(r1[2] > r2[2]) return false;
        }
        return true;
        */
    }
};
