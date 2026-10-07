class Solution {
public:
    bool isNumber(string s) {
        int ei=-1;
        for(int i=0;i<s.size();i++)if(s[i]=='E'||s[i]=='e'){
            ei=i;break;
        }
        if(ei!=-1&&(ei==0||ei==s.size()-1))return 0;
        if(ei!=-1){
int spsi=ei+1;
if(s[spsi]=='+'||s[spsi]=='-')spsi++;
if(spsi==s.size())return 0;
for(int i=spsi;i<s.size();i++){
    if(s[i]>='0'&&s[i]<='9')continue;
    return 0;
}
int fpsi=0;
if(s[fpsi]=='+'||s[fpsi]=='-')fpsi++;
if(fpsi==ei)return 0;

bool dec=false;
bool dg=false;
for(int i=fpsi;i<ei;i++){
    if(s[i]>='0'&&s[i]<='9'){dg=true;continue;}
    if(s[i]=='.'&&dec==false){dec=true;continue;}
    return 0;
}
return dg;

        }
        ei=s.size();
        int fpsi=0;
if(s[fpsi]=='+'||s[fpsi]=='-')fpsi++;
if(fpsi==ei)return 0;
bool dec=false;
bool dg=false;
for(int i=fpsi;i<ei;i++){
    if(s[i]>='0'&&s[i]<='9'){dg=true;continue;}
    if(s[i]=='.'&&dec==false){dec=true;continue;}
    return 0;
}
      return dg;  
    }
};