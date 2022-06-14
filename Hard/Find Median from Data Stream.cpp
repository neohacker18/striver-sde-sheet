// Link to the problem : https://leetcode.com/problems/find-median-from-data-stream/


class MedianFinder {
public:
    int cnt;
    priority_queue<long,vector<long>,greater<long>> right; 
    priority_queue<long> left; 
    MedianFinder() {
        cnt=0;
    }
    
    void addNum(int num) {
        cnt++;
        left.push(num);
        if(left.size()-right.size()>1)
        {
            right.push(left.top());
            left.pop();
        }
        else if(!right.empty() && left.top()>right.top())
        {
            left.push(right.top());
            right.pop();
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(cnt%2==0)
            return (double)((left.top()+right.top())/2.0);
        
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */