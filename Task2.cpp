#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n1, n2, ans, flag=1;
    char op;
    cout<<"Enter two numbers: \n";
    cin>>n1>>n2;
    cout<<"Enter the operation you want to be performed (+, -, *, /): \n";
    cin>>op;
    switch(op)
    {
        case '+':
            ans=n1+n2;
            break;
        case '-':
            ans=n1-n2;
            break;
        case '*':
            ans=n1*n2;
            break;
        case '/':
            ans=n1/n2;
            break;
        default:
            flag=-1;
    }
    if(flag==-1)
        cout<<"Wrong operator!\n";
    else
        cout<<n1<<" "<<op<<" "<<n2<<" = "<<ans<<endl;
    return 0;
}