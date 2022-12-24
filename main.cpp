#include <iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    char a[n][m];
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
                cin>>a[row][col];
                }
    }


    for(int row=0; row<n; row++)
    {
        for(int col=0; col<m; col++)
        {
            if(a[row][col]=='.')
            {
                a[row][col]='0';
            }
        }
    }
    for(int row=0; row<n; row++)
    {
        for(int col=0; col<m; col++)
        {

            if(row>=0 && row<n-1)
            {
                if(a[row][col]=='*' && a[row][col+1]>='0') //right
                {
                    a[row][col+1]++;
                }
                if(a[row][col]=='*' && a[row+1][col]>='0') //Down
                    a[row+1][col]++;
                if(a[row][col]=='*' && a[row][col-1]>='0') //Left
                    a[row][col-1]++;


                if(a[row][col]=='*' && a[row-1][col]>='0') //Up
                    a[row-1][col]++;
                if(col!=0)
                {
                    if(a[row][col]=='*' && a[row-1][col-1]>='0')//Up.left
                        a[row-1][col-1]++;
                    if(a[row][col]=='*' && a[row+1][col-1]>='0') //Down.left
                        a[row+1][col-1]++;
                }
                if(col!=m-1)
                {
                    if(a[row][col]=='*'&&a[row+1][col+1]>='0') //Down.right
                        a[row+1][col+1]++;

                    if(a[row][col]=='*' && a[row-1][col+1]>='0') //Up.right
                        a[row-1][col+1]++;
                }

            }
            else
            {
                if(a[row][col]=='*' && a[row][col+1]>='0') //..>
                {
                    a[row][col+1]++;
                }
                if(a[row][col]=='*' && a[row][col-1]>='0') //<..
                    a[row][col-1]++;

            }


        }
    }
    for(int row=0; row<n; row++)
    {
        for(int col=0; col<m; col++)
        {
            printf("%c",a[row][col]);
        }
        printf("\n");
    }
    return 0;
}
