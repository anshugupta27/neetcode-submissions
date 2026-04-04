class Solution {
public:
    int sum(vector<int>& arr) {
        int sum = 0;
        for (int i = 0 ; i < arr.size() ; i++) sum += arr[i];
        return sum;

    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasFlow = 0, index = 0, maxGas = INT_MIN;
        if (sum(gas) - sum(cost) < 0) return -1;
        for (int i = 0 ; i < gas.size() ; i++) {
            gasFlow += gas[i] - cost[i];
            if (gasFlow < 0) {
                gasFlow = 0;
                index = i+1;
            }
        }
        return index;
    }
};