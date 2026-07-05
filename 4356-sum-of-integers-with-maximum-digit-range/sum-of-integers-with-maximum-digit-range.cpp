class Solution {
public:
    int maxDigitRange(vector<int>& nums) {

        int globalMax = -1;
        int ans = 0;

        for(int x : nums){

            int temp = x;
            int mx = 0, mn = 9;

            while(temp){
                int d = temp % 10;
                mx = max(mx, d);
                mn = min(mn, d);
                temp /= 10;
            }

            int range = mx - mn;

            if(range > globalMax){
                globalMax = range;
                ans = x;
            }
            else if(range == globalMax){
                ans += x;
            }
        }

        return ans;
    }
};