#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

char *expected_tokens[] = {"3", "A", "+", "6", "43", NULL};

int arg_in_expected_tokens(char *arg, char **tokens){
  int found_token_chars = 0;
  for(char **it_token = tokens; *it_token != NULL; it_token++){
    if(!strcmp(arg, *it_token))
      return 1;
  }
  printf("Assertion Failed: %s not in [", arg);
  for(char **it_token = tokens; *it_token != NULL; ++it_token)
    printf("%s, ", *it_token);
  printf("]\n");
  return 0;
}

int main(int argc, char **argv) {
  assert(argc>1);
  for(int i = 1; i < argc; i++)
    assert(arg_in_expected_tokens(argv[i], expected_tokens));
  printf("Tests: Passed\n");
  exit(0);
}
