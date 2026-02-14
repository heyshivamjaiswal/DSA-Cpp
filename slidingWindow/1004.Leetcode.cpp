// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int left = 0, maxLen = 0;
     int zero = 0;

    for(int right = 0 ; right < nums.size(); right++){

       
        if(nums[right] == 0){
            zero++;
        }

        if(zero > k){
          if(nums[left] == 0){
            zero--;
          }
          left++;
        }
        if(zero <= k)
        maxLen = max (maxLen , right - left + 1);
    }
    return maxLen;
    }
};