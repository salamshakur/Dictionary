#include "header.h"

int main(){

  Trie * root = createRoot();

  while(TRUE)
  {
    int input;
    scanf("%d", &input);

    if(input == 1)
      add(root);
    if(input == 2)
      search(root);
    if(input == 3)
      define(root);
    if(input == 0)
      break;
  }

  return EXIT_SUCCESS;

}
