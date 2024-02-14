#include <stdio.h>
#include <string.h>

// TOKENS

typedef enum {
  INT, REG, LET, PUTCHR, INC, DEC, POP, PUSH, CMP, JMP, JE, JNE, JZ, JNZ, INP, JS, JI, ADD, SUB, MUL, DIV, LAB
} token_type;

typedef enum {
  ALPHA, BETA, DELTA, EPSILON, ZETA, ETA, THETA, IOTA, KAPPA, LAMBDA, MU, NU, XI, OMICRON, PI, RHO, SIGMA, TAU,
  UPSILON, PHI, CHI, PSI, OMEGA
} reg;

typedef struct {
  token_type type;
  reg reg_name;
  char lab_name[16];
  int int_value;
} token;

// LEXER

int file_len(char *filename) {
  FILE *fp;
  int count = 0;
  char c;
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Could not open file %s", filename);
    return -1;
  }

  for (c = getc(fp); c != EOF; c = getc(fp)) {
    count++;
  }
  
  fclose(fp);
  printf("LOF : %d\n", count);
  return count;
}
  
void read_file(char *content, char filename[256]) {
  FILE *fp;
  fp = fopen(filename, "r");
  int flen = file_len(filename);
  fgets(content, flen, fp);
  fclose(fp);
} 

void lex(char code[], token *tokens);

int main() {
  file_len("src/main.c");
  return 0;
}
