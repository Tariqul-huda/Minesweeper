#include <iostream>
#include<cstdio>
#define MAX_ROW 3
#define MAX_COL 5
using namespace std;

int main()
{
    char a[MAX_ROW][MAX_COL] = {{'*','*','-','-','-'},{'-','-','-','-','-'},{'-','*','-','-','-'}};
    for(int row=0; row<MAX_ROW; row++)
    {
        for(int col=0; col<MAX_COL; col++)
        {
            if(a[row][col]=='-')
            {
                a[row][col]='0';
            }
        }
    }
    for(int row=0; row<MAX_ROW; row++)
    {
        for(int col=0; col<MAX_COL; col++)
        {

            if(row>=0 && row<MAX_COL-1)
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
                    if(a[row][col]=='*' && a[row-1][col-1]>='0')//Up-left
                        a[row-1][col-1]++;
                    if(a[row][col]=='*' && a[row+1][col-1]>='0') //Down-left
                        a[row+1][col-1]++;
                }
                if(col!=MAX_COL-1)
                {
                    if(a[row][col]=='*'&&a[row+1][col+1]>='0') //Down-right
                        a[row+1][col+1]++;

                    if(a[row][col]=='*' && a[row-1][col+1]>='0') //Up-right
                        a[row-1][col+1]++;
                }

            }
            else
            {
                if(a[row][col]=='*' && a[row][col+1]>='0') //-->
                {
                    a[row][col+1]++;
                }
                if(a[row][col]=='*' && a[row][col-1]>='0') //<--
                    a[row][col-1]++;

            }


        }
    }
    for(int row=0; row<MAX_ROW; row++)
    {
        for(int col=0; col<MAX_COL; col++)
        {
            printf("%c",a[row][col]);
        }
        printf("\n");
    }
    return 0;
}
