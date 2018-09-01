#include "TextQuery.hpp"
void TextQuery::print(){
}

TextResult TextQuery::query(const string& text) const {
    //in case nodata issue
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc=wm.find(text);
    if(loc==wm.end()){
        return TextResult(text,nodata,file);
    }else{
        return TextResult(text,loc->second,file);
    }

}

