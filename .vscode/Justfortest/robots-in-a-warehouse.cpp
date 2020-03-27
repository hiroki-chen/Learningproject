#include <iostream>
using namespace std;
int a,b,n,m;
class wxl
{
public:
    int x, y; //The coordination of each robot//
    int s; //The serial number of each robot//
}ht[1000];
bool panduan(int h)//判断机器人是否会相撞 
{
    if(ht[h].x<=0||ht[h].x>a||ht[h].y<=0||ht[h].y>b)
    {
        cout<<"Robot "<<h<<" crashes into the wall"<<endl;
        return false;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==h)continue;
        if(ht[i].x==ht[h].x&&ht[i].y==ht[h].y)
        {
            cout<<"Robot "<<h<<" crashes into robot "<<i<<endl;
            return false;
        }
    }
    return true;
}
int main()
{
    int i,t,p,j,k;
    bool flag;
    string str;
    cin>>k;
    while(k--)
    {
        cin>>a>>b>>n>>m;
        for(i=1;i<=n;i++)//将方向转为数字存 
        {
            cin>>ht[i].x>>ht[i].y>>str;
            if(str=="N")ht[i].s=0;
            else if(str=="E")ht[i].s=1;
            else if(str=="S")ht[i].s=2;
            else if(str=="W")ht[i].s=3;
        }
        flag=true;//开始全为不会相撞 
        for(i=0;i<m;i++)
        {
            cin>>t>>str>>p;//t为机器人，str表示往哪个方向，p表示前进几步 
            if(str=="F")//F最为简单，先判断 
            {
                if(flag)
                {
                    for(j=0;j<p;j++)
                    {
                        if(ht[t].s==0)ht[t].y++;
                        if(ht[t].s==1)ht[t].x++;
                        if(ht[t].s==2)ht[t].y--;
                        if(ht[t].s==3)ht[t].x--;
                        flag=panduan(t);//此处开始判断 
                        if(!flag)break;//因为在函数中写了输出函数，此处直接退出 
                    }
                }
            }
            else if(str=="L")
            {
                ht[t].s=(ht[t].s-p%4+4)%4;
            }
            else if(str=="R")
            {
                ht[t].s=(ht[t].s+p%4)%4;
            }
        }
        if(flag)cout<<"OK"<<endl;
    }
}