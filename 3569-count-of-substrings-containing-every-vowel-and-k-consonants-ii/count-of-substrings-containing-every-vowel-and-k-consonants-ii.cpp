class Solution {
public:
  bool isVowel(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
        return true;
    }
    return false;
  }
    long long countOfSubstrings(string word, int k) {
        long long cons=0;
        long long ans=0;
        long wlen=word.length();
        vector<int> nextCons(wlen);
         unordered_map<char,long> vowel;
            long nextchar=wlen;
         for(long i=wlen-1;i>=0;i--){
            nextCons[i]=nextchar;
            if(!isVowel(word[i])){
                nextchar=i;
            }
         }

         int i=0,j=0;
         while(j<wlen && i<wlen){
            if(!isVowel(word[j])){
                cons++;
            }
            else{
               vowel[word[j]]++ ;
            }
          
            while (cons > k) {
                if (!isVowel(word[i])) {
                    cons--;
                } else {
                    vowel[word[i]]--; 
                    if (vowel[word[i]] == 0) {
                        vowel.erase(word[i]); 
                    }
                }
                i++;
            }

                     while(i < wlen && vowel.size() == 5 && cons == k) { 
                int idx = nextCons[j];
                ans += idx - j; 
                char ch = word[i];
                if(isVowel(ch)) {
                    vowel[ch]--;
                    if(vowel[ch] == 0) {
                        vowel.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};
