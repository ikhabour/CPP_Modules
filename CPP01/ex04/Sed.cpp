#include "Sed.hpp"

void    replace(std::string filename, std::string find, std::string replace)
{
    std::ifstream input;
    std::ofstream output;

    input.open(filename.data());

    if (!input.is_open())
    {
        std::cerr<<"Error opening file"<<std::endl;
        return ;
    }
    output.open((filename + ".replace").data());
    if (!output.is_open())
    {
        std::cerr<<"Error opening file"<<std::endl;
        return ;
    }
    std::string file_content;
    if (std::getline(input, file_content, '\0'))
    {
        size_t pos = file_content.find(find);
        while (pos != std::string::npos && !find.empty())
        {
            file_content.erase(pos, find.length());
            file_content.insert(pos, replace);
            pos = file_content.find(find, pos + find.length());
        }
        output<<file_content;
    }
    else
    {
        std::cerr<<"File is empty."<<std::endl;
        return ;
    }
    input.close();
    output.close();
}