class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<int> pos, neg, pos1, neg1;
        int zero = 0, zero1 = 0;
        for (int &x: nums1) {
            if (x == 0) {
                zero++;
            } else if (x > 0) {
                pos.push_back(x);
            } else {
                neg.push_back(x);
            }
        }
        for (int &x: nums2) {
            if (x == 0) {
                zero1++;
            } else if (x > 0) {
                pos1.push_back(x);
            } else {
                neg1.push_back(x);
            }
        }
        
        int psz = pos.size(), nsz = neg.size(), psz1 = pos1.size(), nsz1 = neg1.size();
        long long totalZero = 1LL * (psz + nsz) * zero1 + 1LL * (psz1 + nsz1) * zero + 1LL * zero * zero1;

        auto getPosPos = [&](long long p) -> long long {
            if (p <= 0) return 0;
            int i = 0, j = psz1 - 1;
            long long cnt = 0;

            while (i < psz && j >= 0) {
                while (j >= 0 && 1LL * pos[i] * pos1[j] > p) {
                    j--;
                }
                cnt += j + 1;
                i++;
            }
            return cnt;
        };

        auto getPosNeg = [&](long long p) -> long long {
            if (p >= 0) return 1LL * psz * nsz1;
            long long cnt = 0;
            int i = 0, j = 0;
            while (i < nsz1 && j < psz) {
                while (j < psz && 1LL * neg1[i] * pos[j] > p) {
                    j++;
                }
                cnt += psz - j;
                i++;
            }
            return cnt;
        };

        auto getNegPos = [&](long long p) -> long long {
            if (p >= 0) return 1LL * nsz * psz1;
            long long cnt = 0;
            int i = 0, j = 0;
            while (i < nsz && j < psz1) {
                while (j < psz1 && 1LL * neg[i] * pos1[j] > p) {
                    j++;
                }
                cnt += psz1 - j;
                i++;
            }
            return cnt;
        };

        auto getNegNeg = [&](long long p) -> long long {
            if (p <= 0) return 0;
            int i = nsz - 1, j = 0;
            long long cnt = 0;
            while (i >= 0 && j < nsz1) {
                while (j < nsz1 && 1LL * neg[i] * neg1[j] > p) {
                    j++;
                }
                cnt += nsz1 - j;
                i--;
            }
            return cnt;
        };

        auto getCount = [&](long long p) -> long long {
            long long cnt = getPosPos(p) + getPosNeg(p) + getNegPos(p) + getNegNeg(p);
            if (p >= 0) {
                cnt += totalZero;
            }
            return cnt;
        };
        
        long long lo = -1e11, hi = 1e10;
        // smallest product whose count is >= k, where count is number of products in num1 * nums2 that are less than equal to given product
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2; // hi is always valid / true. Extend the valid region to the left
            if (getCount(mid) >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
