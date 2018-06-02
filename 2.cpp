#include<bits/stdc++.h>
#define MAX_SIZE 100

using namespace std;
  
void Parenthesis(int pos, int n, int open, int close)
{
    static char str[MAX_SIZE];     
     
    if(close == n) 
    {
        cout<<str<<endl;
        return;
    }
    else
    {
        if(open > close) 
        {
            str[pos] = '}';
            Parenthesis(pos+1, n, open, close+1);
        }
         
        if(open < n)
        {
	        str[pos] = '{';
	        Parenthesis(pos+1, n, open+1, close);
        }
    }
}

void printParenthesis(int n)
{
    if(n > 0)
        Parenthesis(0, n, 0, 0);
    return;
}     
 
int main()
{
    int n;
    cin>>n;
    printParenthesis(n);
    return 0;
}