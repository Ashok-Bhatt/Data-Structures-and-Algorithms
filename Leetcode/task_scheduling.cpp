#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> occurance(26,0);
        vector<int> last(26,-1);
        int count = tasks.size(), ans=0;

        for (int task : tasks){
            occurance[task-'A']++;
        }

        while (count){

            ans++;
            int candidate = -1;

            for (int i=0; i<26; i++){
                if (occurance[i]){
                    if (candidate == -1){
                        candidate = i;
                    } else {
                        if (last[i] == -1){
                            if ( last[candidate] != -1 || ( last[candidate] == -1 && occurance[i] > occurance[candidate] && ans-last[i] > n) ){
                                candidate = i;
                            }
                        } else if ( (ans - last[i]) < (ans - last[candidate]) ){
                            candidate = i;
                        } else if ( (ans - last[i]) == (ans - last[candidate]) ){
                            if (occurance[i] > occurance[candidate]){
                                candidate = i;
                            }
                        }
                    }
                }
            }

            if (last[candidate]!=-1 && ans-last[candidate] <= n){
                ans = ans + n-(ans-last[candidate]) + 1;
            }

            last[candidate] = ans;
            occurance[candidate]--;
            count--;
        }

        return ans;
    }
};