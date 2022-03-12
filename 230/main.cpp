#include <bitset>
#include <iostream>
#include <sstream>

std::string BinaryStringToText(std::string binaryString) {
  std::string text = "";
  std::stringstream sstream(binaryString);
  while (sstream.good()) {
    std::bitset<8> bits;
    sstream >> bits;
    text += char(bits.to_ulong());
  }
  return text;
}

int main() {
  std::string binaryString =
      "010000110101010001000110011110110100001001101001011101000101111101000110"
      "01101100011010010111000001110000011010010110111001111101";

  std::cout << "Binary string: " << binaryString << "\n";
  std::cout << "Result binary string to text: "
            << BinaryStringToText(binaryString) << "\n";

  return 0;
}
