#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL

long long hashValue(string &x, int n, int RADIX)
{
    long long ans = 0, factor = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans = (ans + ((x[i] - 'a') * factor) % MOD) % MOD;
        factor = (factor * RADIX) % MOD;
    }
    return ans % MOD;
}

bool match(string &occurrence, string &pattern)
{

    int n = occurrence.size(), m = pattern.size();
    if (m > n)
        return false;

    int RADIX = 26;
    long long maxValue = 1;
    long long pattHash = hashValue(pattern, m, RADIX);
    long long occHash = 0;

    for (int i = 0; i < m; i++){
        maxValue = (maxValue * RADIX) % MOD;
    }

    for (int i=0; i<=n-m; i++){
        if (i==0){
            occHash = hashValue(occurrence, m, RADIX);
        } else {
            occHash = ((occHash*RADIX) % MOD - ((occurrence[i-1]-'a')*maxValue) % MOD + (occurrence[i+m-1]-'a') + MOD) % MOD;
        }

        if (occHash == pattHash){
            bool matched = true;
            for (int j=0; j<m; j++){
                if (occurrence[i+j] != pattern[j]){
                    matched = false;
                    break;
                }
            }
            if (matched) return true;
        }
    }

    return false;
}

int main()
{
    string pattern = "reek", occurrence = "geeksforgeeks";
    bool result = match(occurrence, pattern);
    if (result)
        cout << "Match Found" << endl;
    else
        cout << "Match Not Found" << endl;
    return 0;
}