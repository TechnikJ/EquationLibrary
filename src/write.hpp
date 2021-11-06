#ifndef __EQ_WRITE_
#define __EQ_WRITE_

#include<string>
#include "../vendor/JSON/json.hpp"
#include<fstream>
#include<iostream>

namespace EQ{
    class Write{

        public:
            static void createNewEntry(std::string t_category, std::string t_json);
            static void createNewCategory(std::string t_parentCategory,std::string t_categoryName);
        private:
            static void splitString(std::string t_inputString, std::vector<std::string> &t_outputVector, char t_splitArg);
    };
}

#endif