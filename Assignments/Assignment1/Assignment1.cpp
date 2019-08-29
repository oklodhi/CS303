#include <iostream>

int main() {

	for (int i = 0; i < 100; i += 10) {
		std::cout << "1. " << 100 * i + 10 << std::endl;
		std::cout << "2. " << 5 * i * i + 2 << std::endl << std::endl;
	}
}