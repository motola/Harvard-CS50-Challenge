#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <stdio.h>
#include <math.h>


int count_letters(string letter);
int count_words(string word);
int count_sentences(string sentence);
int equation(float L, float S);

int main(void){

    string phrase = get_string("Text: ");

    int letter = count_letters(phrase);
    int words = count_words(phrase);
    int sentence = count_sentences(phrase);

    float avgL =  (float) letter / words * 100;
    float avgS =  (float) sentence / words * 100;
    int result = equation(avgL, avgS);
  /* int result = (grader >= 0) ? (int) (grader + 0.5) : (int) (grader - 0.5); */


   /* printf("AvgS %f\n", avgS);
    printf("AvgL %f\n", avgL);
    printf("result %i\n", result);
    */


     if (result >= 2 && result <= 15) {
          printf("Grade %i\n", result);
        }
   else if (result < 1){
        printf("Before Grade 1\n");
    }

    else if (result >= 16 ) {
        printf("Grade 16+\n");
    }




  /*printf("Letter: %i\n", letter);
    printf("Word: %i\n", words);
    printf("Sentence: %i\n", sentence);
  */

}

int count_letters(string letter){
   int result = 0;

   for (int i = 0, len = strlen(letter); i < len; i++){
    if (isalpha(letter[i])) {
    result++;
    }
   }

   return result;
}

int count_words(string words) {
    int result = 1;
    for (int i = 0, len = strlen(words); i < len; i++){

        if (words[i] == ' ') {
         result++;
        }
    }

    return result;
}

int count_sentences(string sentence){
    int result = 0;

    for (int i = 0, len = strlen(sentence); i < len; i++ ) {

        if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?' ) {
            result++;
        }
    }
    return result;
}

int equation(float L, float S){

    int calc = round(0.0588 * L - 0.296 * S - 15.8);

    return calc;
}

