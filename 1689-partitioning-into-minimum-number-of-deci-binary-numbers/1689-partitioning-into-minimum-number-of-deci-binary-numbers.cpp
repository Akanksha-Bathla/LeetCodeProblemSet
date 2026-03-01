#include<bits/stdc++.h>
class Solution {
public:
    int minPartitions(string n) {
        int sz = n.size();
        int minDigits = 0;
        for (int i=0; i<sz; i++){
            minDigits = max(minDigits, (int)(n[i] - '0'));
        }
        return minDigits;
    }
};