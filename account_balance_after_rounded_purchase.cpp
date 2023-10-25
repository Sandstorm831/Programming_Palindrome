// Question Link - https://leetcode.com/contest/biweekly-contest-110/problems/account-balance-after-rounded-purchase/
// Solution 

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        if(purchaseAmount%10 <= 4) return 100 - (purchaseAmount - purchaseAmount%10);
        else return 100 - (purchaseAmount + (10-purchaseAmount%10));
    }
};