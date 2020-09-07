#include "def.h"
#include "data.h"
#include "declarations.h"
static struct ASTnode *primary(void) {
  struct ASTnode *n;
  switch (Token.token) {
    case T_INTLIT:
      n = mkastleaf(A_INTLIT, Token.intvalue);
      scan(&Token);
      return (n);
    default:
      fprintf(stderr, "syntax error in line %d\n", Line-1);
      exit(1);
  }
}
int arithmeticOperator(int tok) {
  switch (tok) {
    case T_PLUS:
      return (A_ADD);
    case T_MINUS:
      return (A_SUBTRACT);
    case T_STAR:
      return (A_MULTIPLY);
    case T_SLASH:
      return (A_DIVIDE);
    default:
      fprintf(stderr, "Unknown token in arithmeticOperator() in line %d\n", Line);
      exit(1);
  }
}

struct ASTnode *binexpr(void) {
  struct ASTnode *n, *left, *right;
  int nodetype;
  left = primary();
  if (Token.token == T_EOF)
    return (left);
  nodetype = arithmeticOperator(Token.token);
  scan(&Token);
  right = binexpr();
  n = mkastnode(nodetype, left, right, 0);
  return (n);
}
