#include <bits/stdc++.h>
using namespace std;

void displayBoard(vector<vector<char>> B)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<B[i][j];
            if(j!=2)
                cout<<" | ";
        }
        cout<<endl;
        if(i!=2)
            cout<<"-----------\n";
    }
    cout<<endl;
    return;
}
char checkWin(vector<vector<char>> B)
{
    char w=' ';
    int f=0;
    for(int i=0; i<3; i++)
    {
        if(B[i][0]==B[i][1] && B[i][1]==B[i][2])
        {
            w=B[i][0];
            break;
        }
        if(B[0][i]==B[1][i] && B[1][i]==B[2][i])
        {
            w=B[0][i];
            break;
        }
    }
    if(w==' ')
    {
        if(B[0][0]==B[1][1] && B[1][1]==B[2][2])
            w=B[1][1];
        if(B[2][0]==B[1][1] && B[1][1]==B[0][2])
            w=B[1][1];
    }
    if(w==' ')
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(B[i][j]==' ')
                    f=1;
            }
        }
        if(f==0)
            w='D';
    }
    return w;
}
int turnX(vector<vector<char>> &B)
{
    cout<<"Ongoing\n";
    displayBoard(B);
    int X, Y;
    cout<<"Player X's turn:\nInput Row and Column (1/2/3) ";
    cin>>X>>Y;
    if(B[X-1][Y-1]!=' ' || X<1 || X>3 || Y<1 || Y>3)
    {
        cout<<"Invalid move!\n";
        return 0;
    }
    B[X-1][Y-1]='X';
    return 1;
}
int turnO(vector<vector<char>> &B)
{
    cout<<"Ongoing\n";
    displayBoard(B);
    int X, Y;
    cout<<"Player O's turn:\nInput Row and Column (1/2/3) ";
    cin>>X>>Y;
    if(B[X-1][Y-1]!=' ' || X<1 || X>3 || Y<1 || Y>3)
    {
        cout<<"Invalid move!\n";
        return 0;
    }
    B[X-1][Y-1]='O';
    return 1;
}
char newGame(int f)
{
    int c;
    if(f==1)
    {
        vector<vector<char>> B(3, vector<char>(3, ' '));
        char w=' ';
        while(w==' ')
        {
            c=turnX(B);
            if(c==0)
                w='C';
            else
                w=checkWin(B);
            if(w!=' ')
                return w;
            c=turnO(B);
            if(c==0)
                w='C';
            else
                w=checkWin(B);
        }
        return w;
    }
    else
    {
        vector<vector<char>> B(3, vector<char>(3, ' '));
        char w=' ';
        while(w==' ')
        {
            c=turnO(B);
            if(c==0)
                w='C';
            else
                w=checkWin(B);
            if(w!=' ')
                return w;
            c=turnX(B);
            if(c==0)
                w='C';
            else
                w=checkWin(B);
        }
        return w;
    }
}
int main()
{
    int ch=1, first=1;
    while(ch)
    {
        char w=newGame(first);
        if(w=='D')
            cout<<"It's a Draw!\n";
        else if(w=='X')
            cout<<"Congratulations! Player X won.\n";
        else if(w=='O')
            cout<<"Congratulations! Player O won. \n";
        else
            cout<<"Game Dismissed\n";
        char i;
        cout<<"Do you want to play again? (Y/N):\n";
        cin>>i;
        if(i!='Y' && i!='y')
            ch=0;
        first=!first;
    }
    return 0;
}