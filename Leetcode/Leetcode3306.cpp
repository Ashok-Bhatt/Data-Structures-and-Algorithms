#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isVowel(char x){
            return (x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
        }
    
        bool isVowelMissing(unordered_map<char, int> mapping){
            if (mapping.size() < 5) return true;
            for (auto i:mapping){
                if (i.second == 0) return true;
            }
            return false;
        }
    
        long long countOfSubstrings(string word, int k) {
            long long ans = 0, l = 0, r = 0, n = word.size(), consonants=0;
            unordered_map<char, int> mapping;
    
            while (r < n){
    
                // creating required window
                while (r<n && consonants<=k){
                    if (isVowel(word[r])) mapping[word[r]]++;
                    else consonants++;
    
                    if (!isVowelMissing(mapping) && consonants==k){
                        ans++;
                    }
                    r++;
                }
    
                // leftshifing the window
                if (isVowel(word[l])) mapping[word[l]]--;
                else consonants--;
                l++;
            }
    
            return ans;
        }
    };