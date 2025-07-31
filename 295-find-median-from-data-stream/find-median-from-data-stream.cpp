class MedianFinder {
public:
priority_queue<int,vector<int>,greater<int>> min_heap;
priority_queue<int,vector<int>> max_heap;
int ct;
    MedianFinder() {
        ct=0;
      
    }
    
    void addNum(int num) {
        ct++;
        if(max_heap.size()==0 || num <max_heap.top()){
            max_heap.push(num);


        }
        else{
            min_heap.push(num);
           
        }
         if((min_heap.size()+1)<(max_heap.size())){
                int n=max_heap.top();
                max_heap.pop();
                min_heap.push(n);
            }
             else if(max_heap.size()<min_heap.size()){
                int n=min_heap.top();
                min_heap.pop();
                max_heap.push(n);
            }
    }
    
    double findMedian() {
            if(max_heap.size()==0){
            return -1;

        }
             if(ct%2!=0){
                   return max_heap.top();
            }
            else{
                int x=max_heap.top();
                int y=min_heap.top();
                double ans=(x+y)/(double)2;
                return ans;
            }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */