/**
* Solution to LeetCode's Product of Array Except Self
* https://leetcode.com/problems/product-of-array-except-self/
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int size = static_cast<int>( nums.size() );
        for (int i = 0; i < size; ++i) output.push_back(1);
        
        output[0] = productExceptSelf(nums, output, 1, size - 1);
        
        return output;
    }
    
    int productExceptSelf(vector<int>& nums, vector<int>& output, int currentPos, int endingPos) {
        if ( currentPos == endingPos  ) {
            // If we reach the last element, change the last and return the last number on the list.
            output[ currentPos ] = nums[ currentPos - 1 ] * output[ currentPos - 1 ];
            return nums[ currentPos ];
        } else {
            // If we aren't on the last element...
            
            // Current will be previous number * previous product.
            output[ currentPos ] = nums[ currentPos - 1 ] * output[ currentPos - 1 ];
            
            // Recursiveness level: 999
            int value = productExceptSelf(nums, output, currentPos + 1, endingPos);

            // Backtracking.
            output[ currentPos ] *= value;
            return nums[ currentPos ] * value;
        }
    }
};
