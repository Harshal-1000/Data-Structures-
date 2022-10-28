class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        long mx = LONG_MAX/100;
        return helper(num,0,-1,-1,mx);
    }
    bool helper(string num, int inx, long long first,long long second,long mx){
        int n = num.length();
        if(inx == n){
            return false;
        }
        long long val = 0;
        if(first == -1){
            for(int i = inx ; i < n; i++){
                val = val*10 + (num[i]-'0');
                if(i > inx && num[inx] == '0' || val > mx) break;
                if(helper(num,i+1,val,second,mx)) return true;
            }
        }else if(second == -1){
            for(int i = inx; i < n; i++){
                val = val*10 + (num[i]-'0');
                if(i > inx && num[inx] == '0' || val > mx) break;
                if(helper(num,i+1,first,val,mx)) return true;
            }
        }else{
            for(int i = inx; i < n; i++){
                val = val*10 + (num[i]-'0');
                if(i > inx && num[inx] == '0' || val > mx) break;
                if(first + second == val){
                    if(i == n-1) return true;
                    return helper(num,i+1,second,val,mx);
                }
                if(first + second < val) return false;
            }
        }
        return false;
    }
};
