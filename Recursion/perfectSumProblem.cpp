#include <bits/stdc++.h>
using namespace std;

class Solution{

    private:
        long findZeroCount(int n){
            int mod = 1000000007;
            long ans = 1;
            for (int i=0; i<n; i++){
                ans = (ans*2)%mod;
            }
            
            return ans;
        }
        
        void findCount(int arr[], int index, int n, int sum1, int sum, long* count){
            
            if (index==n){
                if (sum==sum1){
                    int mod = 1000000007;
                    *count = (*count + 1)%mod;
                }
            }
            else{
                int nextSum = sum1 + arr[index];
                findCount(arr, index+1, n, nextSum, sum, count);
                findCount(arr, index+1, n, sum1, sum, count);
            }
        }

        public:
        int perfectSum(int arr[], int n, int sum)
        {
            if (sum==0){
                int zero = 0;
                for (int i=0; i<n; i++){
                    if (arr[i]==0){
                        zero++;
                    }
                }
                
                long ans = findZeroCount(zero);
                return ans;
            }
            
            long count = 0;
            int index = 0;
            int sum1 = 0;
            
            findCount(arr, index, n, sum1, sum, &count);
            
            return count;
        }

};

int main(){

    int a[100] = {3, 0, 0, 3, 0};

    Solution obj;
    
    cout << obj.perfectSum(a, 5, 6) << endl;

}