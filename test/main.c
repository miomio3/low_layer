#include "compiler.h"

int main()
{

  user_input = "-5+20-4";
  token = tokenize(user_input);
  Node *node = expr();
  
  printf(".intel_syntax noprefix\n" );
  printf(".global main\n");
  printf("main:\n");

  gen(node);

  printf("  pop rax\n");
  printf("  ret\n");
  return 0;
}