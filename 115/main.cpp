#include <iostream>

#define INPUT "41424354467B34354331315F31355F55353346554C7D"

unsigned char hexval(unsigned char c) {
  if ('0' <= c && c <= '9')
    return c - '0';
  else if ('a' <= c && c <= 'f')
    return c - 'a' + 10;
  else if ('A' <= c && c <= 'F')
    return c - 'A' + 10;
  else
    abort();
}

void hex2ascii(const std::string &in, std::string &out) {
  out.clear();
  out.reserve(in.length() / 2);
  for (std::string::const_iterator p = in.begin(); p != in.end(); p++) {
    unsigned char c = hexval(*p);
    p++;
    if (p == in.end())
      break;                   // incomplete last digit - should report error
    c = (c << 4) + hexval(*p); // + takes precedence over <<
    out.push_back(c);
  }
}

int main() {

  std::string out = "";
  hex2ascii(INPUT, out);
  std::cout << out << "\n";

  return 0;
};
