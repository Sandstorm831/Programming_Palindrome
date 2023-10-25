// Question Link - https://leetcode.com/problems/find-median-from-data-stream/description/?envType=study-plan-v2&envId=top-interview-150
// solution 


class MedianFinder {
public:
    priority_queue<int> bak;
    priority_queue<int, vector<int>, greater<int>> fak;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(bak.size() == fak.size())
        {
            if(bak.empty()) bak.push(num);
            else if(num > fak.top()){int x = fak.top();fak.pop();fak.push(num);bak.push(x);}
            else bak.push(num);
        }
        else if(bak.size()>fak.size())
        {
            if(num<bak.top()){int x = bak.top();bak.pop();bak.push(num);fak.push(x);}
            else fak.push(num);
        }
    }
    
    double findMedian() {
        if(fak.size() == bak.size()) return ((double(fak.top())+double(bak.top()))/double(2));
        else return bak.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */