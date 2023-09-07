## Materiales adicionales para Arquitectura de Computadores

<html>
<ul>
<li> License <a href="http:/creativecommons.org/licenses/by-nc/4.0/">CC BY-NC 4.0</a> </li>
<li> Curso 2023-2024</li>
<li> Alejandro Calderón Mateos </li>
</ul>
</html>


## Viajando de C a C++

### Significado de '\*' y '&' según el contexto

<html>
La siguiente tabla resume los 4 significados habituales con los que trabajar:
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
                definición de variable
		</td>
		<td>
                <span class="border border-secondary">puntero a...</span>
<pre>
 int b = 3 ;
 int *p_int = &b ; // p_int es puntero a entero, 
                   // y guarda la dirección de 'b'
</pre>
		</td>
		<td>
                <span class="border border-secondary">referencia a... (solo C++)</span>
<pre>
 int a = 3 ;
 int &r_int = a ; // r_int=5 hace lo que a=5
                  // al crear la referencia se le indica a quien se asocia
</pre>
		</td>
	</tr>
	<tr>
		<td>
                uso de variable
		</td>
		<td>
                <span class="border border-secondary">accede a...</span>
<pre>
 *p_int = 3 ; // accede a p_int y guarda allí un tres
</pre>

		</td>
		<td>
                <span class="border border-secondary">dirección de...</span>
<pre>
 int b = 3 ;
 int *p_int = &b ; // &b es la dirección de b
</pre>
		</td>
	</tr>
	</tbody>
</table>
</div>
</html>



La referencia se utiliza en C++ para paso de parámetro por referencia, evitando el mecanismo usado en C: usar un puntero:
<html>
<div class="table-responsive">
<table class="table table-bordered table-hover">
	<thead>
	<tr>
		<td class="col-auto">
C con punteros
		</td>
		<td class="col-auto">
C++ con referencias
		</td>
	</tr>
	</thead>
	<tbody>
	<tr>
		<td>
<pre>
    int main ( void )
    {
        int i = 3;
        ...
        inc(&i) ;
                   // i vale 4
    }

    void inc ( int * j)
    {
        *j = *j + 1;
    }
</pre>
		</td>
		<td>
<pre>
    int main ( void )
    {
        int i = 3;
        ...
        inc(i) ;
                   // i vale 4
    }

    void inc ( int & j)
    {
        j = j + 1;
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
   https://codingnest.com/the-little-things-the-missing-performance-in-std-vector/
   Agraceder este enlace a Javier López Gómez


