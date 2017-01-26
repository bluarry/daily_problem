#include "person.h"
#include <iostream>
#include <string>
using std::string;
Person::Person()
{
    this->lname="";
    this->fname[0]='\0';
}

Person::Person(const string &ln, const char* fn)
{
    this->lname=ln;
    for(int i=0;fn[i]!='\0';i++)
        this->fname[i]=fn[i];
}
void Person::show() const
{
    for(int i=0;this->fname[i]!='\0';i++)
        std::cout << this->fname[i];
    std::cout << " ";
    std::cout << this->lname<< std::endl;
}
void Person::FormalShow() const
{
    std::cout << this->lname;
     std::cout << " ";
     for(int i=0;this->fname[i]!='\0';i++)
         std::cout << this->fname[i];
      std::cout << std::endl;
}
