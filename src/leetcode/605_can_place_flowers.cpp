class Solution {
   public:
    int N;
    bool checkFlower(vector<int>& flowerbed, int pos) {
        if (pos > 0 && flowerbed[pos - 1]) {
            return false;
        }

        if (pos < N - 1 && flowerbed[pos + 1]) {
            return false;
        }

        return true;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        N = flowerbed.size();

        for (int i = 0; i < N; ++i) {
            if (flowerbed[i] == 1) continue;
            if (checkFlower(flowerbed, i)) {
                --n;
                flowerbed[i] = 1;
            }

            if (n <= 0) break;
        }

        return n <= 0;
    }
};
