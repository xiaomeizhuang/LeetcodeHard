class Solution {
public:
    string makeLargestSpecial(string S){
        S = "1" + S + "0";
	    string result = recursion(S);
	    return result.substr(1, result.size()-2);
    }
    string recursion(string& S){
        if(S.size()==2) return S;
        vector<string> v;
        string res="";
        int temp=0;
        int pos=1;
        for(int i=1; i<S.size()-1; ++i)
        {
            temp += (S[i]=='1')? 1:-1;
            if(temp==0){
                string str=S.substr(pos,i-pos+1);
                v.push_back(recursion(str));
                pos=i+1;
            }
        }
        sort(v.begin(), v.end(), greater<string>());
        for(auto &c:v) res+=c;
        return "1"+res+"0";
    }
};