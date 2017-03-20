//Problem 6.1: Format a Table

#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include "format_numbers.hpp"


std::vector<int> vec_to_int(std::vector<double> v);
std::vector<double> vec_rounded(std::vector<double> v);
std::string double_to_string(double x);
std::vector<std::string> format_numbers(std::vector<double> v);
void print_vec(std::vector<int> v);
void print_vec(std::vector<double> v);
void print_vec(std::vector<std::string> v);


int main()
{
    std::vector<double> vdouble = {1.234,7.123,3.630,2.325,4.527};
    print_vec(vec_to_int(vdouble));
    print_vec(vec_rounded(vdouble));
    std::cout << double_to_string(223452.234523) << std::endl;
    std::cout << double_to_string(-223452.234523) << std::endl;
    std::cout << double_to_string(-2223452.234523) << std::endl;
    std::cout << double_to_string(-22233452.234523) << std::endl;
    std::cout << double_to_string(2352) << std::endl;
    std::cout << double_to_string(-2352) << std::endl;
    std::cout << double_to_string(-252.4) << std::endl;
    print_vec(format_numbers(numbers));
    return 0;
}


std::vector<int> vec_to_int(std::vector<double> v)
{
    std::vector<int> result(v.size(), 0); //Initialize return vector with Zeros
    std::transform(v.begin(), v.end(), result.begin(), [](double x){return std::round(x);}); //round with lambda expression in transform function
    return result;
}

std::vector<double> vec_rounded(std::vector<double> v)
{
    std::vector<double> result(v.size(), 0);
    std::transform(v.begin(), v.end(), result.begin(), [](double x){return std::round(x*100)/100;});
    return result;
}

std::string double_to_string(double x)
{

    std::string number = std::to_string((int)(std::round(x*100)));
    std::string result;
    if(x<0) number = number.substr(1, number.size()-1);
    int s=0; //s counts for the number string
    int i=0; //i counts for the result string
    //put all characters together, in reverse order

    if(number.size()==0)
    {
        number = "000" + number;
    }

    if(number.size()==1)
    {
        number = "00" + number;
    }

    if(number.size()==2)
    {
        number = '0' + number;
    }

    while(number[s]!='\0')
    {
        if(i == 2)
        {
            result+='.';
            i++;
            continue;
        }

        if((i==6 &&number.size()>4) || (i==10 && number.size()>8) || (i==13&&number.size()>11))
        {
            result += "'";
            i++;
            continue;
        }

        result += number[number.size()-1-s];
        s++;
        i++;
    }

    if(x<0)
    {
        result+='-';
        i++;
    }

    while(i<16)
    {
        result += ' ';
        i++;
    }

    std::string result2;
    for(int n = result.size(); n>=0; n--)
    {
        result2 += result[n];
    }

    return result2;
}

std::vector<std::string> format_numbers(std::vector<double> v)
{
    std::vector<std::string> result(v.size(), "");
    std::transform(v.begin(), v.end(), result.begin(), [](double x){return double_to_string(x);});
    return result;
}

void print_vec(std::vector<int> v)
{
    for(int i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
    std::cout << std::endl;
}

void print_vec(std::vector<double> v)
{
    for(int i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
    std::cout << std::endl;
}

void print_vec(std::vector<std::string> v)
{
    for(int i = 0; i< v.size(); ++i)
    {
        std::cout << v[i] << std::endl;
    }
}
