class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
           int n=m.size();
           int meetDay=0;
           vector<bool> isMeetDay(days,false);
           int prevEnd=0;
          sort(m.begin(),m.end());
           for(int i=0;i<n;i++){

               int stTime=m[i][0];
                int endTime=m[i][1];
                if(stTime>prevEnd){
                    meetDay+=stTime-prevEnd-1;
                }
               
                prevEnd=max(endTime,prevEnd);
        
           }
           if(prevEnd<days){
              meetDay+=(days-prevEnd);
           }
           return meetDay;
    }
};