#include <string>
#include <vector>
#include "vector.hpp"

int main(void)
{
	ft::vector<std::string> vec(10, "slt");
	std::vector<std::string> rvec(10, "bjr");
	std::cout << rvec[9] << std::endl;
	std::cout << vec[9] << std::endl;
	return (0);	
}
