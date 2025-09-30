#define DOUBLE_MIN numeric_limits<double>::lowest()
#define DOUBLE_MAX numeric_limits<double>::max()
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
           int n=points.size();
           double ans=DOUBLE_MIN;
           for(int i=0;i<n-2;i++)
           {
               for(int j=i+1;j<n-1;j++)
               {

                  for(int k=j+1;k<n;k++){
                    double x1=points[i][0],x2=points[j][0],x3=points[k][0];
                     double y1=points[i][1],y2=points[j][1],y3=points[k][1];
                    double area=0.5*fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
                    ans=max(area,ans);

                }
               }


           }
           return ans;
    }
};