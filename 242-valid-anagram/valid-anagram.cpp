class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        unordered_map<char,int> frq;

        for(int i = 0; i<s.size(); i++){
            if(frq.count(s[i])){
                frq[s[i]]++;
            }else{
                frq[s[i]] = 1;
            }
        }
       for(int i = 0; i<t.size(); i++){
        if(frq.count(t[i])){
            frq[t[i]]--;
            if(frq[t[i]] == 0){
                frq.erase(t[i]);
            }
        }else{
            return false;
        }
    }

        return frq.size() == 0;
    }
};