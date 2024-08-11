#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING

#include <iostream>
#include "spdlog/spdlog.h"
//#include "AppZoo.h"
#include "Date.h"

using std::move;
int main() {
    int status = -1;
    try {
        // Например, 
        auto appLogLevel = spdlog::level::trace;
        // AppZoo app("logs/applog.txt", appLogLevel);
        //AppZoo app(appLogLevel);
        //status = app.run();
        spdlog::info("Start");
        Date date(2023, 12, 23);
        Date date1(move(date));
        std::cout << date1.toString();
        spdlog::info("End");
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::cerr << "Log init failed: " << ex.what() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what();
    }

    return status;
}



