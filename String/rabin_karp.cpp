#include <bits/stdc++.h>
#define MOD int(1e9+7)
using namespace std;

long long findHash(string str, int n, int base){

    long long temp = str[0]-'a', multiplier = 1;
    for (int i=1; i<=n; i++){
        temp = (temp*base*multiplier + str[i]-'a')%MOD;
        multiplier = multiplier*base;
    }
    return temp;
}

bool isMatch(string x, string y, int index, int n){
    for (int i=0; i<n; i++){
        if (x[i+index] != y[i]){
            return false;
        }
    }
    return true;
}

int solve(string haystack, string needle){
    int m = haystack.size(), n = needle.size();
    if (n > m) return -1;

    int base = 26;
    long long needleHash = findHash(needle, n-1, base);
    long long hayStackHash = findHash(haystack, n-1, base);
    long long power = 1;

    for (int i=1; i<n; i++){
        power = (power*base) % MOD;
    }

    if (needleHash == hayStackHash){
        if (isMatch(haystack, needle, n, 0)){
            return 0;
        }
    }

    for (int i=n; i<m; i++){
        hayStackHash = ((hayStackHash - (haystack[i-n]-'a')*power + MOD)*base + (haystack[i]-'a')) % MOD;
        if (needleHash == hayStackHash){
            if (isMatch(haystack, needle, n, i-n+1)){
                return i-n+1;
            }
        }
    }

    return -1;
}

int main(){
    string haystack="abcdfgyukhhjgfchmjytfcghjkhgfhjklkjhgklhgfjhklo;uyguigfhjjhbgiyftvhjboighgjvkyulbhvfgykugiunytdtjyjuklhjyuioytukhikljhfygefgh", needle="gyukhhjgfchmjytfcghjkhgfhjklkjhgklhgfjhklo;uyguigfhjjhbgiyftvhjboighgjvkyulbhvfgykugiunytdtjyjuklhjyuioytukhikl";
    cout << solve(haystack, needle) << endl;
}