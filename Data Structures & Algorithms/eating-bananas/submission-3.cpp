class Solution {
public:
    bool isValid (int k, vector<int>& piles, int h) {
        int hoursRequired = 0;
        for (int i = 0 ; i < piles.size() ; i++) {
            int rem = piles[i]%k;
            hoursRequired += (piles[i]/k);
            if (rem) hoursRequired += 1;
        }
        if (hoursRequired > h) return false;
        return true;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = INT_MAX, potentialAns = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (isValid (mid, piles, h)) {
                potentialAns = mid;
                high = mid -1;
            }
            else low = mid + 1;
        }
        return potentialAns;
    }
};