#include <stdio.h>
#include <cs50.h>



void row_brick(int space, int brick);
int n;

int main(void)
{

   do {
    n = get_int("Height: ");
   }
    while (n < 1);

    for (int i = 0; i < n; i++){
      printf("M");

    /*
    for (int j = n; j > i + 1; j--){

     printf(" ");
    }

    for (int k = 0; k < i + 1; k++) {
      printf("#");
    }



    printf("\n");
    */

   row_brick(i + 1, i + 1);
    }

    }


   void row_brick(int space, int brick){
    for (int j = n; j > space; j-- ) {
      printf(" ");
    }
    for (int k = 0; k < brick; k++){
      printf("#");
    }
    printf("\n");

   }
