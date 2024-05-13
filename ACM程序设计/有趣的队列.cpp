#include<iostream>
#include<queue>
int main()
{
    std::queue<int> que;
    int n,m,cnt=1;
    std::cin>>n>>m;
    while(m--)
    {
        int x;
        std::cin>>x;
        if(!x)que.push(cnt++);
        else{
            que.push(que.front());
            que.pop();
        }
}
    while(!que.empty())
    {
        if(que.size()!=1)
        std::cout<<que.front()<<' ';
        else std::cout<<que.front()<<'\n';
        que.pop();
    }
}