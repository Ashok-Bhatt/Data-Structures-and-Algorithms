#include <bits/stdc++.h>
using namespace std;

int getInitialAns(string &s){
    int ans = 0, temp = 0;
    for (int i=1; i<s.size()-1; i++){
        if (s[i] == '0'){
            temp = 0;
        } else {
            temp++;
            ans = max(ans, temp);
        }
    }

    return ans;
}

int maxActiveSectionsAfterTrade(string s) {

    s = "1" + s + "1";
    int n = s.size(), i = 0, j = 0, ans = getInitialAns(s), steps = 1;

    while (j<n){
        if (s[i] == '1'){
            char flag = '1';
            while (j<n && steps<=5){
                if (s[j] != flag){
                    steps++;
                    if (flag == '1'){
                        flag--;
                    } else {
                        flag++;
                    }
                }
            }

            if (steps == 5){
                int last = min(j-1, n-2);
                int first = (i==0) ? 0 : i-1;
                ans = max(ans, last-first);

                while (i<n && s[i] == '1'){
                    i++;
                }

                while (i<n && s[i] == '0'){
                    i++;
                }

                steps = 3;
            }
        } else {
            i++;
            j++;
        }
    }

    return ans;
}

int main(){
    string s = "11011000";
    cout << maxActiveSectionsAfterTrade(s) << endl;
    return 0;
}