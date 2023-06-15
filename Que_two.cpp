int func()
{
  return f();
}

int main()
{
  func();
}
/*
This programme crash because of inifinite recursion causing in the program, as when program run enough amount of time
stack used to store thr recursions usually fill up, and due to no space in stack, it overflows, and the program crashs.
*/