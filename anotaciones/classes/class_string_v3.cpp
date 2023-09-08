
#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace std;


class ClassString
{
  private:
    int str_len ;
    char *ptr ;

  public:

    // Follow the "Rule of five":
    // https://en.wikipedia.org/wiki/Rule_of_three_%28C++_programming%29

    ClassString ( )
    {
       // default constructor
       cout << "ClassString, *default* constructor" << endl ;

       this->str_len = 0 ;
       this->ptr     = nullptr ;
    }

    ClassString ( const char * initial_value )
    {
       // constructor with 1 string argument 
       cout << "ClassString, *1 string* constructor" << endl ;

       this->str_len = 0 ;
       this->ptr     = nullptr ;

       if (initial_value != nullptr)
       {
           this->str_len = strlen(initial_value) ;
           this->ptr     = strdup(initial_value) ;
       }
    }

    ClassString ( const ClassString & other )
    {
       // copy constructor
       cout << "ClassString, *copy* constructor" << endl ;

       this->str_len = 0 ;
       this->ptr = nullptr ;

       if (other.ptr != nullptr)
       {
           this->str_len = other.str_len ;
           this->ptr     = strdup(other.ptr) ;
       }
    }

    ClassString & operator= ( const ClassString& other )
    {
       // copy assignment operator
       cout << "ClassString, *= operator*" << endl ;

       if (this->ptr != nullptr)
       {
           free(this->ptr) ;
           this->str_len = 0 ;
           this->ptr = nullptr ;
       }

       if (other.ptr != nullptr)
       {
           this->str_len = other.str_len ;
           this->ptr     = strdup(other.ptr) ;
       }

       return *this;
    }

    ~ClassString ( )
    {
       // default constructor
       cout << "ClassString, *destructor*" << endl ;
       if (this->ptr != nullptr)
	    cout << "value: " << this->ptr << endl ;
       else cout << "value: nullptr" << endl ;

       free(this->ptr) ;
       this->str_len = 0 ;
       this->ptr = nullptr ;
    }

    ClassString ( ClassString && other )
    {
       // move constructor
       cout << "ClassString, move *constructor*" << endl ;

       // 'steal' resources
       this->str_len = other.str_len ;
       this->ptr     = other.ptr ;
       other.str_len = 0 ;
       other.ptr     = nullptr ;
    }

    ClassString & operator= ( ClassString&& other )
    {
       // move assignment operator
       cout << "ClassString, move *assignment operator*" << endl ;

       // 'steal' resources
       this->str_len = other.str_len ;
       this->ptr     = other.ptr ;
       other.str_len = 0 ;
       other.ptr     = nullptr ;

       return *this ;
    }

};


int main ( int argc, char *argv[] )
{
   // 1-string constructor
   ClassString a("hola mundo") ;

   // copy constructor
   ClassString b = a ;

   // copy assignment operator
   ClassString c ;
   c = a ;

   // move constructor
   ClassString d = std::move(a) ;

   // move assignment operator
   ClassString e ;
   e = std::move(a) ;

   // return ok
   return 0 ;
}

