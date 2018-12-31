/* Import Dictionary Functions */
#include "functions.h"

/* Main Driver */
int main() {

  // Create a root for dictionary tree
  Trie * root = createNode();

  // Open exisiting text file, otherwise create a new one
  FILE * file = fopen("data.txt", "a+");
  
  char line[MAX];
  char data[3][MAX];

  // If file has any content, loop through each line of text
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

  // loop to keep program open
  while(TRUE)
  {
    // Allocates memory & ask user to enter a word to look up or enter QUIT to exit program
    char * word = (char *) malloc(sizeof(char) * MAX);
    printf("\nPlease enter a word or enter EXIT to exit program: \n"); scanf("%s", word);

    // Exit program
    if(strcmp(word, "EXIT") == 0 || strcmp(word, "exit") == 0)
      return EXIT_SUCCESS;

    // Define word if exist, else create new word
    if(doesExist(root, word) == TRUE)
      define(root, word);
    else
      create(root, word, file);
  }

  // Close file
  fclose(file);

  // Exit program
  return EXIT_SUCCESS;
}
