#include <iostream>
using namespace std;

void read_process(char Process_ID[])
{
    cout<<"Enter the processes:-->"<<endl;
    for(int i=0; i<5; i++)
    {
        cin>>Process_ID[i];
    }
}

void read_BT(int BT_array[])
{
    cout<<"Enter the Burst Time w.r.t processes:-->"<<endl;
    for(int j=0; j<5; j++)
    {
        cin>>BT_array[j];
    }
}



void sorting_fun(char Process_ID[5],int BT_array[5])
{
    int temp1;
    char temp2;
    
    for(int i=0; i<5; i++)
    {
        for(int t=0; t<4-i; t++)
            
        {
            if(BT_array[t] > BT_array[t+1])
        {
            
            temp1 = BT_array[t];
            BT_array[t] = BT_array[t+1];
            BT_array[t+1] = temp1;
            
            temp2 = Process_ID[t];
            Process_ID[t] = Process_ID[t+1];
            Process_ID[t+1] = temp2;
        }
        }
    }
}

void waiting_time(int WT_array[],int BT_array[])
{
    WT_array[0]=0;
    cout<<"The Waiting Time for the processe:-->"<<endl;
    for(int p=1; p<5; p++)
    {
        WT_array[p] = WT_array[p-1] + BT_array[p-1];
    }
    for(int q=0; q<5 ; q++)
    {
        cout<<"The Waiting time for the process:--> "<<q<<endl;
        cout<<WT_array[q]<<endl;
    }
}

void TAT(int TAT_array[5],int BT_array[5],int WT_array[5])
{
    cout<<"The TAT for the processes:-->"<<endl;
    for(int e=0; e<5; e++)
    {
        TAT_array[e] = BT_array[e] + WT_array[e];
        cout<<"The TAT for process "<<e+1<<endl;
        cout<<TAT_array[e]<<endl;
    }
}

void Gantt_chart(int WT_array[5], char Process_ID[5])
{
    WT_array[0]=0;
    cout<<"| "<<Process_ID[0]<<" | "<<Process_ID[1]<<" | "<<Process_ID[2]<<" | "<<Process_ID[3]<<" | "<<Process_ID[4]<<" |"<<endl;
    cout<<WT_array[0]<<"   "<<WT_array[1]<<"   "<<WT_array[2]<<"   "<<WT_array[3]<<"   "<<WT_array[4]<<endl;
    
}

int main()
{
    char Process_ID[5];
    int BT_array[5],  WT_array[5], TAT_array[5];
    int n = sizeof(BT_array[5])/sizeof(BT_array[0]);
    read_process(Process_ID);
    read_BT(BT_array);
    sorting_fun(Process_ID,BT_array);
    waiting_time(WT_array, BT_array);
    TAT(TAT_array, BT_array, WT_array);
    Gantt_chart(WT_array,Process_ID);
    
    return 0;
}
