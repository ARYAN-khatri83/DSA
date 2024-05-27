
// BASIC APPROACH

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();

        for(int i = 0;i<n;i++){
            for(int j = i+1 ; j<n;j++){
                if(prices[j]>prices[i]){
                    maxProfit = max(prices[j]-prices[i],maxProfit);
                }
            }
            
        }
        return maxProfit;
    }
};

// OPTIMAL


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int mini = prices[0];
        int n = prices.size();
        for(int i =1;i<n;i++){
            int cost = prices[i]-mini;
            maxProfit=max(maxProfit,cost);
            mini = min(mini,prices[i]);
        }
        return maxProfit;
    }
};
