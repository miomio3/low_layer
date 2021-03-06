#include "compiler.h"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    error("引数の数が正しくありません。\n");
    return 0;
  }

  user_input = argv[1];
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