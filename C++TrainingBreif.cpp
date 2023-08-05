
#include <iostream>

using namespace std;



/************************** Enum Class **********************/
/*
enum class color1
{   
   RED,
   GREEN 
};
enum class color2
{   
   RED,
   GREEN 
};


*/
/************************** Namespace *********************/


/*
int x = 0;
void print()
{
    cout << " GLobal Scope " << x << endl;
}
namespace space1
{
    int x = 1;
    void print()
    {
          cout << "Space 1 Scope " << x << endl;
    }

    namespace nested
    {
        int x =10;
        void print()
        {
            cout << "Space nested Scope " << x << endl;
        }

        class spec
        {
            public:
                void print()
                {
                    cout << "Class " << x << endl;
                }

            private:
                int x = 20;

        };

    }
}
*/
/*******************************  Template ************************************************/


#define OFFSET 10


template < typename T1> 
T1 add(T1 x , T1 y)
{
    return x+y;
}

template < typename T1 , typename T2 , int offset> 
T2 add(T1 x , T2 y)
{
    return offset+x+y;
}


template <typename T1 ,typename T2>

class LED
{
    public:

    void printSizeOf()
    {
        cout << "size X = " << sizeof(x) << endl;
        cout << "size Y = " << sizeof(y) << endl;
    }
    private:
    T1 x = 4;
    T2 y = 10;

};


int main(void)
{
    /*
    color1 C1 = color1::GREEN;

    if(C1 == color1::GREEN)
    {
        cout << "Green" << endl;
    } 

    ****************************************************/

    /*
   space1::nested::spec obj;
   obj.print();
   space1::nested::print();

    *******************************************************/

  //  cout << add<int , float , OFFSET>(1,5.1) << endl;
    
    LED<char , int> obj;
    obj.printSizeOf();
    return 0;
}