#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{

    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    /* printf("Player1 %s\n", player1);
      printf("Player2 %s\n", player2); */

    int score1 = compute_score(player1);
    int score2 = compute_score(player2);

    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }

    else if (score1 < score2)
    {
        printf("Player 2 Wins\n");
    }
    else
    {
        printf("Tie\n");
    }
}

int compute_score(string word)
{
    int score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
        score += POINTS[word[i] - 'A'];
        }
        else if(islower(word[i]))
        {
         score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
