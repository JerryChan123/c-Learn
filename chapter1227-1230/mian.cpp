#include <iostream>
#include <sstream>
#include <fstream>
#include "lib/TextQuery.hpp"
#include "lib/TextResult.hpp"
void runQueries(std::ifstream& infile)
{
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}
void testStream(string fileName){
    ifstream file(fileName);
    if(!file){
        cout<<"error read file"<<endl;
        return;
    }
   string text;
   cout<<"start read"<<endl;
   while(getline(file,text)){
       cout<<"read::";
        cout<<text<<endl;
   }
}

int main(){
    string s;
    std::cout<<"input file"<<std::endl;
    cin>>s;
    //testStream(s);
    ifstream is(s);
    runQueries(is);
}
