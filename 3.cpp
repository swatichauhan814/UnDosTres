#include<bits/stdc++.h>
#define MAX_SIZE 100

using namespace std;
 
int max(int x, int y) 
{ 
    return (x > y) ? x : y; 
}

int lps(char *str)
{
   int n = strlen(str), j, L[n][n];
 
   for(int i=0; i<n; i++)
      L[i][i] = 1;
 
    for(int k=2; k<=n; k++)
    {
        for(int i=0; i<n-k+1; i++)
        {
            j = i + k - 1;
            if(str[i] == str[j] && k == 2)
               L[i][j] = 2;

            else if(str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
           
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
 
    return L[0][n-1];
}
 
int main()
{
    char seq[100];
    cin>>seq;
    int n = strlen(seq);
    cout<<lps(seq);
    return 0;
}
