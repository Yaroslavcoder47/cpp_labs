#include <iostream>
#include <vector>
#include "Task3.h"
#include "Task4.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"


using std::cin;
using std::cout;
using namespace std;


void FourthTask()
{
	uint16_t a1, a2, a3;
	uint16_t b1, b2, b3;
	uint16_t c1, c2, c3;
	/*cout << "Input a1, a2, a3: \n";
	cin >> a1 >> a2 >> a3;
	cout << "Input b1, b2, b3: \n";
	cin >> b1 >> b2 >> b3;*/
	a1 = 0xFFFF;
	a2 = 0xFFFF;
	a3 = 0xEFFF;

	b1 = 0x0001;
	b2 = 0x0000;
	b3 = 0x0000;
	__asm {
		mov ax, a1
		add ax, b1
		mov c1, ax

		mov ax, a2
		adc ax, b2
		mov c2, ax

		mov ax, a3
		adc ax, b3
		mov c3, ax
		
	}
	cout << hex << c3 << ':' << c2 << ':' << c1 << endl;
	cout << ((static_cast<long long>(c3) << 32) | (static_cast<long long>(c2) << 16) | c1);
}



int main()
{
	try {
		auto logger = spdlog::basic_logger_mt("Lab02_main", "Lab02Logger.txt");
		logger.get()->info("Start project");
		logger.get()->info("End project");
	}
	catch (const spdlog::spdlog_ex& ex) {
		std::cerr << "Log is failed: " << ex.what() << '\n';
	}
	return 0;
}
