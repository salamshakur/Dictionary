/* Import Dictionary Functions */
#include "functions.h"

/* Main Driver */
int main() {

  // Create a root for dictionary tree
  Trie * root = createNode();

  // Open text file, if exist. Otherwise, create new file
  FILE * file = fopen("data.txt", "r");

  if(file == NULL)
  {
    file = fopen("data.txt", "w");
  }
  else
  {
    char line[MAX];
    char data[3][MAX];

    // If file found, loop through each line in text file
    while(fgets(line, MAX, file))
    {
      // Store each section of text, separated by the / symbol, into an array
      strcpy(data[0], strtok(line, "/"));
      strcpy(data[1], strtok(NULL, "/"));
      strcpy(data[2], strtok(NULL, "/"));

      // Store those sections into a word, definition, and language accordingly
      char * word = data[0];
      char * definition = data[1];
      char * language = data[2];

      // Insert those words into the dictionary
      insert(root, word, definition, language);
    }
  }

  // loop to keep program open
  while(TRUE)
  {
    // Allocates memory & ask user to enter a word to look up or enter QUIT to exit program
    char * word = (char *) malloc(sizeof(char) * MAX);
    printf("\nPlease enter a word or enter QUIT to exit program: \n"); scanf("%s", word);

    // Exit program
    if(strcmp(word, "QUIT") == 0 || strcmp(word, "quit") == 0)
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
