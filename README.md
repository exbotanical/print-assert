# print-assert

Assertion primitives for matching on stdout and stderr output.

```c
#include <print_assert.h>

int
main (void)
{
  pa_setup();

  printf("hello\n");
  pa_expect_stdout("hello\n");

  printf("hello.txt");
  pa_expect_stdout("*.txt");

  printf("holt");
  pa_expect_stdout("h**t");

  fprintf(stderr, "123example");
  pa_expect_stderr("[0-9]*");

  pa_teardown();
}

```
