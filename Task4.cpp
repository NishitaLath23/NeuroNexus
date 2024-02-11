#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> tasks;

void addNew()
{
    string t;
    cout<<"Enter task:\n";
    cin>>t;
    tasks.push_back({t, 0});
    cout<<"Task added!\n";
    return;
}

void view()
{
    if(tasks.size()==0)
    {
        cout<<"No tasks to show!\n";
        return;
    }
    cout<<"Status\t\tTask\n";
    for(int i=0; i<tasks.size(); i++)
    {
        if(tasks[i].second==1)
            cout<<"Completed\t";
        else    
            cout<<"Pending\t\t";
        cout<<tasks[i].first<<endl;
    }
    return;
}

void viewInd()
{
    cout<<"Index\tStatus\t\tTask\n";
    for(int i=0; i<tasks.size(); i++)
    {
        cout<<i+1<<"\t";
        if(tasks[i].second==1)
            cout<<"Completed\t";
        else    
            cout<<"Pending\t\t";
        cout<<tasks[i].first<<endl;
    }
    return;
}

void mark()
{
    if(tasks.size()==0)
    {
        cout<<"No tasks to mark as complete!\n";
        return;
    }
    viewInd();
    cout<<"Enter index of Task to mark as completed: \n";
    int ind;
    cin>>ind;
    if(ind<0 || ind>tasks.size())
        cout<<"Invalid task index!\n";
    else
    {
        tasks[ind-1].second=1;
        cout<<"Task marked as completed!\n";
    }
    return;
}

void remove()
{
    if(tasks.size()==0)
    {
        cout<<"No tasks to delete!\n";
        return;
    }
    viewInd();
    cout<<"Enter index of Task to be removed: \n";
    int ind;
    cin>>ind;
    if(ind<0 || ind>tasks.size())
        cout<<"Invalid task index!\n";
    else
    {
        tasks.erase(tasks.begin()+ind-1);
        cout<<"Task removed!\n";
    }
    return;
}

int main()
{
    int ch;
    cout<<"To-Do List Manager:\n";
    while(true)
    {
        cout<<"\nPress 1 to add new task.\n";
        cout<<"Press 2 to view tasks. \n";
        cout<<"Press 3 to mark task as complete. \n";
        cout<<"Press 4 to remove task. \n";
        cout<<"Press 0 to exit. \n";
        cin>>ch;
        switch(ch)
        {
            case 0:
                cout<<"Exiting...\n";
                return 0;
            case 1:
                addNew();
                break;
            case 2:
                view();
                break;
            case 3:
                mark();
                break;
            case 4:
                remove();
                break;
            default:
                cout<<"Invalid choice! \n";
        }
    }
}