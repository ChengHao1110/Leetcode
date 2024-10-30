        //update dp
        for(int i = 1; i < pLen; i++){
            if(p[i] == '*'){
                for(int j = ((cmpIdx - 1) < 0) ? 0 : cmpIdx - 1; j < sLen; j++) dp[i][j] = true;
            }
            else if(p[i] == '?'){
                for(int j = cmpIdx; j < sLen; j++){
                    if(j - 1 >= 0){
                        if(dp[i - 1][j - 1]) dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = true;
                    } 
                }
                cmpIdx++;
            }
            else{
                for(int j = cmpIdx; j < sLen; j++){
                    if(j - 1 >= 0){
                        if(dp[i - 1][j - 1] && p[i] == s[j]) dp[i][j] = true;
                    }
                    else{
                        if(p[i] == s[j]) dp[i][j] = true;
                    }                    
                }
                cmpIdx++;
            }    
        }
        PrintDPTable