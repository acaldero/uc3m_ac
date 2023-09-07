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
                al definir una variable
		</td>
		<td>
                <u><b>puntero a...</b></u><p></p>
		Ejemplo:<br>
<pre>
 int b = 3 ;
 int *p_int = &b ;
</pre>
p_int es puntero a entero, y guarda la dirección de 'b' <br>
		</td>
		<td>
                <u><b>referencia a... (solo C++)</b></u><p></p>
		Ejemplo:<br>
<pre>
 int a = 3 ;
 int &r_int = a ;
</pre>
r_int=5 hace lo que a=5 al crear la referencia se le indica a quien se asocia
		</td>
	</tr>
	<tr>
		<td>
                uso de variable
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


### Paso de parámetros por referencia en C (con punteros) y en C++ (con referencias)

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
   * https://codingnest.com/the-little-things-the-missing-performance-in-std-vector/
   * Agraceder este enlace a Javier López Gómez


