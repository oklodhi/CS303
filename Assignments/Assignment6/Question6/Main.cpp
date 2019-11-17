
#include "Huffman_Tree.h"
#include <iostream>
#include <string>


int main()
{
	Huff_Data<std::string>one(2, "Mary");
	Huff_Data<std::string>two(2, "had");
	Huff_Data<std::string>three(2, "a");
	Huff_Data<std::string>four(4, "little");
	Huff_Data<std::string>five(4, "lamb");
	Huff_Data<std::string>six(1, "the");
	Huff_Data<std::string>seven(1, "fleece");
	Huff_Data<std::string>eight(1, "was");
	Huff_Data<std::string>nine(1, "white");
	Huff_Data<std::string>ten(1, "as");
	Huff_Data<std::string>eleven(1, "snow");

	
	
	std::ostringstream code;
	std::vector<Huff_Data<std::string>> huff_Data = {one, two, three, four, five, six, seven, eight, nine, ten, eleven};
	Huffman_Tree<std::string> huff_tree;
	huff_tree.build_tree(huff_Data);
	huff_tree.print_code(code);
	std::string result = code.str();
	std::cout << result << std::endl << std::endl;

	result = huff_tree.decode("1010");
	std::cout << result << std::endl;
	
	result = huff_tree.decode("0101");
	std::cout << result << std::endl;

	result = huff_tree.decode("111");
	std::cout << result << std::endl;

	return 0;
}
