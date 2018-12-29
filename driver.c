/* Import Dictionary Functions */
#include "functions.h"

/* Main Driver */
int main() {

  // Create a root for dictionary tree
  Trie * root = createNode();

  while(TRUE)
  {
    // Allocates memory & ask user to enter a word to look up
    char * word = (char *) malloc(sizeof(char) * MAX);
    printf("\nPlease enter a word or enter QUIT to exit program: \n"); scanf("%s", word);

    if(strcmp(word, "QUIT") == 0)
    {
      printf("\nOkay, goodbye!\n");
      return EXIT_SUCCESS;
    }

    // Check if word exists
    if(doesExist(root, word) == TRUE)
    {
      define(root, word);
    }
    else
    {
      // Promp user if they would like to add new word into dictionary
      printf("\nWord does not exist, would you like to add it? Please enter: YES or NO.\n");
      char * input = (char *) malloc(sizeof(char) * 4);
      scanf("%s", input);

      if(strcmp(input, "YES") != 0)
      {
        printf("\n");
      }
      else
      {
        // Read in definition
        printf("\nPlease enter a definition: \n");
        char * definition = (char *) malloc(sizeof(char) * MAX);
        scanf(" %[^\n]", definition);

        // Read in language
        printf("\nPlease enter what language this word belongs to: \n");
        char * language = (char *) malloc(sizeof(char) * MAX);
        scanf("%s", language);

        // Insert word into dictionary
        insert(root, word, definition, language);
        printf("\nWord has been added.\n");
      }
    }

  }

  // Exit program
  return EXIT_SUCCESS;

}
