vector<int> tot_num(vector<int>& digits,vector<int>arr){
    int k= digits.size();
    int O=0,T=0,H=0;
    int num=0;
    for (int O=0;O<k;O++){
        for (int T=0;T<k;T++){
            for (int H=0;H<k;H++){
                if(H != T && T != O && H!=O && digits[H] != 0){
                num=digits[H]*100 +digits[T]*10+digits[O]*1;
                arr.push_back(num);
                }
            }
        
        }
    }
    return arr;

}
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>arr;
        arr=tot_num(digits,arr);
        vector<int>ans;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                ans.push_back(arr[i]);
            }

        }
        // ab mujhe bs ans me se wo number hatane h ji digitrepeat ho kar aai hai..
        
        sort(ans.begin(),ans.end());

        vector<int> res;

        for (int i = 0; i < ans.size(); i++) {
           if (i == 0 || ans[i] != ans[i - 1]) {
                res.push_back(ans[i]);
            }
        }

    return res.size();
        
    }
};
