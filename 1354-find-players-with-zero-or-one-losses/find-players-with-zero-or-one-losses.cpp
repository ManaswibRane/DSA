;class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
          unordered_map<int,int> lostmp;
          vector<int> winner;
          vector<int> oneloss;
          set<int> players;
          int n=m.size();
          for(auto match:m){
            players.insert(match[0]);
            players.insert(match[1]);
            lostmp[match[1]]++;
          }
          for(int player:players){
              if(lostmp.find(player)==lostmp.end()){
                winner.push_back(player);
              }
              if(lostmp[player]==1){
                 oneloss.push_back(player);
              }
          }
         sort(winner.begin(),winner.end());
         sort(oneloss.begin(),oneloss.end());
          return {winner,oneloss};

    }
};