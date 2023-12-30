#include <iostream>
using namespace std;
string n1;
string n2;
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token='X';
bool draw=false;
using namespace std;
void functionzero()
{
    cout<<"Tic Tac Toe game."<<endl;
    cout<<"Enter the name of player 1 : ";
    cin>>n1;
    cout<<"Enter the name of player 2 : ";
    cin>>n2;
    cout<<n1<<" Vs "<<n2<<endl; 
}
void functionone()
{
    cout<<"     |       |       "<<endl;
    cout<<"  "<<space[0][0]<<"  |   "<<space[0][1]<<"   |  "<<space[0][2]<<"  "<<endl;
    cout<<"_____|_______|_______"<<endl;
    cout<<"     |       |       "<<endl;
    cout<<"  "<<space[1][0]<<"  |   "<<space[1][1]<<"   |  "<<space[1][2]<<"  "<<endl;
    cout<<"_____|_______|_______"<<endl;
    cout<<"     |       |       "<<endl;
    cout<<"  "<<space[2][0]<<"  |   "<<space[2][1]<<"   |  "<<space[2][2]<<"  "<<endl;
    cout<<"     |       |       "<<endl; 
}

void functiontwo()
{
    int digit;
    if(token=='X')
    {
        cout<<n1<<" Please Enter: ";
        cin>>digit;
    }
    if(token=='0')
    {
        cout<<n2<<" Please Enter: ";
        cin>>digit;
    }

    if(digit==1)
    {
        row=0;
        column=0;
    }
    else if(digit==2)
    {
        row=0;
        column=1;
    }
    else if(digit==3)
    {
        row=0;
        column=2;
    }
    else if(digit==4)
    {
        row=1;
        column=0;
    }
    else if(digit==5)
    {
        row=1;
        column=1;
    }
    else if(digit==6)
    {
        row=1;
        column=2;
    }
    else if(digit==7)
    {
        row=2;
        column=0;
    }
    else if(digit==8)
    {
        row=2;
        column=1;
    }
    else if(digit==9)
    {
        row=2;
        column=2;
    }
    else
    {
        cout<<"INALID entry!!"<<endl;
    }

    if(token=='X' && !(space[row][column]=='X') && !(space[row][column]=='0'))
    {
        space[row][column]='X';
        token='0';
    }
    else if(token=='0' && !(space[row][column]=='X') && !(space[row][column]=='0'))
    {
        space[row][column]='0';
        token='X';
    }
    else
    cout<<"Space is not empty"<<endl;
}

bool functionthree()
{
for(int i=0;i<3;i++)
    {
    if((space[0][i]==space[1][i]&&space[0][i]==space[2][i])||(space[i][0]==space[i][1]&&space[i][0]==space[i][2]))
    {
        return true;
    }
    }
    if((space[0][0]==space[1][1]&&space[0][0]==space[2][2])||(space[0][2]==space[1][1]&&space[0][2]==space[2][0]))
    {
        return true;
    }
     int count=0;
     for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if((space[i][j]=='X')||(space[i][j]=='0'))
            count++;
        }
    }
    if(count==9)
    {
        draw = true;
        return true;
    }

    return false;
}

int main()
{
    
    functionzero();
    functionone();
    while(!functionthree())
    {
        functiontwo();
        functionthree();
        functionone();
    }

    if(token=='X' && draw == false )
    {
        cout<<n2<<" Wins!!"<<endl;
    }
    else if(token=='0' && draw == false )
    {
        cout<<n1<<" Wins!!"<<endl;
    }
    else
    {
        cout<<"it's a draw."<<endl;
    }
}