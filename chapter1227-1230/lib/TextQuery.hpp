#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_ 
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <memory>
#include <fstream>
#include <ctype.h>
#include <sstream>
#include <algorithm>
#include "TextResult.hpp"
using namespace std;
//class TextResult;
class TextQuery{
private:
   using line_no= vector<string>::size_type; 
   //vector<std::string> inputText;
   //ifstream *stream;
   //map<string,set<int>> textFromLine;
   shared_ptr<vector<string>> file;
   map<string,shared_ptr<set<line_no>>> wm;
public:
   TextQuery(ifstream &is):file(new vector<string>){
       string text;
       while(getline(is,text)){
           file->push_back(text);//保存文本
           int n=file->size()-1;
           istringstream line(text);
           string word;
           while(line>>word){
               //过滤标点符号
               word.erase(remove_if (word.begin(),word.end(), static_cast<int(*)(int)>(&ispunct) ), word.end());
                auto &lines=wm[word];
                cout<<word<<"  ";
                if(!lines){
                    lines.reset(new set<line_no>);
                }
                lines->insert(n);
                word.clear();
            }

       }
   }
   TextResult query(const string& text) const;
   void print();
};

#endif
