#include <assert.h>
#include <stdio.h>
#include <unistd.h>

#include "print_assert.h"

static const char* t1
  = "hellohellohellohellohellohellohellohellohellohellohellohellohellohell"
    "ohellohellohellohellohellohellohellohellohellohellohellohellohellohel"
    "lohellohellohellohellohellohellohellohellohellohellohellohellohellohe"
    "llohellohellohellohellohellohellohellohellohellohellohellohellohelloh"
    "ellohellohellohellohellohellohellohellohellohellohellohellohellohello"
    "hellohellohellohellohellohellohellohellohellohellohellohellohellohell"
    "ohellohellohellohellohellohellohellohellohellohellohellohellohellohel"
    "lohellohellohellohellohellohellohellohellohellohellohellohellohellohe"
    "llohellohellohellohellohellohellohellohellohellohellohellohellohelloh"
    "ellohellohellohellohellohellohellohellohellohellohell"
    "ohellohellohellohellohellohellohellohellohellohellohellohellohellohel"
    "lohellohellohellohellohellohellohellohellohellohellohellohellohellohe"
    "llohellohellohellohellohellohellohellohellohellohellohellohellohelloh"
    "ellohellohellohellohellohellohellohellohellohellohellohellohellohello"
    "hellohellohellohellohellohellohellohellohellohellohellohellohellohell"
    "ohellohellohellohellohellohellohellohellohellohellohellohellohellohel"
    "lohellohellohellohellohellohellohellohellohellohellohellohellohellohe"
    "llohellohellohellohellohellohellohellohellohellohellohellohellohelloh"
    "ellohellohellohellohellohellohellohellohellohellohell"
    "ohellohellohellohellohellohellohellohellohellohellohellohellohellohel"
    "lohellohellohellohellohellohellohellohellohellohellohellohellohellohe"
    "llohellohellohellohellohellohellohellohellohellohellohellohellohelloh"
    "ellohellohellohellohellohellohellohellohellohellohellohellohellohello"
    "hellohellohellohellohellohellohellohellohellohellohellohellohellohell"
    "ohellohellohellohellohellohellohellohellohellohellohellohellohellohel"
    "lohellohellohellohellohellohellohellohellohellohellohellohellohellohe"
    "llohellohellohellohellohellohellohellohellohellohellohellohellohelloh"
    "ellohellohellohellohellohellohellohellohellohellohell"
    "ohellohellohellohellohellohellohellohellohellohellohellohellohellohel"
    "lohellohellohellohellohellohellohellohellohellohellohellohellohellohe"
    "llohellohellohellohellohellohellohellohellohellohellohellohellohelloh"
    "ellohellohellohellohellohellohellohellohellohellohellohellohellohello"
    "hellohellohellohellohellohellohellohellohellohellohellohellohellohell"
    "ohellohellohellohellohellohellohellohellohellohellohellohellohellohel"
    "lohellohellohellohellohellohellohellohellohellohellohellohellohellohe"
    "llohellohellohellohellohellohellohellohellohellohellohellohellohelloh"
    "ellohellohellohellohellohellohellohellohellohellohell"
    "ohellohellohellohellohellohellohellohellohellohellohellohellohellohel"
    "lohellohellohellohellohellohellohellohellohellohellohellohellohellohe"
    "llohellohellohellohellohellohellohellohellohellohellohellohellohelloh"
    "ellohellohellohellohellohellohellohellohellohellohellohellohellohello"
    "hellohellohellohellohellohellohellohellohellohellohellohellohellohell"
    "ohellohellohellohellohellohellohellohellohellohellohellohellohellohel"
    "lohellohellohellohellohellohellohellohellohellohellohellohellohellohe"
    "llohellohellohellohellohellohellohellohellohellohello\n";

int
main (void)
{
  pa_setup();

  printf("hello\n");
  assert(1 == pa_match_stdout("hello\n"));

  printf(t1);
  assert(1 == pa_match_stdout(t1));

  fprintf(stderr, t1);
  assert(1 == pa_match_stderr(t1));

  // doesnt work
  // printf("\\//\\//");
  // pa_match_stdout("\\//\\//");

  printf("hello.txt");
  assert(1 == pa_match_stdout("*.txt"));

  printf("holt");
  assert(1 == pa_match_stdout("h**t"));

  fprintf(stderr, "123example");
  assert(1 == pa_match_stderr("[0-9]*"));

  // TODO: add negative test cases

  pa_teardown();

  printf("done\n");
}
