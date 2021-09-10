// differentiation integration and bisection CS 543.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h> 
using namespace std;

double derivative(int power, double coeff, long long val)
{
    
    if (power == 0)
    {
        return 0;
    }
    else
    {
        return coeff * power * pow(val, power - 1);
    }
}


double derivativeVal(double coeff[], int val, int size)
{
    double ans = 0;
    for (int i = 0; i < size; ++i)
    {
        ans += derivative(i, coeff[i], val);
    }
    return ans;
}



double integralTerm(int power, double coeff, int val1, int val2)
{
    
    return (double)(coeff / (power + 1)) * (pow(val2, power + 1) - pow(val1, power + 1));
}


double integralVal(double coeff[], int val1, int val2, int size)
{
    double ans = 0;
    for (int i = 0; i < size; ++i)
    {
        ans += integralTerm(i, coeff[i], val1, val2);
    }
    return ans;
}

double func(double coeff[], double a, int size)
{
    double ans = 0;
    for (int i = 0; i < size; ++i)
    {
        ans += (double)coeff[i] * pow(a, i);
    }
    return ans;
}


void bisection(double coeff[], double a, double b, int size)
{
    double EPSILON = 0.01;
    if (func(coeff, a, size) * func(coeff, b, size) >= 0)
    {
        cout << "You have not used the right values"<<endl;
        return;
    }

    double c = a;
    while ((b - a) >= EPSILON)
    {
       
        c = (a + b) / 2;

        
        if (func(coeff, c, size) == 0.0)
            break;

       
        else if (func(coeff, c, size) * func(coeff, a, size) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The value of the root is : " << c;
}


int main()
{
    
    int n;
    cout << "Enter the degree of the polynomial";
    cin >> n;
    n = n + 1;
   
    
    double* coeff = new double [n];
    cout << "Enter the coefficients starting from constant going to highest power:";
    for (int i = 0; i < n; ++i)
    {
        cin >> coeff[i];
    }

   
    while (true)
    {
        int choice;
        cout << "Enter your Choice- enter 4 to exit" << endl;
        cout << "1. Differentiate" << endl;
        cout << "2. Integrate" << endl;
        cout << "3. bisection" << endl;
        cin >> choice;
        cout << "You chose: " << choice << endl;
        switch (choice)
        {
        case 1: {
           
            int value;
            cout << "Enter the value of the point "<<endl; 
            cin >> value;
            cout << "The value of the derivative is: " << derivativeVal(coeff, value, n)<<endl;
            break;
        }
        case 2: {
            
            int value1, value2;
            cout << "Enter the values of the point "<<endl;
            cin >> value1 >> value2;
            cout << "The value of the derivative is :" << integralVal(coeff, value1, value2, n)<<endl;
            break;
        }
        case 3: {
           
            double val1, val2;
            cout << "Enter the values of the point "<<endl; 
            cin >> val1 >> val2;
            bisection(coeff, val1, val2, n);
            break;
        }
        case 4: return 0;
        }
    }
    delete[] coeff;
    return 0;
}