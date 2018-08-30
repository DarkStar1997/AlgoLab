#include <iostream>
#include <vector>
#include <string>
void calc(const std::string &pat, int M, std::vector<int> &lps)
{
    int len = 0;
 
    lps[0] = 0;
 
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    std::cout<<"LPS:\n";
    for(const auto& i : lps)
    	std::cout<<i<<'\n';
}
void search(const std::string &pat, const std::string &txt)
{
    int M = pat.length();
    int N = txt.length();
    std::vector<int> lps(M);
 
    calc(pat, M, lps);
 
    int i = 0; 
    int j  = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
            std::cout<<"Found pattern at index "<<i-j<<'\n';
            j = lps[j-1];
        }
 
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}
 
int main()
{
    /*std::string txt = "ABABDABACDABABCABAB";
    std::string pat = "ABABCABAB";*/
    std::string txt, pat;
    std::cout<<"Enter the text and the pattern to be searched\n";
    std::cin>>txt>>pat;
    search(pat, txt);
    return 0;
}
