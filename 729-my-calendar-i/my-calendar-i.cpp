class MyCalendar {
public:
    typedef pair<int ,int> P;
    vector<P> calender;


    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        int n=calender.size();
        
        for(int i=0;i<n;i++){
            int st=calender[i].first;
            int end=calender[i].second;
            if( (e>st && s<end)){
                 return false;
            }
        }
       calender.push_back({s,e});
       return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */