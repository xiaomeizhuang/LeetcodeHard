class Solution {
public:
    string countOfAtoms(string formula) {
        int pos=0;
        string res="";
        for(auto a: recursion(formula, pos)){
            res+=a.first + (a.second==1 ? "":to_string(a.second));
        }
        return res;
    }
    map<string, int>recursion(string& str, int& pos){
        map<string, int>temp;
        int i=0;
        string num=" ";
        for(;pos<str.size();++pos){
            if(str[pos]=='('){
                ++pos;
                for(auto& a:recursion(str,pos))temp[a.first]+=a.second;
            }
            else if(str[pos]==')'){
                i=++pos;
                while(isdigit(str[pos]) && pos<str.size())
                    ++pos;
                num=str.substr(i,pos-i);
                --pos;
                int multiple=stoi(num);
                for(auto &a:temp) temp[a.first] *= multiple;
                return temp;
            }
            else{
                i=pos++;
                while(islower(str[pos]) && pos<str.size())
                    ++pos;
                string elem=str.substr(i,pos-i);
                i=pos;
                while(isdigit(str[pos]) && pos<str.size())
                    ++pos;
                num=str.substr(i,pos-i);
                temp[elem]+=num.empty()? 1 : stoi(num);
                --pos;
            }
        }
        return temp;
    }
};