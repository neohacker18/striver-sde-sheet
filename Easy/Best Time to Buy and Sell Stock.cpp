Link to the problem : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit= 0,curr = 0,n=prices.size(); 
        int minima=INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(prices[i] < minima)
            { 
                minima = prices[i]; 
            }
            curr= prices[i] - minima;
            if(profit < curr){ 
                profit=curr;
            }
        }
        return profit;
    }
};