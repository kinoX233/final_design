#include <vector>
#include <string>
#include <bitset>
#define VOC_LEN 6000
#define DWORD 128

// 依照token的序号经过嵌入层矩阵，将其变为向量
class embedding
{
private:
    int voc_len = VOC_LEN;
    int dword = DWORD;
    std::vector<std::vector<std::bitset<2>>> embed_w = std::vector<std::vector<std::bitset<2>>>(VOC_LEN,
                                                                                                std::vector<std::bitset<2>>(DWORD,
                                                                                                                             std::bitset<2>()));

public:
    embedding();
    ~embedding();
};

embedding::embedding()
{
    // std::vector<std::bitset<2>> temp(DWORD, std::bitset<2>("00"));
    // for (int i = 0; i < VOC_LEN; i++)
    // {
    //     embed_w.push_back(temp);
    // }
}

embedding::~embedding()
{
}
