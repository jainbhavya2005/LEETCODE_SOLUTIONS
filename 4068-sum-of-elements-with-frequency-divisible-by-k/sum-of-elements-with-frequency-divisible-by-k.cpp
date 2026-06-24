class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
     unordered_map<int,int>mp;
     // no,frequency
     for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
     }
     int sum=0;
     for (int x=0;x<nums.size();x++){
        if(mp[nums[x]]%k==0){ sum+=nums[x];}
     }
return sum;
    }
};