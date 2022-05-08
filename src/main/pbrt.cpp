//
//  pbrt.cpp
//  pbrt
//
//  Created by Johan Solbakken on 06/05/2022.
//

#include <iostream>
#include <vector>
#include <string>

struct Options
{
    int nCores = 0;
    bool quickRender = false;
    bool quiet = false, verbose = false;
    bool openWindow = false;
    std::string imageFile = "";
};

void pbrtInit(const Options& opt)
{
}

void pbrtCleanup()
{
    
}

bool ParseFile(const std::string& file)
{
    return false;
}

int main(int argc, const char * argv[]) {
    Options options;
    std::vector<std::string> filenames;
    for (uint32_t i = 1; i < (uint32_t) argc; i++)
    {
        filenames.push_back(std::string(argv[i]));
    }

    pbrtInit(options);
    
    if (filenames.size() == 0)
    {
        ParseFile("-");
    } else {
        for (uint32_t i = 0; i < filenames.size(); i++)
        {
            if (!ParseFile(filenames[i]))
            {
                std::cout << "Could not open scene \"" << filenames[i].c_str() << '"' << std::endl;
                // Error("Could not open scene \"%s\"", filenames[i].c_str());
            }
        }
    }
    
    pbrtCleanup();
    
    return 0;
}
