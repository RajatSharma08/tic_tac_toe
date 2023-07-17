#include<iostream>
using namespace std;

int index1;
char board[9] = {'*','*','*','*','*','*','*','*','*'}; // Single array represents the board '*' means empty box in board

// Function to check if the board is full
int isFull()
{
    for(int i =0;i<9;i++)
    {
        if(board[i]!='X' && board[i]!='O')
        {
            return 0;
        }
    }
    return 1;
}

// Function to check if the user has won
int user_won()
{
    // Check rows
    for(int i=0;i<9;i+=3)
    {
        if((board[i]==board[i+1]) && (board[i+1]==board[i+2]) && (board[i]=='O'))
        {
            return 1;
        }
    }
    // Check columns
    for(int i=0;i<3;i++)
    {
        if((board[i]==board[i+3]) && (board[i+3]==board[i+6]) && (board[i]=='O'))
        {
            return 1;
        }
    }
    // Check diagonals
    if((board[0]==board[4]) && (board[4]==board[8]) && (board[0]=='O'))
    {
        return 1;
    }
    if((board[2]==board[4]) && (board[4]==board[6]) && (board[2]=='O'))
    {
        return 1;
    }
    return 0;
}

// Function to check if the CPU has won
int cpu_won()
{
    // Check rows
    for(int i=0;i<9;i+=3)
    {
        if((board[i]==board[i+1]) && (board[i+1]==board[i+2]) && (board[i]=='X'))
        {
            return 1;
        }
    }
    // Check columns
    for(int i=0;i<3;i++)
    {
        if((board[i]==board[i+3]) && (board[i+3]==board[i+6]) && (board[i]=='X'))
        {
            return 1;
        }
    }
    // Check diagonals
    if((board[0]==board[4]) && (board[4]==board[8]) && (board[0]=='X'))
    {
        return 1;
    }
    if((board[2]==board[4]) && (board[4]==board[6]) && (board[2]=='X'))
    {
        return 1;
    }
    return 0;
}

// Function to draw the tic-tac-toe board
void draw_board()
{
    cout<<endl;
    cout<<board[0]<<"|"<<board[1]<<"|"<<board[2]<<endl;
    cout<<"-----"<<endl;
    cout<<board[3]<<"|"<<board[4]<<"|"<<board[5]<<endl;
    cout<<"-----"<<endl;
    cout<<board[6]<<"|"<<board[7]<<"|"<<board[8]<<endl;
}

// The minimax function
int minimax(bool flag)
{
    int max_val = -1000, min_val = 1000;
    int value = 1;
    int score[9] = {1,1,1,1,1,1,1,1,1}; // If score[i]=1 then it is empty

    for(int i=0;i<9;i++)
    {
        if(board[i] == '*')
        {
            if(min_val > max_val)
            {
                if(flag)
                {
                    board[i] = 'X';
                    value = minimax(false);
                }
                else
                {
                    board[i] = 'O';
                    value = minimax(true);
                }
                board[i] = '*';
                score[i] = value;
            }
        }
    }

    if(flag)
    {
        max_val = -1000;
        for(int j=0;j<9;j++)
        {
            if(score[j] > max_val && score[j] != 1)
            {
                max_val = score[j];
                index1 = j;
            }
        }
        return max_val;
    }
    else
    {
        min_val = 1000;
        for(int j=0;j<9;j++)
        {
            if(score[j] < min_val && score[j] != 1)
            {
                min_val = score[j];
                index1 = j;
            }
        }
        return min_val;
    }
}

int main()
{
    int move, choice;
    cout<<"-------------------------TIC TAC TOE-----------------------------------------------------";
    cout<<endl<<"USER--->(O)      CPU------>(X)";
    cout<<endl<<"SELECT : 1-> Player first 2-> CPU first:";
    cin>>choice;

    if(choice == 1)
    {
        draw_board();
    up:
        cout<<endl<<"Enter the move:";
        cin>>move;
        if(board[move-1]=='*')
        {
            board[move-1] = 'O';
            draw_board();
        }
        else
        {
            cout<<endl<<"Invalid Move......Try a different move";
            goto up;
        }
    }

    while(true)
    {
        cout
