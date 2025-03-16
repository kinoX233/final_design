#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

// 将输入的语句切分为token，并转化为词汇表序号
#define MAX_TOKEN_NUM 128
#define UNKNOW 6000

class tokenizer
{
private:
    std::vector<std::string> tokens;
    std::string token;
    
    std::map<std::string,int> vocabulary;

    int token_num;

public:
    tokenizer(/* args */);
    void split(std::string &input);
    std::vector<int> token_idx;
};

tokenizer::tokenizer(/* args */)
{
    token_num=0;
}
//!可能需要析构函数

void tokenizer::split(std::string &input)
{
    for (char ch : input)
    {
        if (isspace(ch) or ispunct(ch))
        {
            if (not token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(std::string(1, ch));
            token_num++;
        }
        else
        {
            token += ch;
        }
    }

    if (not token.empty())
    {
        tokens.push_back(token);
        token_num++;
        token.clear();
    }

    
    //read vocabulary
    std::ifstream file("./vocabulary.txt");
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << std::endl;
    }

    std::string word;
    int idx=3;
    while(std::getline(file,word)){
        vocabulary[word]=idx;
        idx++;
    }
    file.close();

    vocabulary["sos"]=0;
    vocabulary["eos"]=1;

    //find idx in vocabulary
    for(auto tok : tokens){
        auto idx_iter=vocabulary.find(tok);
        if(idx_iter != vocabulary.end()){
            token_idx.push_back(idx_iter->second);
        }
        else{
            token_idx.push_back(UNKNOW);
        }
    }
}