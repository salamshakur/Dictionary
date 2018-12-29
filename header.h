#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FALSE    0
#define TRUE     1
#define ALPHABET 26
#define MAX      190000

typedef struct Trie {
  int         isWord;
  char        * definition;
  char        * language;
  struct Trie * children[ALPHABET];
} Trie;

Trie * createRoot(){

  Trie * root = (Trie *) malloc(sizeof(Trie));

  for(int i = 0; i < ALPHABET; i++)
  {
    root->children[i] = NULL;
  }
  root->isWord        = FALSE;
  root->definition    = NULL;

  return root;

}

void add(Trie * root){

  char word[MAX];
  scanf("%s", word);

  int length = strlen(word);

  Trie * current = root;

  for(int i = 0; i < length; i++)
  {
    word[i] = tolower(word[i]);

    int j = (int) word[i] - (int) 'a';

    if(current->children[j] == NULL)
    {
      current->children[j] = createRoot();
    }

    current = current->children[j];
  }

  current->isWord = TRUE;

  char definition[MAX];
  scanf("%[^\n]", definition);

  current->definition = (char *) malloc(sizeof(char) * MAX);
  strcpy(current->definition, definition);

}

void search(Trie * root){

  char word[MAX];
  scanf("%s", word);

  int length = strlen(word);

  Trie * current = root;

  for(int i = 0; i < length; i++)
  {
    word[i] = tolower(word[i]);

    int j = (int) word[i] - (int) 'a';

    if(current->children[j] == NULL)
    {
      printf("(%s) does not exists.\n", word);
      return;
    }

    current = current->children[j];
  }

  if(current->isWord == TRUE && current != NULL)
    printf("%s exists.\n", word);
  else
    printf("%s does not exists.\n", word);

}

void define(Trie * root){

  char word[MAX];
  scanf("%s", word);

  int length = strlen(word);

  Trie * current = root;

  for(int i = 0; i < length; i++)
  {
    word[i] = tolower(word[i]);
    int j = (int) word[i] - (int) 'a';
    current = current->children[j];
  }

  if(current->definition != NULL)
    printf("%s -- %s\n", word, current->definition);
  else
    printf("No definition found.\n");

}
