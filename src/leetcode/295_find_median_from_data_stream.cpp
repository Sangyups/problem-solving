#include <deque>

class MedianFinder {
   public:
    priority_queue<int, vector<int>, greater<int>> big;
    priority_queue<int> small;

    MedianFinder() {
    }

    void addNum(int num) {
        if (small.size() < big.size()) {
            if (big.size() == 0) {
                small.push(num);
            } else {
                if (big.top() < num) {
                    small.push(big.top());
                    big.pop();
                    big.push(num);
                } else {
                    small.push(num);
                }
            }
        } else {
            if (small.size() == 0) {
                big.push(num);
            } else {
                if (small.top() > num) {
                    big.push(small.top());
                    small.pop();
                    small.push(num);
                } else {
                    big.push(num);
                }
            }
        }
    }

    double findMedian() {
        if (small.size() == big.size()) {
            return (small.top() + big.top()) / 2.0;
        } else if (small.size() > big.size()) {
            return small.top();
        } else {
            return big.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
