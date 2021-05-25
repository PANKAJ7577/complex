#include<iostream>
using namespace std;
class complex
{
private :
    int a, b;
public :
    complex (int x, int y)                  // constructor for 2 arguments
    { a=x; b=y;}
    complex (int x)                         // constructor for 1 argument
    { a=x; b=0;}
    complex ()                              // constructor without any argument
    { a=0; b=0;}
    complex (complex &c)                    // copy constructor
    {
        a=c.a;
        b=c.b;
    }
    inline complex operator+(complex C)                   // overloading binary +
    {
        complex temp;
        temp.a=a+C.a;
        temp.b=b+C.b;
        return (temp);
    }
    inline complex operator-(complex C)                   // overloading binary -
    {
        complex temp;
        temp.a=a-C.a;
        temp.b=b-C.b;
        return (temp);
    }
    inline complex operator*(complex C)                   // overloading binary *
    {
        complex temp;
        temp.a=(a*C.a)-(b*C.b);
        temp.b=(b*C.a)+(a*C.b);
        return (temp);
    }
    // -complex operator/(complex C) still to be coded   // overloading binary /


    friend istream& operator>>(istream&, complex&);      // overloading >> as a friend of ISTREAM and complex
    friend ostream& operator<<(ostream&, complex);       // overloading << as a friend of OSTREAM and complex

};
istream& operator>>(istream& din, complex& C)
{
    din>>C.a>>C.b;
    return (din);
}
ostream& operator<<(ostream& dout, complex C)
{
    dout<<"\na = "<<C.a<<" b = "<<C.b<<endl;
    return (dout);
}

int main ()
{
    complex c1(3,4),c2(5,6),c3(9),c4;           //initializing to check all versions of constructor function
    cout<<c1<<c2<<c3;                           // overloading of COUT with cascading
    c4=c1*c2;                                   // multiplication of 2 complex numbers
    cout<<c4;
    cin>>c1>>c2;                                // overloading of CIN with cascading
    cout<<c1<<c2;
    return 0;
}
