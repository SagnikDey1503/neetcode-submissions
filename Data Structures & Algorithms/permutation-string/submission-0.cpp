class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1 (26,0);
        vector<int> v2 (26,0);
        if(s1.length()>s2.length()) return false;

        for(int i=0;i<s1.length();i++){
            v1[s1[i]-'a']++;
              v2[s2[i]-'a']++;
        }
        if(v1==v2) return true;
         
         int l =0 ,r=s1.size();
         while(r<s2.size()){
            v2[s2[l++]-'a']--;
            v2[s2[r++]-'a']++;
              if(v1==v2) return true;
         }
       return false;
    }
};
