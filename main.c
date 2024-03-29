#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main()
{
    srand(time(NULL));

    int player_throw = 0;
    int ai_throw = 0;
    bool draw = false;

     printf("~~Let's Play Rock,Paper,Scissors~~\n");
    do
    {
    printf("Player's pick\n");
    printf("1.Rock\n");
    printf("2.Paper\n");
    printf("3.Scissors\n");
    printf("Selection: ");
    scanf("%d",&player_throw);

    ai_throw = (rand()%3)+1;

    if(ai_throw==ROCK)
        printf("The AI throws Rock\n");
    else if(ai_throw==PAPER)
        printf("The AI throws Paper\n");
    else if(ai_throw==SCISSORS)
        printf("The AI throws Scissors\n");

    draw=false;
    if(player_throw==ROCK && ai_throw==SCISSORS)
        printf("ROCK beats SCISSORS. You Win!\n\n");
    else if(player_throw==ROCK && ai_throw==PAPER)
        printf("PAPER beats ROCK. You Lose!\n\n");
    else if(player_throw==SCISSORS && ai_throw==PAPER)
        printf("SCISSORS beats PAPER. You Win!\n\n");
    else if(player_throw==SCISSORS && ai_throw==ROCK)
        printf("ROCK beats SCISSORS. You Lose!\n\n");
    else if(player_throw==PAPER && ai_throw==ROCK)
        printf("PAPER beats ROCK. You Win!\n\n");
    else if(player_throw==PAPER && ai_throw==SCISSORS)
        printf("SCISSORS beats PAPER. You Lose!\n\n");
    else
    {
        printf("\nDRAW! Play Again!\n\n");
        draw=true;
    }


    }while(draw);

	return 0;
}

