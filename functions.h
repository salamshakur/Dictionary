/* Import Trie Struct & Definitions */
#include "struct.h"

/* Creates A New Node*/
Trie * createNode() {

  Trie * root = (Trie *) malloc(sizeof(Trie));

  for(int i = 0; i < ALPHABET; i++)
  {
    root->children[i] = NULL;
  }
  root->isWord        = FALSE;
  root->definition    = NULL;

  return root;

}

/* Insert Word Into Dictionary */
void insert(Trie * root, char * word, char * definition, char * language) {

  // Get length of word
  int length = strlen(word);

  // Keep track of current node as it transverses tree
  Trie * current = root;

  // Loop through word...
  for(int i = 0; i < length; i++)
  {
    // If letter is uppercase, convert them to lowercase
    if (word[i] >= 'A' && word[i] <= 'Z')
         word[i] = word[i] + 32;

    // Convert each letter into an index
    int n = (int) word[i] - (int) 'a';

    // If there is no letter associated with this node, insert one
    if(current->children[n] == NULL)
      current->children[n] = createNode();

    // Keeping track of the current node
    current = current->children[n];
  }

  // Flag final node to indicate that this string is a word
  current->isWord = TRUE;

  // Insert defintion
  current->definition = (char *) malloc(sizeof(char) * MAX);
  strcpy(current->definition, definition);

  // Insert the language this word belongs to
  current->language = (char *) malloc(sizeof(char) * MAX);
  strcpy(current->language, language);
}

/* Check If Word Exists In Dictionary */
int doesExist(Trie * root, char * word) {

  // Get length of word
  int length = strlen(word);

  // Keep track of current node as it transverses tree
  Trie * current = root;

  // Loop through word...
  for(int i = 0; i < length; i++)
  {
    // If letter is uppercase, convert them to lowercase
    if (word[i] >= 'A' && word[i] <= 'Z')
         word[i] = word[i] + 32;

    // Convert each letter into an index
    int n = (int) word[i] - (int) 'a';

    // Check if complete word exists. Otherwise word doesn't exists, return FALSE
    if(current->children[n] == NULL)
      return FALSE;

    // Keeping track of the current node
    current = current->children[n];
  }

  // If the end of tranversal, the flag is found, word exists. Return TRUE
  if(current->isWord == TRUE && current != NULL)
    return TRUE;
  else
    return FALSE;
}

/* Gives Definition of Word */
void define(Trie * root, char * word) {

  // Get length of word
  int length = strlen(word);

  // Keep track of current node as it transverses tree
  Trie * current = root;

  // Loop through word...
  for(int i = 0; i < length; i++)
  {
    // If letter is uppercase, convert them to lowercase
    if (word[i] >= 'A' && word[i] <= 'Z')
         word[i] = word[i] + 32;

    // Convert each letter into an index
    int j = (int) word[i] - (int) 'a';

    // Keeping track of the current node
    current = current->children[j];
  }

  // Print word's definition and language it belongs to
  printf("\n");
  printf("%s\n", word);
  printf("Definition: %s\n", current->definition);
  printf("language: %s\n", current->language);
}

/* Prompt User to Create New Word*/
void create(Trie * root, char * word, FILE * file) {

  // Promp user if they would like to add new word into dictionary
  printf("\nWord does not exist, would you like to add it? Please enter: YES or NO.\n");
  char * input = (char *) malloc(sizeof(char) * 4);
  scanf("%s", input);

  // If yes, create word
  if(strcmp(input, "YES") == 0 || strcmp(input, "yes") == 0 )
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

    // Save data into text file
    saveText(file, word, definition, language);

    // Prompt user that process was a success
    printf("\nWord has been added.\n");
  }

}

/* Save Word Into Text File */
void saveText(FILE * file, char * word, char * definition, char * language) {

  

}
