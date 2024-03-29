#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetboard();
void printboard();
int CheckFreeSpace();
void PlayerMove();
void CompMove();
char CheckWinner();
void PrintWinner(char);

int main()
{
    char winner = ' ';
    char response = ' ';
	printf(" ~LET'S PLAY A GAME~ \n\n");
	
    do
    {
    winner = ' ';
    response = ' ';

    resetboard();

    while(winner == ' ' && CheckFreeSpace() != 0)
    {
        printboard();

        PlayerMove();
        winner = CheckWinner();
        if(winner != ' ' || CheckFreeSpace() == 0)
            break;

        CompMove();
        winner = CheckWinner();
        if(winner != ' ' || CheckFreeSpace() == 0)
            break;
    }
    printboard();
    PrintWinner(winner);
    printf("Would you like to play again? (Y/N): ");
    scanf("%c");
    scanf("%c",&response);
    response = toupper(response);
    }while(response == 'Y');

    printf("Thanks for Playing");

    return 0;
}

void resetboard()
{
    for(int i = 0;i<3; i++)
    {
        for(int j=0; j<3 ; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printboard()
{
    printf("\n");
    printf(" %c | %c | %c \n",board[0][0], board[0][1],board[0][2]);
    printf("---+---+----\n");
    printf(" %c | %c | %c \n",board[1][0], board[1][1],board[1][2]);
    printf("---+---+----\n");
    printf(" %c | %c | %c \n",board[2][0], board[2][1],board[2][2]);
    printf("\n");
}
int CheckFreeSpace()
{
    int freespaces = 9;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3 ; j++)
        {
            if (board[i][j] != ' ')
            {
                freespaces--;
            }
        }
    }
    return freespaces;
}
void PlayerMove()
{
    int x,y;

    do
    {
        printf("Enter row #(1-3): ");
        scanf("%d",&x);
        x--;

        printf("Enter row #(1-3): ");
        scanf("%d",&y);
        y--;

        if(board[x][y] != ' ')
            printf("Invalid Move");
        else{
            board[x][y] = PLAYER;
            break;
            }
    }while(board[x][y] != ' ');
}
void CompMove()
{
    srand(time(0));
    int x,y;

    if(CheckFreeSpace() > 0)
    {
        do
        {
            x = rand()%3;
            y = rand()%3;
        }while(board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
    else
        PrintWinner(' ');
}
char CheckWinner()
{
    for(int i = 0; i<0; i++)
    {
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2])
        {
            return board[i][0];
        }
         if(board[0][i]==board[1][i] && board[0][i]==board[2][i])
        {
            return board[0][i];
        }
    }
         if(board[0][0]==board[1][1] && board[0][0]==board[2][2])
        {
            return board[0][0];
        }
         if(board[0][2]==board[1][1] && board[0][0]==board[2][0])
        {
            return board[0][2];
        }
        return ' ';
}
void PrintWinner(char winner)
{
    if(winner == PLAYER)
        printf("YOU WIN!");
    else if(winner == COMPUTER)
        printf("YOU LOST!");
    else
        printf("IT'S A DRAW!");
}
