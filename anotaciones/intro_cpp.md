## Materiales adicionales para Arquitectura de Computadores

<html>
<ul>
<li> License <a href="http:/creativecommons.org/licenses/by-nc/4.0/">CC BY-NC 4.0</a> </li>
<li> Curso 2023-2024</li>
<li> Alejandro Calderón Mateos </li>
</ul>
</html>


## Introducción a C++

### (A) Definición de una clase en C++

<html>
<div class="table-responsive">
<table class="table table-bordered table-hover">
	<thead>
	<tr>
		<td class="col-auto">
&nbsp;
		</td>
		<td class="col-auto">
Constructor + destructor
		</td>
		<td class="col-auto">
Constructor + destructor + constructor copia + operador =
		</td>
		<td class="col-auto">
Constructor + destructor + constructor copia + operador = + constructor movimiento + copia de movimiento
		</td>
	</tr>
	</thead>
	<tbody>
	<tr>
		<td class="col-auto">
Definición de la clase
		</td>
		<td>
<pre>
class ClassString
{
  private:
    int str_len ;
    char *ptr ;

  public:

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
};
</pre>
		</td>
		<td>
<pre>
class ClassString
{
  private:
    int str_len ;
    char *ptr ;

  public:

    // Follow the "Rule of three":
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
};
</pre>
		</td>
		<td>
<pre>
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
</pre>
		</td>
	</tr>
	<tr>
		<td class="col-auto">
Uso de la clase
		</td>
		<td>
<pre>
int main ( int argc, char *argv[] )
{
   ClassString a("hola mundo") ;

   ClassString b = a ;

   // return ok
   return 0 ; // destructor 
}
</pre>
		</td>
		<td>
<pre>
int main ( int argc, char *argv[] )
{
   ClassString a("hola mundo") ;

   // copy constructor
   ClassString b = a ;

   // copy assignment operator
   ClassString c ;
   c = a ;

   // return ok
   return 0 ; // destructor 
}
</pre>
		</td>
		<td>
<pre>
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
   return 0 ; // destructor 
}
</pre>
		</td>
	</tr>
	</tbody>
</table>
</div>
</html>


