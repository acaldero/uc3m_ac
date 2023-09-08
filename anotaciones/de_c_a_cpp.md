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


