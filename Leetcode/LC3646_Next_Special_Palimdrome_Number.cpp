#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(long long n, int count){
        vector<int> odds = {0, 1, 3, 5, 7, 9};
        long long ans = LLONG_MAX;

        for (auto odd : odds){
            if (odd%2 != count%2) continue;

            vector<int> digits = {2,4,6,8};
            if (odd!=0) digits.push_back(odd);

            for (int i=0; i<(1<<digits.size()); i++){
                vector<int> used;
                for (int j=0; j<digits.size(); j++){
                    if (i&(1<<j)){
                        for (int k=0; k<digits[j]/2; k++){
                            used.push_back(digits[j]);
                        }
                    }
                }

                if (used.size()*2 + (odd ? 1 : 0) != count) continue;

                for (int j=0; j<used.size(); j++){
                    cout << used[j] << " ";
                } cout << " " << odd << endl;
                
                if (used.size() > 0){
                    sort(used.begin(), used.end());
                    vector<int> sortedUsed = used;

                    do{
                        long long num = 0;
                        for (int k=0; k<used.size(); k++){
                            num = num*10 + used[k];
                        }
                        
                        if (odd) num = num*10 + odd;
                        
                        for (int k=used.size()-1; k>=0; k--){
                            num = num*10 + used[k];
                        }

                        if (num > n) {
                            ans = min(ans, num);
                            break;
                        }

                        next_permutation(used.begin(), used.end());
                    } while (used != sortedUsed);
                } else {
                    int num = 0;
                    for (int k=1; k<=odd; k=k+2){
                        num = num*10 + odd;
                    }
                    if (num > n) ans = min(ans, (long long)num);
                }
            }
        }

        return ans;
    }

    long long specialPalindrome(long long n) {
        int digits_count = to_string(n).size();
        return min(solve(n, digits_count), solve(n, digits_count+1));
    }
};

int main(){
    Solution* s1 = new Solution;
    long long ans = s1->specialPalindrome(33);
    cout << "ans: " << ans << endl;
}