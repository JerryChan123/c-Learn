//1.21
#include <iostream> //头文件的概念
#include "Sales_item.hpp"
using namespace std;
int main(){
    
    cout<<"start"<<endl;
    Sales_item item1,item2;
    cin>>item1>>item2;
    cout<<item2+item1<<endl;
    return 0;
}
//3.6 修改string对象字符，每个位置替换成对应字符
int main(){
    string str="asnkaduqe";
    //试用下标方式
    for (string::size_type i=0;i<str.length();i++) {
        str[i]='X';
    }
    //使用迭代器
    for (auto begin=str.begin(); begin!=str
         .end(); begin++) {
        *begin='kk';
    }
    cout<<str<<endl;
    return 0;
}
//6.21
int compareNum(int a,int* b){
    if(a>*b){
        return a;
    }
    return *b;
}
//6.22
void changePointer(int *a,int *b){
    int* temp=a;
    a=b;
    b=temp;
    cout<<*a<<*b<<endl;
}
//6.33
void printVct(vector<int> &k,vector<int>::size_type size){
    if (size!=0) {
        cout<<k[k.size()-size]<<" ";
        printVct(k, --size);
    }
}
//6.36
//type *(func(parameter_list))[dimension]
//不要返回一个局部变量的指针或引用，如果要返回，需要使用new的方式，所以下面的方式是错的
int (*func(int a))[4]{
    int an[4]={1,2,34,4};
    return &an;
}

//12.2 编写自己的StrBlob类，包含const版本的front和back  
//StrBlob.h
#ifndef StrBlob_hpp
#define StrBlob_hpp
#include <vector>
#include <stdio.h>
#include <iostream>
#include <memory>
using namespace std;
class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> li);
    size_type size() const{
        return data->size();
    }
    int getRefCount() const{
        return data.use_count();
    }
    bool empty() const{
        
        return data->empty();
    }
    void push_back(const std::string& str);
    void pop_back();
    string& front();
    string& back();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type sizetye,const std::string &str) const{
        if(sizetye>=data->size()){
            throw out_of_range(str);
        }
    }
};
#endif /* StrBlob_hpp */

//StrBlob.cpp
#include "StrBlob.hpp"

StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>>()){
    
}
StrBlob::StrBlob(initializer_list<string> li):data(make_shared<vector<string>>(li)){
    
}
void StrBlob::push_back(const std::string &str){
    check(0, "push back on empty");
    data->push_back(str);
}
void StrBlob::pop_back(){
    check(0, "pop_back on empty");
    data->pop_back();
}
string& StrBlob::front(){
    check(0, "front on empty");
    return data->front();
}

string& StrBlob::back(){
    check(0, "back on empty");
    return data->back();
}
//12.5我们未编写一个接受一个initializer_list explicit参数的构造函数，讨论这个设计
//策略的优点和缺点
C++提供了关键字explicit，可以阻止不应该允许的经过转换构造函数进行的隐式转换的发生,声明为explicit的构造函数不能在隐式转换中使用。


//12.6 编写函数，返回一个动态分配int的vector，将此vector传递给另一个函数
//这个函数读取标准输入，读的值保存在vector里面，再通过另外一个函数打印出来。
vector<string> * getVec(){
    vector<string>* vec=new vector<string>;
    return vec;
}

void input(vector<string>* vec){
    vec->push_back("aaaa");
    vec->push_back("nbbb");
}

void output(vector<string>* vec){
    vector<string> test=*vec;
    for(auto i=test.cbegin();i!=test.cend();i++){
        cout<<*i<<endl;
    }
}
int main(int argc, const char * argv[]) {
    vector<string> *vec=getVec();
    input(vec);
    
    output(vec);
    delete vec;
    return 0;
}

//12.9
//解释如下代码执行结果
void check(){
    int *q=new int[42];
    int* r=new int[100];
    r=q;//没有指针指向原来r所指的内存，所以没有能够释放，调用deletd[] r之后,int[42]数组内存释放
    auto q2=make_shared<int>(42);
    auto r2=make_shared<int>(100);
    r2=q2;//r2的智能指针引用次数减一，q2的智能指针引用加一
}


