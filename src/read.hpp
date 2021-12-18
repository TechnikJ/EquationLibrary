#pragma once

#include <string>
#include "../vendor/JSON/json.hpp"
#include<fstream>
#include<iostream>

namespace EQ{
    class Read{
        public:
            static void getData(std::string &t_outputString, std::string t_inputFactor);
            static void searchFile(std::string &t_outputString, std::string t_searchInputJson);
        private:
            static void splitString(std::string t_inputString, std::vector<std::string> &t_outputVector, char t_splitArg);

    };
} 