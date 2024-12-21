#include <iostream>
#include <fstream>
#include <string>

bool is_argc_correct(int argc)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./ft_sed filename s1 s2" << std::endl;
        return (false);
    }
    return (true);
}

bool open_infile(std::ifstream &infile, std::string infile_name)
{
    infile.open(infile_name.c_str());
    if (!infile)
    {
        std::cerr << "Error: cannot open input file '" << infile_name << "'" << std::endl;
        return (false);
    }
    return (true);
}

bool open_outfile(std::ofstream &outfile, std::string outfile_name)
{
    outfile.open(outfile_name.c_str());
    if (!outfile)
    {
        std::cerr << "Error: cannot open output file '" << outfile_name << "'" << std::endl;
        return (false);
    }
    return (true);
}

void read_content(std::string &content, std::ifstream &infile)
{
    std::string line;

    while (std::getline(infile, line))
        content += line + "\n";
}

void replace_all(std::string &content, std::string s1, std::string s2)
{
    int i;

    i = content.find(s1);
    while (i != -1)
    {
        content.erase(i, s1.length());
        
        content.insert(i, s2);
        i += s2.length();
        i = content.find(s1, i);
    }
}

int main(int argc, char **argv)
{
    if (!is_argc_correct(argc))
        return (1);

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream infile;
    std::ofstream outfile;
    std::string   content;
    
    if (!open_infile(infile, filename))
        return (1);
    if (!open_outfile(outfile, filename + ".replace"))
        return (1);
    
    read_content(content, infile);
    infile.close();

    replace_all(content, s1, s2);
    
    outfile << content;
    outfile.close();
    
    return (0);
}
