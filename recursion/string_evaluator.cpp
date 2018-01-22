#include <iostream>
#include <stdlib.h>

using namespace std;

int eval(const char *a, int& i);

int main (int argc, char* argv[])
{

  string test("* + 7 * * 4 6 + 8 9 5");
  const char *test_a = test.c_str();
  int start_index =0;
  cout << eval(test_a,start_index) << endl;

  return 0;
}

int eval(const char *a, int& i){
  int x = 0;
  while (a[i] == ' ') {
    i++;
  }
  if (a[i] == '+'){
    i++;
    return eval(a,i) + eval(a,i);
  }
  if (a[i] == '*'){
    i++;
    return eval(a,i) * eval(a,i);
  }
  while((a[i] >='0') && (a[i] <='9')){
    x = (10 * x) + (a[i++]-'0');
  }
  return x;
}