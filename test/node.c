#include "compiler.h"

Node *new_node(NodeKind kind, Node *ls, Node *rs)
{
  Node *node = calloc(1, sizeof(Node));
  node->kind = kind;
  node->ls = ls;
  node->rs = rs;
  return node;
}

Node *new_node_num(int val)
{
  Node *node = calloc(1, sizeof(Node));
  node->kind = ND_NUM;
  node->val = val;
  return node;
}

Node *expr()
{
  Node *node = mul();
  for(;;)
  {
    if (consume('+'))
      node = new_node(ND_ADD, node, mul());
    else if (consume('-'))
      node = new_node(ND_SUB, node, mul());
    else
      return node;
  }
}

Node *mul()
{
  Node *node = unary();
  for (;;)
  {
    if (consume('*'))
      node = new_node(ND_MUL, node, unary());
    else if (consume('/'))
      node = new_node(ND_DIV, node, unary());
    else
      return node;
  }
}

Node *unary()
{
  for(;;)
  {
    if(consume('+'))
      return primary();
    else if(consume('-'))
      return new_node(ND_SUB, new_node_num(0), primary());
    else
      return primary();
  }
}

Node *primary()
{
  if(consume('('))
  {
    Node *node = expr();
    expect(')');
    return node;
  }

  return new_node_num(expect_number());
}