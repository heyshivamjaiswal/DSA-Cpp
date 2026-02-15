// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 



class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        long long sum = 0;
        double maxAvg = -1e18;
        for(int right = 0 ; right < nums.size(); right++){
          sum = sum + nums[right];
           if(right - left + 1 > k){
            sum = sum - nums[left];
            left++;
           }
           if(right - left +1 == k)
           maxAvg = max(maxAvg , (double)sum/k);
        }
        return maxAvg;
    }
};