#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    int n=rand()%100;
    int guess;
    cout<<"Make a guess.\n";
    cin>>guess;
    while(guess!=n)
    {
        if(guess<n)
            cout<<"Oops! Guess too low. \n";
        else
            cout<<"Oops! Guess too high. \n";
        cout<<"Make another guess. \n";
        cin>>guess;
    }
    cout<<"Congratulations! The number is "<<n<<". "<<endl;
    return 0;
}