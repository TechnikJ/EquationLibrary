#include "read.hpp"

using json = nlohmann::basic_json<>;

void EQ::Read::getData(std::string &t_outputString, std::string t_inputFactor){
    std::string m_physics_file = "physic.json";
    std::ifstream m_ifs(m_physics_file);
    json m_jf = json::parse(m_ifs);

    int m_count = std::count(t_inputFactor.begin(),t_inputFactor.end(), '.');

    std::vector<std::string> m_category;
    EQ::Read::splitString(t_inputFactor, m_category,'.');
    std::string m_jsonTemplate="{";

    json m_tmpJson = m_jf;

    for(int i = 0;i<=m_count;i++){
        m_tmpJson=m_tmpJson[m_category[i]];
    }

    std::cout << m_tmpJson << std::endl;

}

void EQ::Read::searchFile(std::string &t_outputString, std::string t_searchInputJson){

    

}

void EQ::Read::splitString(std::string t_inputString, std::vector<std::string> &t_outputVector, char t_splitArg){
    std::string m_temp = "";
    for (int i = 0; i < t_inputString.length(); i++){
        if(t_inputString[i] == t_splitArg){
            t_outputVector.push_back(m_temp);
            m_temp="";
        }else{
            m_temp.push_back(t_inputString[i]);
        }
    }
    t_outputVector.push_back(m_temp);
    
}