#include <string>
#include <vector>
#include <iostream>
size_t getMax(std::vector<std::string> &arr, int n)
{
    size_t max = arr[0].size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i].size()>max)
            max = arr[i].size();
    }
    return max;
}

void countSort(std::vector<std::string> &a, int size, size_t k)
{
    std::vector<std::string> b(size);
    std::vector<int> c(257, 0);

    for (int j = 0; j <size; j++)
        c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;

    for (int f = 1; f <257; f++)
        c[f] += c[f - 1];

    for (int r = size - 1; r >= 0; r--){
        b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
        c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
    }

    for (int l = 0; l < size; l++){
        a[l] = b[l];
    }
}


void radixSort(std::vector<std::string> &b, int r)
{
    size_t max = getMax(b, r);
    for (size_t digit = max; digit > 0; digit--)
        countSort(b, r, digit - 1);
}

int main() 
{
    int n; std::cin>>n;
    std::vector<std::string> data(n);
    for(auto& i : data)
        std::cin>>i;
    radixSort(data, n);
    for(auto& i : data)
        std::cout<<i<<'\n';
    return 0;
}