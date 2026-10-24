#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

namespace logger {

inline void LOG(const char* ID, const char* log) {

    fs::path cache = ".cache";
    fs::path dir = cache / "ege";
    fs::path file = dir / "log.txt";

    if(!fs::exists(dir)) fs::create_directory(dir);

    std::ofstream stream(file, std::ios::app);

    if(!stream.is_open()) {
        std::cerr << "[LOGGER] " << "Cannot open LOG file: " << file.generic_string() << std::endl;
        return;
    }

    std::stringstream ss;
    ss << "[" << ID << "] " << log << std::endl;

    stream << ss.str();
    std::cerr << ss.str();

}

}


