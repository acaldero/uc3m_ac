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
	<tr VALIGN="TOP">
		<td class="col-auto">
&nbsp;
		</td>
		<td class="col-auto">
Constructor y destructor<br>
		</td>
		<td class="col-auto">
Constructor y destructor +<br>
constructor copia +<br>
operador =
		</td>
		<td class="col-auto">
Constructor y destructor + <br>
constructor copia + <br>
operador = + <br>
constructor movimiento +<br>
copia de movimiento
		</td>
	</tr>
</thead>
<tbody>
	<tr>
		<td class="col-auto">
Regla aconsejada
		</td>
		<td class="col-auto">
&nbsp;
		</td>
		<td class="col-auto">
<a href="https://en.wikipedia.org/wiki/Rule_of_three_%28C++_programming%29)">Seguir la "regla de tres"</a>
		</td>
		<td class="col-auto">
<a href="https://en.wikipedia.org/w/index.php?title=Rule_of_three_(C%2B%2B_programming)&redirect=yes">Seguir la "regla de cinco"</a>
		</td>
	</tr>
	
<tr VALIGN="TOP">
<td class="col-auto">
Definición de la clase
</td>
<td>
<pre>
// <a href="https://github.com/acaldero/uc3m_ac/blob/main/anotaciones/classes/class_string_v1.cpp">Código completo aquí</a>
class ClassString
{
  private:
    int str_len ;
    char *ptr ;
  public:
    ClassString ( )
    {
       // default constructor
       ...
    }
    ClassString ( const 
	          char * 
	          value )
    {
       // constructor with
       // one string argument 
       ...
    }
    ~ClassString ( )
    {
       // default constructor
       ...
    }
};
</pre>
</td>
<td>
<pre>
// <a href="https://github.com/acaldero/uc3m_ac/blob/main/anotaciones/classes/class_string_v2.cpp">Código completo aquí</a>
class ClassString
{
  private:
    int str_len ;
    char *ptr ;
  public:
    ClassString ( )
    {
       // default constructor
       ...
    }
    ClassString ( const 
	          char *
	          value )
    {
       // constructor with
       // one string argument 
       ...
    }
    ClassString ( const 
	          ClassString &
	          other )
    {
       // copy constructor
       ...
    }
    ClassString & 
    operator= ( const 
	        ClassString& 
	        other )
    {
       // copy assignment operator
       ...
    }
    ~ClassString ( )
    {
       // default constructor
       ...
    }
};
</pre>
</td>
<td>
<pre>
// <a href="https://github.com/acaldero/uc3m_ac/blob/main/anotaciones/classes/class_string_v3.cpp">Código completo aquí</a>
class ClassString
{
  private:
    int str_len ;
    char *ptr ;
  public:
    ClassString ( )
    {
       // default constructor
       ...
    }
    ClassString ( const 
	          char * 
	          value )
    {
       // constructor with
       // one string argument 
       ...
    }
    ClassString ( const 
	          ClassString &
	          other )
    {
       // copy constructor
       ...
    }
    ClassString & 
    operator= ( const
	        ClassString & 
	        other )
    {
       // copy assignment operator
       ...
    }
    ~ClassString ( )
    {
       // default constructor
       ...
    }
    ClassString ( ClassString && 
	          other )
    {
       // move constructor
       // ('steal' resources)
       ...
    }
    ClassString & 
    operator= ( ClassString && 
	        other )
    {
       // move assignment operator
       // ('steal' resources)
       ...
    }
};
</pre>
</td>
</tr>
<tr VALIGN="TOP">
<td class="col-auto">
Uso de la clase
</td>
<td>
<pre>
// <a href="https://github.com/acaldero/uc3m_ac/blob/main/anotaciones/classes/class_string_v1.cpp">Código completo aquí</a>
int main ( int argc, 
	   char *argv[] )
{

   // one-string constructor
   ClassString a("hola mundo") ;

   // copy constructor
   ClassString b = a ;

   // 
   //
   //

   //
   //

   //
   //
   //

   // return ok
   return 0 ; // destructor 
}
</pre>
</td>
<td>
<pre>
// <a href="https://github.com/acaldero/uc3m_ac/blob/main/anotaciones/classes/class_string_v2.cpp">Código completo aquí</a>
int main ( int argc, 
	   char *argv[] )
{

   // one-string constructor
   ClassString a("hola mundo") ;

   // copy constructor
   ClassString b = a ;

   // copy assignment operator
   ClassString c ;
   c = a ;

   //
   //

   // 
   //
   //

   // return ok
   return 0 ; // destructor 
}
</pre>
</td>
<td>
<pre>
// <a href="https://github.com/acaldero/uc3m_ac/blob/main/anotaciones/classes/class_string_v3.cpp">Código completo aquí</a>
int main ( int argc, 
	   char *argv[] )
{

   // one-string constructor
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
