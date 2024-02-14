#include <stdio.h>
#include <string.h>

// TOKENS

typedef enum {
  INT, REG, LET, PUTCHR, INC, DEC, POP, PUSH, CMP, JMP, JE, JNE, JZ, JNZ, INP, JS, JI, ADD, SUB, MUL, DIV, LAB,
  PUTINT
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

// REGISTERS

struct registers {
  int alpha, beta, delta, epsilon, zeta, eta, theta, iota, kappa, lambda, mu, nu, xi, omicron, pi, rho, sigma, tau,
  upsilon, phi, chi, psi, omega;
};

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

void lex(char code[], token *tokens) {
  char tok[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int tok_index = 0; // what char in the current token are we in?
  int token_index = 0; // what token are we in the tokens array?
  for (int i = 0; i <= strlen(code), i++) {
    tok[tok_index] = code[i];
    
    if (strcmp(tok, ""))

    // else: try to convert as an int

    tok_index++;
  }

}

int main() {
  file_len("src/main.c");
  token toks[2048];
  return 0;
}
