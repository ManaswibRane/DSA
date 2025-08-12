class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
         int x1=coordinates[0][0];
               int y1=coordinates[0][1];
               int x2=coordinates[1][0];
               int y2=coordinates[1][1];
                float slope;
               if((x2-x1)==0){
                   slope=99999;
               }
               else{
                      slope =(float)(y2-y1)/(x2-x1);
               }
      
          for(int i=0;i<(coordinates.size())-1;i++){
               x1=coordinates[i][0];
               y1=coordinates[i][1];
               x2=coordinates[i+1][0];
               y2=coordinates[i+1][1];
               float slope1;
                if((x2-x1)==0){
                   slope1=99999;
               }
               else{
                      slope1 =(float)(y2-y1)/(x2-x1);
               }
               if(slope!=slope1){
                return false;
               }
          }
          return true;
    }
};