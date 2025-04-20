#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        vector<int> temp(1000000001, 0);
        int n = hand.size(), i=0, nextStep;

        for (int i=0; i<n; i++){
            temp[hand[i]]++;
        }

        while (n){

            if (temp[i] != 0){

                nextStep = 0;

                for (int j=i; j<i+groupSize; j++){
                    if (j>int(1e9+7) || temp[j]==0){
                        return false;
                    } else {
                        temp[j]--;
                        if (temp[j] == 0){
                            n--;
                            if (i==j || temp[j-1]==0){
                                nextStep++;
                            }
                        }
                    }
                }

                i = i + nextStep;
            } else {
                i++;
            }
        }

        return true;
    }
};