#ifndef COMPILER_H
#define COMPILER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

typedef enum
{
  ND_ADD,
  ND_SUB,
  ND_MUL,
  ND_DIV,
  ND_NUM,
} NodeKind;

typedef struct Node Node;
struct Node
{
    NodeKind kind;
    Node *rs;
    Node *ls;
    int val;
};

typedef enum{
  TK_RESERVED,
  TK_EOF,
  TK_NUM,
}Tokenkind;


typedef struct Token Token;
struct Token{
  Tokenkind kind;
  Token *next;
  int val;
  char *str;
};


Node *expr();
Node *mul();
Node *primary();
char *user_input;
bool consume(char op);
int expect_number();
void expect(char op);
void gen(Node *node);
void error(char *fmt, ...);
Token *tokenize(char *p);

Token *token;

#endif