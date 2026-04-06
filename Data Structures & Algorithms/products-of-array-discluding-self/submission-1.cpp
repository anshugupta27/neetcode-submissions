class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftPrefixProduct, rightPrefixProduct(nums.size()+1), finalAns;
        int product = 1;
        for (int i = 0 ; i < nums.size() ; i++) {
            leftPrefixProduct.push_back (product);
            product = product * nums[i];
        }
        product = 1;
        for (int i = nums.size()-1 ; i >= 0 ; i--) {
            rightPrefixProduct[i] = product;
            product = product * nums[i];
        }
        for (int i = 0 ; i < nums.size() ; i++) {
            finalAns.push_back (leftPrefixProduct[i]*rightPrefixProduct[i]);
        }
        return finalAns;


    }
};