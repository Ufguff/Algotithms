#include <vector>
#include <iostream>
using namespace std;
    

class Polynomial
{
    vector<long double> coefficients; 
public:
    Polynomial();
    Polynomial(vector<long double> coef) : coefficients(coef) {}
    long double calc(long double x)
    {
        long double c = 1, answer = 0;
        for (int i = coefficients.size(); i >= 0; i--)
        {
            answer += (c * coefficients[i]);
            c *= x;

        }
        return answer;
    }
    Polynomial operator+(Polynomial a)
    {
        vector<long double> temp = coefficients;
        if (a.coefficients.size() > temp.size())
            temp.resize(a.coefficients.size());

        for (int i = 0; i < a.coefficients.size(); i++)
            temp[i] += a.coefficients[i];

        return Polynomial(temp);
    }
    Polynomial operator*(Polynomial a)
    {
        vector<long double> temp(coefficients.size() + a.coefficients.size() - 1);

        for (int i = 0; i < coefficients.size(); i++)
            for (int j = 0; j < a.coefficients.size(); j++)
                temp[i + j] += a.coefficients[j] * coefficients[i];

        return Polynomial(temp);
    }

};

int main(){
    cout << "Hello" << endl;
}