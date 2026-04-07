class Solution {
public:
    vector<int> getBestPriceUtil (vector<vector<vector<int>>> &adj, int src, int dst, int k, int n) {
        queue<vector<int>> q;
        q.push({src, 0, 0}); // location , price, stops
        vector<int> price(n+1, INT_MAX);
        price[src] = 0;
        while (q.size()) {
            auto front = q.front();
            q.pop();
            int parentNode = front[0];
            int parentPrice = front[1];
            int parentStops = front[2];
            if (parentStops > k) continue;
            
            for (auto it : adj[parentNode]) {
                int childNode = it[0];
                int childPrice = it[1];
                if (childPrice + parentPrice < price[childNode]) {
                    price[childNode] = childPrice + parentPrice;
                    q.push({childNode, price[childNode], parentStops+1});
                }
            }
        }
        return price;

    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n+1);
        for (int i = 0 ; i < flights.size() ; i++) {
            auto ele = flights[i];
            int start = ele[0];
            int end = ele[1];
            int price = ele[2];
            adj[start].push_back({end, price});
        }
        vector<int> price = getBestPriceUtil (adj, src, dst, k, n);
        for (int i = 0 ; i < price.size() ; i++) cout << price[i] << ", "; 
        return price[dst] == INT_MAX ? -1 : price[dst];
    }
};