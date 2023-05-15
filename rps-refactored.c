#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gameEngine(int); /* This method is designed to evaluate the winner */

int main()
{
    /* Setting up the Rock Paper Scissors (RPS) enum characters for the game menu */
    enum rps {R = 'R', r = 'r', P = 'P', p = 'p',
        S = 'S', s = 's', Q = 'Q', q = 'q'};
    enum rps player; /* initializing enum player variable */
    int flag;        /* boolean flag to determaine when to exit program. to exit set flag = 0 */
    
    /* Player starting point & instructions */
    printf("\n");
    printf("#############################################################\n");
    printf("#\t\tRock Paper Scissors\n");
    printf("#############################################################\n");
    printf("#  Developer: Brenden Boswell\n");
    printf("#  School:    The Ohio State University (Go Bucks!)\n");
    printf("#  Intro: Welcome to my version of Rock-Paper-Scissors. Below,\n");
    printf("#         you will find instruction on how to play this game!\n");
    printf("#  RULES:\n");
    printf("# -Rock wins for rock and scissors (rock pounds scissors)\n");
    printf("# -Paper wins for rock and paper (paper covers rock)\n");
    printf("# -Scissors wins for scissors and paper (scissors cut paper)\n");
    printf("# -Tie if the options chosen by both players are identical.\n");
    printf("#############################################################\n");
    printf("\n");
    printf("R (or) r = (Rock)\n");
    printf("P (or) p = (Paper)\n");
    printf("S (or) s = (Scissors)\n");
    printf("Q (or) q = (Quit)\n");

    /* Start of main program loop */
    do
    {
        printf("\nUSER CHOICE: ");
        player = getchar();
        
    /* gets players first choice, holds enum char value */
    switch (player) {
        case R:
        case r:
            flag = 1;
            gameEngine(1); /* Call to game algorithm */
            break;
        case P:
        case p:
            flag = 1;
            gameEngine(2); /* Call to game algorithm */
            break;
        case S:
        case s:
            flag = 1;
            gameEngine(3); /* Call to game algorithm */
            break;
        case Q:
        case q:
            flag = 0;
            printf("THE END.......\n");
            break;
        default: /* Incorrect selection, invalid character: message display */
            flag = 1;
            printf("\n");
            printf("Invalid selection, please try again! \n");
            printf("Select one of the following choices below.\n");
            printf("R (or) r = (Rock)\n");
            printf("P (or) p = (Paper)\n");
            printf("S (or) s = (Scissors)\n");
            printf("Q (or) q = (Quit)\n");
            break;
        
    }
        getchar();  /* Used to consume \n character */
    } while (flag); /* Invalid selection flag. Continue loop until flag = 0 */
    return (0);
}

void gameEngine(int player){

    srand(time(NULL)); /* Setting the (seed) for new random values, use computers clock */
    int computer = rand() % 3+1; /* Randomized computer choice: R(1), P(2), S(3) */
    
    /* Grabs random computer generated value & compares with player value to determaine winner. */
    
    switch (computer) {
        case 1:                        /* Computer Rock(1) */
            printf("COMPUTER CHOICE: R\n");
            if (player == 3){          /* Computer Rock, Player Scissors */
                printf("Winner: <COMPUTER>\n");
                printf("The (R)ock Smashed your pesky little (S)cissors....\n");
            } else if (player == 1){   /* Computer Rock, Player Rock */
                printf("<< TIE >>\n");
            }else{                     /* Computer Rock, Player Paper */
                printf ("Winner: <PLAYER>\n");
            }
            break;
        case 2:                       /* Computer Paper(2) */
            printf("COMPUTER CHOICE: P\n");
            if (player == 1){         /* Computer Paper, Player Rock */
                printf ("Winner: <COMPUTER>\n");
                printf("The (P)aper smothered your poor little (R)ock....\n");
            } else if (player == 2){  /* Computer Paper, Player Paper */
                printf("<< TIE >>\n");
            } else{                   /* Computer Paper, Player Scissors */
                    printf ("Winner: <PLAYER>\n");
            }
            break;
        case 3:                         /* Computer Scissors(3) */
            printf("COMPUTER CHOICE: S\n");
            if (player == 2){           /* Computer Scissors, Player Paper */
                printf ("Winner: <COMPUTER>\n");
                printf("Those (S)cissors cut up your HW (P)aper....\n");
            } else if (player == 3){    /* Computer Scissors, Player Scissors */
                printf("<< TIE >>\n");
            } else{                     /* Computer Scissors, Player Rock */
                printf ("Winner: <PLAYER>\n");
            }
            break;
    }
}
