#include <stdio.h>
#include <string.h>

// TOKENS

typedef enum {
  INT, REG, LET, PUTCHR, INC, DEC, POP, PUSH, CMP, JMP, JZ, JNZ, JS, JI, ADD, SUB, MUL, DIV, LAB,
  PUTINT, INPCHR, INPINT
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

struct {
  int alpha, beta, delta, epsilon, zeta, eta, theta, iota, kappa, lambda, mu, nu, xi, omicron, pi, rho, sigma, tau,
  upsilon, phi, chi, psi, omega;
} registers;

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

void reset_token(char *token, char *last_token) {
  for (int i = 0; i < 16; i++) {
    last_token[i] = 0;
  } 
  strcpy(last_token, token);
  for (int i = 0; i < 16; i++) {
    token[i] = 0;
  } 
}

void lex(char code[], token *tokens) {
  char tok[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  char last_tok[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int tok_index = 0; // what char in the current token are we in?
  int tokens_index = 0; // what token are we in the tokens array?
  int in_label = 0;

  for (int i = 0; i <= strlen(code); i++) {
    if (code[i] == ' ') {continue;} 

    tok[tok_index] = code[i];
    tok_index++;
    printf("%d %s %c\n", in_label, tok, code[i]); // debug printf, to remove in the future

    if (code[i] == '[' && tok_index == 1 && in_label == 0) { // If we are at the start of a label name
      in_label = 1;
      reset_token(tok, last_tok);
      tok_index = 0;
    }

    if (in_label == 1 && code[i] == ']') { // If we are at the end of a label name
      tok[tok_index-1] = ' ';
      in_label = 0;
      tokens[tokens_index].type = LET;
      strcpy(tokens[tokens_index].lab_name, tok);
      printf("- LAB %s\n", tokens[tokens_index].lab_name);
      reset_token(tok, last_tok);
      tok_index = 0;
      tokens_index++;
    } else if (in_label == 1 && code[i] != ']') { // Let the label name be harvested
      continue;
    }

    if (strcmp(tok, "let") == 0) {
      tokens[tokens_index].type = LET;
      reset_token(tok, last_tok);
      tok_index = 0;
      tokens_index++;
      printf("- LET\n");
    }

    // else: try to convert as an int

    
  }

}

int main(int argc, char *argv[]) {
  file_len(argv[1]);
  token toks[2048];
  lex(argv[2], toks);
  return 0;
}
