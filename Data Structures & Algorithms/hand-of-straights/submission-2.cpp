class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize) return false;
        map<int,int> freqCountMp;
        for ( int i = 0 ; i < hand.size() ; i++) freqCountMp[hand[i]]++;
        int totalGroups = hand.size() / groupSize;
        while (freqCountMp.size()) {
            int prev = -1, countElements = 0;
            if (totalGroups < 0) return false;
            int startKey = freqCountMp.begin() -> first;
            for (int i = 0 ; i < groupSize ; i++) {
                if (freqCountMp.find(startKey+i) == freqCountMp.end()) return false;
                freqCountMp[startKey+i]--;
                if (freqCountMp[startKey+i] == 0) freqCountMp.erase(startKey+i);
            }
            totalGroups--;
        }
        if (totalGroups == 0) return true;
        return false;
    }
};