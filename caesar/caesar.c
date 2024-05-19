#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


bool only_digits(string args);
int rotate(char s, int txt);

int main(int argc, string argv[]){
  bool is_digit;
  int num;

  if (argv[1]) {
    is_digit = only_digits(argv[1]);
  }

  if (argc != 2 || is_digit == false) {
    printf("Usage: %s Key \n", argv[0]);
    return 1;
  }
  if (is_digit){
    num = atoi(argv[1]);
  }

  string text = get_string("Plaintext: ");
  int len = strlen(text);
  int result;
  char rtext[len*2];
  string letter;


  for (int i = 0; i < len; i++){
     result = rotate(text[i], num);
   /*   rtext = "%c" + result; */
      sprintf(&rtext[i], "%c", result);
   /* printf("Ciphertext: %c ", rtext[i]); */


  }
 printf("Ciphertext: %s\n", rtext);
  return 0;
}

bool only_digits(string args){
  for (int i = 0, len = strlen(args); i < len; i++){
       if(isdigit(args[i])) {
        return true;
       }
       else {
         return false;
       }

  }
 return 0;
}

int rotate(char s, int key){
  int result;


  if (isalpha(s) && isupper(s)){
   result = ((s - 'A') + key) % 26;
   return result + 'A';
  }
  else if (isalpha(s) && islower(s)){
   result = ((s - 'a') + key) % 26;
   return result + 'a';
  }
  else {
   return result = s;

  }
}
