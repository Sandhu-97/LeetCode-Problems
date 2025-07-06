class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size()==0){
            return s.size()==0; 
        }

        bool first_char_match = false;

        if (s.size()>0 && (s[0]==p[0] || p[0]=='.')) first_char_match=true;

        if (p[1]=='*'){
            bool not_take = isMatch(s, p.substr(2));
            bool take = (first_char_match && isMatch(s.substr(1), p));

            return take || not_take;
        }
        
        return (first_char_match && isMatch(s.substr(1), p.substr(1)));
        
    }
};