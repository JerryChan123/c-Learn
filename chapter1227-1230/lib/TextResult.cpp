#include"TextResult.hpp"

ostream& print(ostream& stream,TextResult re)  {
        stream << re.sought << " occurs " << re.lines->size()
        << (re.lines->size() > 1 ? " times" : " time") << std::endl;
    if(re.lines->size()>0){
        stream<<"word in lines is:";
        for(auto begin=re.lines->cbegin();begin!=re.lines->cend();begin++){
            stream<<*begin<<",";
        }
        stream<<endl;
    }else{
        stream << "no word lines"<<endl;
    }
    return stream;
}
