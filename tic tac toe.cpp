//to prepare toc tac toe game
#include<iostream>
using namespace std;
int row, column;
char choice,turn='O' ;
void display_board();
bool Draw = false;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void display_board()
{
cout<<"\n"<<"\n\t"<< 
board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<"\n\t_____\n\t"<<board[1][0]<<"|"<<board[1][1]<<
"|"<<board[1][2]<<"\n\t_____"<< "\n\t"<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2]<<"\n"<< 
"\n \t"<<endl;
}
void turn_order()
{
 //cout<<turn;
 if(turn=='X')
 {
 turn='O';
 }
else if(turn=='O')
 {
 turn='X';
 }
 // cout<<turn;
}
void player_turn()
{
 if(turn=='X')
 {
 cout<<"Player 1[X]"<<endl;
 }
 else if(turn=='O')
 {
 cout<<"Player 2[O]"<<endl;
 }
 cin>>choice;
 switch(choice)
{
 case '1': row=0; column=0;
 break;
case '2': row=0; column=1;
 break;
case '3': row=0;column=2;
break;
case '4': row=1; column=0;
 break;
case '5': row=1;column=1;
 break;
case '6': row=1;column=2;
 break;
case '7': row=2 ;column=0;
 break;
case '8': row=2 ;column=1;
 break;
case '9': row=2;column=2;
 break;
 default:cout<<"invalid case"<<endl;
}
if(turn=='X'&& board[row][column]!='X'&& board[row][column]!='O')
{
 board[row][column]='X';
}
else if(turn=='O'&& board[row][column]!='O'&& board[row][column]!='X')
{
 board[row][column]='O';
}
else
{
cout<<"Position is already filled"<<endl;
 display_board();
 player_turn();
}
}
bool game_over()
{
 for( int i=0;i<3;i++)
 {
 if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && 
board[0][i]==board[2][i])
 return false;
 }
 if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][3]==board[1][1] && 
board[0][3]==board[2][1])
 return false;
for (int i=0;i<3;i++)
 {
 for (int j=0;j<3;j++)
 {
 if (board[i][j]!='O' && board[i][j]!='X')
 return true;
}
 }
 Draw=true;
 return false;
}
int main()
{
while(game_over())
{
 display_board();
 turn_order();
 player_turn();
}
if(turn=='X' && Draw==false)
{
 cout<<"Player 1 is winner"<<endl;
}
else if(turn=='O' && Draw==false)
{
 cout<<"Player 2 is winner"<<endl;
}
else
{
cout<<"Draw"<<endl;
}
return 0;
}