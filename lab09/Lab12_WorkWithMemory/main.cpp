#include <iostream>
#include <string>
#include "StackOnList.h"
#include "StackOnArray.h"
#include "evaluate.h"
#include "calculator.h"


//#define _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
//#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING


#include "spdlog/spdlog.h"
//#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
//#include "spdlog/sinks/rotating_file_sink.h"

//#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
//// уровни логирования
    //critical - FATAL;
    //error - ERROR; 
    //warn - WARN;
    //info - INFO;
    //debug - DEBUG;
    //trace - TRACE;

using std::move;
using std::string;
using std::cin;
using std::cout;

int main()
{
    spdlog::set_level(spdlog::level::debug); // настройка уровня вхождения
    
    spdlog::set_pattern("[%Y:%m:%d] [%H:%M:%S] [%n] [%^---%L---%$] %v");
    try
    {
        auto logger = spdlog::basic_logger_mt("main", "logs/basic-log.txt"); 
        logger->info("Application started");
        string formula;
        cout << "Please, enter your formula:\n";
        cin >> formula;
        
       // cout << evaluate(formula) << '\n';
        cout << "Postfix note: \n";
        cout << makePostfix(formula) << '\n';
        cout << "The result is: ";
        cout << calculate(formula);

        logger->info("Aplication finished");
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cerr << "Log init failed: " << ex.what() << std::endl;
        spdlog::critical("Log init failed");
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
    }

	return 0;
}


//spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

/*
spdlog::critical("critical Apication started");
    spdlog::error("error Application started");
    spdlog::warn("warn Application started");
    spdlog::info("info Application started");
    spdlog::debug("debug Application started");
    spdlog::trace("trace Application started");

    printf("Number is %9.5f", 65.45);*/