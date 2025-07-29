class Solution {
public:
//int solve(string start, string end, unordered_set<string>& bank,unordered_set<string> isVisited,int idx,int n){}
    /*if(idx==n){
         return 9999999;
    }
    if(start==end){
        return 0;
    }
     int A=INT_MAX,C=INT_MAX,G=INT_MAX,T=INT_MAX;
    string strA=start,strC=start,strG=start,strT=start;
    strA[idx]='A';
    strC[idx]='C';
    strG[idx]='G';
    strT[idx]='T';
    if(isVisited.find(strA)==isVisited.end() && bank.find(strA)!=bank.end()){
          isVisited.insert(strA);
          A=min(A,1+solve(strA,end,bank,isVisited,idx+1,n));
    }
     if(isVisited.find(strC)==isVisited.end() && bank.find(strC)!=bank.end()){
          isVisited.insert(strC);
          C=min(C,1+solve(strC,end,bank,isVisited,idx+1,n));
    }
     if(isVisited.find(strG)==isVisited.end() && bank.find(strG)!=bank.end()){
          isVisited.insert(strG);
          G=min(G,1+solve(strG,end,bank,isVisited,idx+1,n));
    }
     if(isVisited.find(strT)==isVisited.end() && bank.find(strT)!=bank.end()){
          isVisited.insert(strT);
          T=min(T,1+solve(strT,end,bank,isVisited,idx+1,n));
    }
    return min({A,C,G,T});

}  */


    int minMutation(string start, string end, vector<string>& Bank) {
     queue<string> q;
     unordered_set<string> bank;
     unordered_set<string> isVisited;
     int ans=0;
     for(string & str: Bank){
        bank.insert(str);

     }
     q.push(start);
     while(!q.empty()){
        int n=q.size();
      
        while(n--){
                 string st=q.front();
                 q.pop();
                if(st==end){
                    return ans;
                 }
                
            for(int idx=0;idx<start.length();idx++){
                            string strA=st,strC=st,strG=st,strT=st;
           strA[idx]='A';
           strC[idx]='C';
           strG[idx]='G';
           strT[idx]='T';
           

            if(isVisited.find(strA)==isVisited.end() && bank.find(strA)!=bank.end()){
                isVisited.insert(strA);
                q.push(strA);
          
         }
     if(isVisited.find(strC)==isVisited.end() && bank.find(strC)!=bank.end()){
          isVisited.insert(strC);
          q.push(strC);
        
    }
     if(isVisited.find(strG)==isVisited.end() && bank.find(strG)!=bank.end()){
          q.push(strG);
   
    }
     if(isVisited.find(strT)==isVisited.end() && bank.find(strT)!=bank.end()){
          q.push(strT);
       
    }
            }
        }
        
            
          ans++;   
     }
     return -1;
    }
};