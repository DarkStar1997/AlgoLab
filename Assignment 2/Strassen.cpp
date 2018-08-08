#include <iostream>
#include <vector>
#include <tuple>
template<typename T>
struct Mat
{
    std::vector<std::vector<T>> data;
    Mat(int rows, int cols)
    {
        data = std::vector<std::vector<T>>(rows, std::vector<T>(cols));
    }
    Mat(int rows, int cols, int val)
    {
        data = std::vector<std::vector<T>>(rows, std::vector<T>(cols, val));
    }
    Mat<T> merge(const Mat<T> &a, const Mat<T> &b, const Mat<T> &c, const Mat<T> &d)
    {
        int n = a.data.size()*2;
        Mat<T> res(n, n, T(0));
        
        for(int i = 0, x = 0; i < n/2; i++, x++)
            for(int j = 0, y = 0; j < n/2; j++, y++)
                res.data[i][j] = a.data[x][y];

        for(int i = 0, x = 0; i < n/2; i++, x++)
            for(int j = n/2, y = 0; j < n; j++, y++)
                res.data[i][j] = b.data[x][y];
        
        for(int i = n/2, x = 0; i < n; i++, x++)
            for(int j = 0, y = 0; j < n/2; j++, y++)
                res.data[i][j] = c.data[x][y];
        
        for(int i = n/2, x = 0; i < n; i++, x++)
            for(int j = n/2, y = 0; j < n; j++, y++)
                res.data[i][j] = d.data[x][y];

        return res;
    }
    std::tuple<Mat<T>, Mat<T>, Mat<T>, Mat<T>> slice(const Mat<T> &mat)
    {
        int n = mat.data.size();
        Mat<T> ans1(n/2, n/2);
        Mat<T> ans2(n/2, n/2);
        Mat<T> ans3(n/2, n/2);
        Mat<T> ans4(n/2, n/2);
        
        for(int i = 0; i < n/2; i++)
		    for(int j = 0; j < n/2; j++)
			    ans1.data[i][j] = mat.data[i][j];

        for(int i = 0, x = 0; i < n/2; i++, x++)
		    for(int j = n/2, y = 0; j < n; j++, y++)
			    ans2.data[x][y] = mat.data[i][j];

        for(int i = n/2, x = 0; i < n; i++, x++)
            for(int j = 0, y = 0; j < n/2; j++, y++)
                ans3.data[x][y] = mat.data[i][j];

        for(int i = n/2, x = 0; i < n; i++, x++)
            for(int j = n/2, y = 0; j < n; j++, y++)
                ans4.data[x][y] = mat.data[i][j];

        return std::make_tuple(ans1, ans2, ans3, ans4);
    }
    Mat<T> operator-(const Mat<T>& b)
    { 
        Mat<T> c(b.data.size(), b.data.size());
        for(int i=0;i<b.data.size();i++)
            for(int j=0;j<b.data.size();j++)
                c.data[i][j]=data[i][j]-b.data[i][j];
        return c;
    }
    Mat<T> operator+(const Mat<T>& b)
    { 
        Mat<T> c(b.data.size(), b.data.size());
        for(int i=0;i<b.data.size();i++)
            for(int j=0;j<b.data.size();j++)
                c.data[i][j]=data[i][j]+b.data[i][j];
        return c;
    }
    Mat<T> operator*(Mat<T> Y)
    {
        Mat<T> X = *this;
        int n = X.data.size();
        if(n == 2)
        {
            Mat<T> bound(2, 2);
            bound.data[0][0] = (X.data[0][0] * Y.data[0][0]) + (X.data[0][1] * Y.data[1][0]);
            bound.data[0][1] = (X.data[0][0] * Y.data[0][1]) + (X.data[0][1] * Y.data[1][1]);
            bound.data[1][0] = (X.data[1][0] * Y.data[0][0]) + (X.data[1][1] * Y.data[1][0]);
            bound.data[1][1] = (X.data[1][0] * Y.data[0][1]) + (X.data[1][1] * Y.data[1][1]);
            return bound;
        }
        if(n % 2 == 1)
        {
            for(int i=0;i<X.data.size();i++)
            {
                X.data[i].push_back(T(0));
                Y.data[i].push_back(T(0));
            }
            X.data.push_back(std::vector<T>(X.data.size(),T(0)));
            Y.data.push_back(std::vector<T>(Y.data.size(),T(0)));
            Y.data[Y.data.size()-1][Y.data.size()-1]=T(1);
            X.data[X.data.size()-1][X.data.size()-1]=T(1);
        }
        auto [A, B, C, D] = slice(X);
        auto [E, F, G, H] = slice(Y);
        auto P1 = A * (F-H);
        auto P2 = (A+B) * H;
        auto P3 = (C+D) * E;
        auto P4 = D * (G-E);
        auto P5 = (A+D) * (E+H);
        auto P6 = (B-D) * (G+H);
        auto P7 = (A-C) * (E+F);

        auto temp = merge((P6+P5)+(P4-P2), P1+P2, P3+P4, (P1+P5)-(P3+P7));
        if(n%2==1)
        {
            temp.data.pop_back();
            for(auto& i: temp.data)
                i.pop_back();
        }
        return temp;
    }
};
int main()
{
    int n; std::cout<<"Enter n\n";
    std::cin>>n;
    Mat<int> mtx1(n, n), mtx2(n, n);
    std::cout<<"Enter the 1st matrix:\n";
    for(auto& i : mtx1.data)
        for(auto& j : i)
            std::cin>>j;
    std::cout<<"Enter the 2nd matrix:\n";
    for(auto& i : mtx2.data)
        for(auto& j : i)
            std::cin>>j;
    std::cout<<"The resultant matrix:\n";
	auto res = mtx1 * mtx2;
	for(auto& i : res.data)
	{
		for(auto& j : i)
			std::cout<<j<<", ";
		std::cout<<"\n";
	}
	std::cout<<std::endl;
	return 0;
}