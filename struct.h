/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Definition */
#define FALSE     0
#define TRUE      1
#define ALPHABET  26
#define MAX       190000

/* Trie Node Object*/
typedef struct  Trie {
  int           isWord;       // Indicates string is a word
  char          * definition; // Definition of the word
  char          * language;   // Indicates the language this word belongs to
  struct Trie   * children[ALPHABET]; // Linked nodes, each corresponding to every letter of the alphabet
} Trie;
