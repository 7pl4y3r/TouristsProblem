#include <iostream>
#include <fstream>

using namespace std;

ifstream in("luggage.txt");
int n,m,st[10],si,f[10];
char item[10];

void init()
{
    in >> n >> m;
    for(int si = 1; si <= n; si++){
        in >> item[si];
        switch(item[si])
        {
             case 'i': f[1]++;break;
             case 'a': f[2]++;break;
             case 't': f[3]++;break;
        }
    }
}

void write()
{
    for(int i = 1; i <= n; i++)
        cout << item[i] << ' ';
}

void putItems()
{
    while(f[1] <= 2){
        item[++si] = 'i';
        f[1]++;
    }

    while(f[2] <= 3){
        item[++si] = 'a';
        f[2]++;
    }

    while(f[3] <= 2){
        item[++si] = 't';
        f[3]++;
    }
}

void bcktr()
{
    int p = 1;
    st[p] = 0;

    while(p > 0){

        if(st[p] < n){

            st[p]++;
            if(p == m)
                write();
            else
                st[++p] = 0;

        } else p--;
    }
}

int main()
{
    init();

    if(m < 5)
        cout << "NSP\n";

    else {

       putItems();
       bcktr();

    }

    return 0;
}
