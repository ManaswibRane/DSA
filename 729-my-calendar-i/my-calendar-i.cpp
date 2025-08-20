class MyCalendar {
public:
    typedef pair<int ,int> P;
    set<P> st;


    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
         auto it=st.lower_bound({s,e});
         if(it!=st.end() && it->first < e){
            return false;
         }

         if(it!=st.begin()){
            auto pr=prev(it);
            if(pr->second > s){
                return false;
            }
         }
         st.insert({s,e});
         return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */