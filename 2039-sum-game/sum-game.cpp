class Solution {
public:
    bool sumGame(string s) {
        int n=s.size(),d=0,l=0,r=0;

        for(int i=0;i<n/2;i++)
            if(s[i]=='?') l++;
            else d+=s[i]-'0';

        for(int i=n/2;i<n;i++)
            if(s[i]=='?') r++;
            else d-=s[i]-'0';

        return (l+r)%2 || d != 9*(r-l)/2;
    }
};