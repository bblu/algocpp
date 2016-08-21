class Solution {
public:
    string reverseString(string s) {
       int n = s.size();
       for(int i=0;i<n/2;i++){
           char t=s[i];
           s[i]=s[n-i-1];
           s[n-i-1]=t;
       }
       return s;
    }
    string reverseStr(string s){
         string result;
        while(!s.empty()){
            result.push_back(s[s.size()-1]); 
            s.pop_back();
        }
        return result;
    }
}; 