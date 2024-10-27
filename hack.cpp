#include <bits/stdc++.h>
using namespace std;

int main()
{
    auto file = fopen("hack.txt","w");
    fprintf(file,"1\n100000\n");
    for(int i=1;i<=40000;i++)
    {
        fprintf(file, "%d ", 100000);
    }
}
