#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
#define PSS pair<string,string>
#define PSI pair<string,int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define x first
#define y second
const int N = 3e5 + 10;
using namespace std;

struct node{   ///定义结构体
    string s;  ///姓名
    string id; ///身份证号
    int body;  ///身体状况
    int hh;    ///小时
    int mm;    ///分钟
    int pos;   ///排队序号
}dp[N];

map<string,int>day; ///发放口罩时间
set<PSS>st;         ///记录患病信息是否重复
vector<PSS>peo;     /// 记录患病人群信息
vector<PSS>ans;     /// 记录发口罩记录
vector<node>vp;     /// 记录每一回合可以发口罩
set<string>sp;      /// 记录当天发口罩人群信息

bool cmp(node x,node y){   ///排序
    if(x.hh!=y.hh) return x.hh<y.hh;
    else if(x.mm!=y.mm) return x.mm<y.mm;
    else return x.pos<y.pos;
}


int main(){
    int d,p;
    cin>>d>>p;
    for(int dd=1;dd<=d;dd++){
        int t,s;
        cin>>t>>s;
        char c;
        vp.clear();
        for(int i=1;i<=t;i++){
            cin>>dp[i].s>>dp[i].id>>dp[i].body>>dp[i].hh>>c>>dp[i].mm;
            dp[i].pos=i;
            int len=dp[i].id.size();
            if(len!=18) continue;     ///判断身份证长度是否符合条件
            bool flag=0;
            for(int j=0;j<len;j++){    ///判断身份证是否每一位都是数字
                if(!isdigit(dp[i].id[j])){
                    flag=1;
                    break;
                }
            }
            if(flag) continue;
            if(dp[i].body) peo.pb(PSS{dp[i].s,dp[i].id});  ///记录患病人群信息
            if(day[dp[i].id]+p<dd||!day[dp[i].id]) vp.pb(dp[i]); ///可以发口罩的信息存到vp中
        }
        sort(vp.begin(),vp.end(),cmp); ///排序
        int len=vp.size();
        sp.clear();  ///sp数组清空
        for(int i=0;i<len;i++){
            if(!s) break;  ///判断口罩是否发完
            if(!sp.count(vp[i].id)){  ///判断是否今天发过口罩
                ans.pb(PSS{vp[i].s,vp[i].id});  ///存入ans最后输出
                sp.insert(vp[i].id);  ///记录今天发过口罩
                day[vp[i].id]=dd;  ///更新时间
                s--;  ///剩余口罩数量-1
            }
        }
    }

    for(int i=0;i<(int)ans.size();i++){  ///输出发放口罩信息
        cout<<ans[i].x<<" "<<ans[i].y<<endl;
    }

    for(int i=0;i<(int)peo.size();i++){  ///输出患病人群信息
        if(!st.count(peo[i])){  ///判断是否输出
            cout<<peo[i].x<<" "<<peo[i].y<<endl;
            st.insert(peo[i]);
        }
    }
    return 0;
}

