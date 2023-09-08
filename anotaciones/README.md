## Materiales adicionales para Arquitectura de Computadores

<html>
<ul>
<li> License <a href="http:/creativecommons.org/licenses/by-nc/4.0/">CC BY-NC 4.0</a> </li>
<li> Curso 2023-2024</li>
<li> Alejandro Calderón Mateos </li>
</ul>
</html>


## Viajando de C a C++

### (A) Significado de '\*' y '&' según el contexto

La siguiente tabla resume los 4 significados habituales con los que trabajar:
<html>
<div class="table-responsive">
<table class="table table-bordered table-hover">
	<thead>
	<tr>
		<td class="col-auto">
                &nbsp;
		</td>
		<td class="col-auto">
                *
		</td>
		<td class="col-auto">
                &
		</td>
	</tr>
	</thead>
	<tbody>
	<tr>
		<td>
                Al definir una variable...
		</td>
		<td>
                <u><b>puntero a...</b></u><p></p>
		Ejemplo:<br>
<pre>
 int b = 3 ;
 int <b>*</b>p_int = &b ; // (*)
</pre>
(*) p_int es puntero a entero, y se guarda la dirección de la variable 'b'
		</td>
		<td>
                <u><b>referencia a... (solo C++)</b></u><p></p>
		Ejemplo:<br>
<pre>
 int b = 3 ;
 int <b>&</b>r_int = b ; // (*)
</pre>
(*) r_int es una referencia a la variable 'b', y r_int=5 hace lo que b=5.
		</td>
	</tr>
	<tr>
		<td>
                Al usar una variable...
		</td>
		<td>
                <u><b>accede a...</b></u><p></p>
		Ejemplo:<br>
<pre>
 int p_int = &b ;
 <b>*</b>p_int = 3 ; // (*)
</pre>
(*) accede a p_int y guarda allí un tres
		</td>
		<td>
                <u><b>dirección de...</b></u><p></p>
		Ejemplo:<br>
<pre>
 int b = 3 ;
 int *p_int = <b>&b</b> ; // (*)
</pre>
(*) &b es la dirección de la variable b
		</td>
	</tr>
	</tbody>
</table>
</div>
</html>

La referencia se utiliza en C++ para paso de parámetro por referencia, evitando el mecanismo usado en C: usar un puntero.


### (B) Paso de parámetros por referencia en C (con punteros) y en C++ (con referencias)

<html>
<div class="table-responsive">
<table class="table table-bordered table-hover">
	<thead>
	<tr>
		<td class="col-auto">
&nbsp;
		</td>
		<td class="col-auto">
C 
		</td>
		<td class="col-auto">
C++
		</td>
	</tr>
	</thead>
	<tbody>
	<tr>
		<td class="col-auto">
Paso de variable por referencia.
		</td>
		<td>
C con punteros<br>
Ejemplo:<p></p>
<pre>
    int main ( void )
    {
        int i = 3;
        ...
        inc(&i) ;
                   // (*)
    }

    void inc ( int * j )
    {
        *j = *j + 1;
    }
</pre>
(*) Tras llamar a 'inc', la variable i vale 4
		</td>
		<td>
C++ con referencias<br>
Ejemplo:<p></p>
<pre>
    int main ( void )
    {
        int i = 3;
        ...
        inc(i) ;
                   // (*)
    }

    void inc ( int & j )
    {
        j = j + 1;
    }
</pre>
(*) Tras llamar a 'inc', la variable i vale 4
		</td>
	</tr>
	<tr>
		<td class="col-auto">
Paso de variable por valor
		</td>
		<td>
En C todo se pasa por valor<br>
Ejemplo:<p></p>
<pre>
    int main ( void )
    {
        int i = 3;
        ...
        inc(i) ;
                   // (*)
    }

    void inc ( int j )
    {
        j = j + 1;
    }
</pre>
(*) Tras llamar a 'inc', la variable i vale 3.
    Al llamar a 'inc' se copia el valor en j y se incrementa la copia (no el original)
		</td>
		<td>
C++ igual que en C<br>
Ejemplo:<p></p>
<pre>
    int main ( void )
    {
        int i = 3;
        ...
        inc(i) ;
                   // (*)
    }

    void inc ( int j )
    {
        j = j + 1;
    }
</pre>
(*) Tras llamar a 'inc', la variable i vale 3.
    Al llamar a 'inc' se copia el valor en j y se incrementa la copia (no el original)
		</td>
	</tr>
   </tbody>
</table>
</div>
</html>


### (C) Definición de una clase en C++

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



## Lecturas recomendadas

 * The Little Things: The Missing Performance in std::vector:
   * https://codingnest.com/the-little-things-the-missing-performance-in-std-vector/
   * Agraceder este enlace a Javier López Gómez


