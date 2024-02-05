
#include <spdlog/spdlog.h>
#include "Parser.h"

using namespace std;

int main()
{
	Parser p;
	p.parseData("input.txt", 1);
	return 0;
}