/* Import Dictionary Functions */
#include "functions.h"

/* Main Driver */
int main() {

  // Create a root for dictionary tree
  Trie * root = createNode();

  // Infinite loop to keep program open
  while(TRUE)
  {
    // Allocates memory & ask user to enter a word to look up or enter QUIT to exit program
    char * word = (char *) malloc(sizeof(char) * MAX);
    printf("\nPlease enter a word or enter QUIT to exit program: \n"); scanf("%s", word);

    // Exit program
    if(strcmp(word, "QUIT") == 0)
      return EXIT_SUCCESS;

    // Define word if exist, else create new word
    if(doesExist(root, word) == TRUE)
      define(root, word);
    else
      create(root, word);
  }

  // Exit program
  return EXIT_SUCCESS;
}
