#include<bits/stdc++.h>
using namespace std;

vector<int> getLPS(string &pat, int m){
    vector<int> lps(m, 0);
    int length = 0, i = 1;
    while (i<m){
        if (pat[i] == pat[length]){
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0){
                length = lps[length-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> search(string &txt, string &pat){
    int n = txt.size(), m = pat.size();
    int i = 0, j = 0;
    vector<int> ans;
    vector<int> lps = getLPS(pat, m);

    while (i<n){
        if (txt[i] == pat[j]){
            i++;
            j++;

            if (j==m){
                ans.push_back(i-m);
                j = lps[j-1];
            }
        } else {
            if (j!=0){
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }

    return ans;
}

int main(){
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    vector<int> ans = search(txt, pat);
    for (auto it : ans){
        cout << it << " ";
    }

    return 0;
}