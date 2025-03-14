class MedianFinder {
public:
    priority_queue<int> lmaxhp;
    priority_queue<int,vector<int>,greater<int>> rminhp;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lmaxhp.empty() || num<lmaxhp.top()){
            lmaxhp.push(num);
        }
        else{
            rminhp.push(num);
        }
        if(abs((int)lmaxhp.size()-(int)rminhp.size())>1){
            rminhp.push(lmaxhp.top());
            lmaxhp.pop();
        }
        else if(lmaxhp.size()<rminhp.size()){
            lmaxhp.push(rminhp.top());
             rminhp.pop();
        }
    }
    
    double findMedian() {
         if(lmaxhp.size()==rminhp.size()){
            return double((rminhp.top()+lmaxhp.top())/2.0);
         }
         else {return lmaxhp.top();}
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */