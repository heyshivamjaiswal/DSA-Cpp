// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array



class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int , int> freq;

        long long ans = 0;
        long long sum = 0;
        int left = 0;

        for(int right = 0 ; right < nums.size(); right++){
           
           //add new element to the window with it's freq in map
            sum += nums[right];
            freq[nums[right]]++;
            
            //check if current length is bigger then k if it is then remove element from left 
            //and also decrease the freq of that element 
            if(right - left + 1 > k){
                sum -= nums[left];
                freq[nums[left]]--;
                
                //if frequency of the element become zero remove the element
                if(freq[nums[left]] == 0)
                    freq.erase(nums[left]);

                left++;
            }
            
            if(right - left + 1 == k && freq.size() == k){
                ans = max<long long>(ans , sum);
            }
        }
        return ans;
    }
};
