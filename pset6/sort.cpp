// Problem 6.2: Sort version numbers

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "sort_versions.hpp"


std::vector<int> split_version(std::string version);
bool version_less(std::string v1, std::string v2);


int main()
{
    //testrun
    /*
    std::vector<int> v = split_version("1.23.2.14");
    for(auto & element:v)
    {
        std::cout << element <<std::endl;
    }
    std::cout << version_less("1.2.0", "1.2.0.4") << std::endl;
    */

    //sort versions from file
    std::sort(versions.begin(), versions.end(), [](std::string a, std::string b){return version_less(a,b);});
    //print sorted versions to screen
    for(auto & element:versions)
    {
        std::cout << element <<std::endl;
    }
    return 0;
}


std::vector<int> split_version(std::string version)
{
    std::vector<int> result;
    int index = 0;
    int pindex = 0;
    while(version.size()>0)
    {
        if(version.find('.') != std::string::npos)
        {
            pindex = version.find('.');
            result.push_back(std::atoi((version.substr(index, (pindex-index))).c_str()));
            version = version.substr(pindex+1);
        }
        else
        {
            pindex = version.size();
            result.push_back(std::atoi((version.substr(index)).c_str()));
            break;
        }
    }
    return result;
}

bool version_less(std::string v1, std::string v2){
    std::vector<int> a, b;
    a = split_version(v1);
    b = split_version(v2);

    //fill the vectors with zeros to be of equal length
    if(a.size() < b.size())
    {
        for(int i=0, d=b.size()-a.size(); i<d; ++i)
        {
            a.push_back(0);
        }
    }
    if(a.size() > b.size())
    {
        for(int i=0, d=a.size()-b.size(); i<d; ++i)
        {
            b.push_back(0);
        }
    }

    //compare version numers and return true if a is less
    int i = 0;
    while(i < a.size())
    {
        if(a[i]<b[i]) return true;
        if(a[i]>b[i]) return false;
        else i++;
    }
    return false;
}
