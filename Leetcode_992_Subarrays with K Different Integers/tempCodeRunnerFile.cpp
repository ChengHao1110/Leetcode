                while(map.size() != k){
                    map[nums[l]]--;
                    if(map[nums[l]] == 0) map.erase(nums[l]);
                    l++;