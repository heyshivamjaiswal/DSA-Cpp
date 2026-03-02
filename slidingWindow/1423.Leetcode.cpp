// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

// Your score is the sum of the points of the cards you have taken.

// Given the integer array cardPoints and the integer k, return the maximum score you can obtain


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //[3,5,4,4,5,2,1,9]
        int leftSum = 0, rightSum = 0 , maxSum = 0;
        for(int i = 0; i< k; i++){
            leftSum = leftSum + cardPoints[i];
        }
        maxSum = leftSum;
        int rightIndex = cardPoints.size()-1;
        for(int j=k-1 ; j >=0; j--){
            leftSum = leftSum - cardPoints[j];
            rightSum = rightSum + cardPoints[rightIndex];
            rightIndex = rightIndex-1;
            maxSum = max(maxSum , leftSum + rightSum);
        }
        return maxSum;
    }
};
