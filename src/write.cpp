#include "write.hpp"

using json = nlohmann::basic_json<>;

void EQ::Write::createNewEntry(std::string t_category,std::string t_json){
    std::string m_physics_file = "physic.json";
    std::ifstream m_ifs(m_physics_file);
    json m_jf = json::parse(m_ifs);

    int m_count = std::count(t_category.begin(),t_category.end(), '.');

    std::vector<std::string> m_category;
    EQ::Write::splitString(t_category, m_category,'.');
    std::string m_jsonTemplate="{";

    json m_tmpJson=m_jf;
    for(int i = 0;i<=m_count;i++){
        m_tmpJson=m_tmpJson[m_category[i]];
    }
    int m_size = m_tmpJson.size();

    for(int i = 0; i < m_category.size();i++){
        m_jsonTemplate=m_jsonTemplate+"\""+m_category[i]+"\":{";
    }
    m_jsonTemplate= m_jsonTemplate+"\""+std::to_string(m_size)+"\":"+t_json;
    for(int i = 0; i < m_category.size()+1;i++){
        m_jsonTemplate=m_jsonTemplate+"}";
    }

    json m_newJson = json::parse(m_jsonTemplate);
    m_jf.merge_patch(m_newJson);

    std::ofstream m_ofs(m_physics_file);
    m_ofs << m_jf;

}

void EQ::Write::createNewCategory(std::string t_parentCategory,std::string t_categoryName){
    std::string m_physics_file = "physic.json";
    std::ifstream m_ifs(m_physics_file);
    json m_jf = json::parse(m_ifs);

    std::vector<std::string> m_parentCategory;

    EQ::Write::splitString(t_parentCategory, m_parentCategory,'.');

    std::string m_jsonTemplate="{";

    for(int i = 0; i < m_parentCategory.size();i++){
        m_jsonTemplate=m_jsonTemplate+"\""+m_parentCategory[i]+"\":{";
    }

    m_jsonTemplate=m_jsonTemplate+"\""+t_categoryName+"\":{}";

    for(int i = 0; i < m_parentCategory.size()+1;i++){
        m_jsonTemplate=m_jsonTemplate+"}";
    }

    json m_newJson = json::parse(m_jsonTemplate);

    m_jf.merge_patch(m_newJson);

    std::ofstream m_ofs(m_physics_file);
    m_ofs << m_jf;

}

void EQ::Write::splitString(std::string t_inputString, std::vector<std::string> &t_outputVector, char t_splitArg){
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