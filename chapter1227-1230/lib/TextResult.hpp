#ifndef TEXTRESULT_H_
#define TEXTRESULT_H_ 
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include <set>
using namespace std;
class TextResult{
friend ostream& print(ostream&,const TextResult re);
private:
    string sought;
    using line_no=vector<string>::size_type;
    shared_ptr<vector<string>> file;
    shared_ptr<set<line_no>> lines;
public:
    TextResult(string s,shared_ptr<set<line_no>> p,
            shared_ptr<vector<string>> f):sought(s),file(f),lines(p){
    
    }
    //void print();

};

#endif
