class Solution {
    bool isprime(int x){
        if(x<2){ return false;}
        for(int i=2;i<=sqrt(x);i++){
            if(x%i==0){
                return false;
            }
        }
    return true;
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int>mp;
        // no,frequency
        for(int i=0;i<nums.size();i++){
           mp[nums[i]]++;
        }
   for(int i=0;i<nums.size();i++){
    if(isprime(mp[nums[i]])){
        return true;
    }
   }
return false;

    }
};