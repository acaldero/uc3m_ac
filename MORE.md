## Materiales adicionales para Arquitectura de Computadores

<html>
<ul>
<li> License <a href="http:/creativecommons.org/licenses/by-nc/4.0/">CC BY-NC 4.0</a> </li>
<li> Curso 2022-2023</li>
</ul>
</html>


## Materiales complementarios

* Typical 5-stage pipeline:
  * Forwarding: https://www.cs.umd.edu/~meesh/cmsc411/website/proj01/dlx/forwarding.html
  * Forwarding (Mem->Dec o bien WB->Ex, depende cto usado): https://ee.usc.edu/~redekopp/ee357/slides/EE357Unit18_Pipelining_Notes.pdf
    * WB to MEM [ADD $t1,$t2,$t3; SW $t1,0($s0) | ...]
    * WB to EX [ () ] LW $t1,0($t2); next inst.; SUB $t3,$t1,$t4 | ...]
    * MEM to EX [ADD $t1,$t2,$t3; SUB $t3,$t1,$t4 | ...]

* Directory-Based Cache Coherence:
  * Transparencias: http://15418.courses.cs.cmu.edu/spring2013/lecture/directorycoherence/slide_001
  * Video: https://www.youtube.com/watch?v=KEc4NQZjkMI

* Introducción al lenguaje C++
  * Posibles tutoriales de interés:
    * https://www.w3schools.com/cpp/
    * https://cplusplus.com/doc/tutorial/
  * Posibles herramientas de interés:
    * https://en.cppreference.com/w/
    * https://godbolt.org/

* Memoria transaccional:
  * Video CppCon 2015: Brett Hall "Transactional Memory in Practice": https://www.youtube.com/watch?v=k20nWb9fHj0
  * Esquema de ayuda para SC vs TSO vs PSO vs WO: https://slideplayer.com/slide/15188206/92/images/27/Adibidea+SC+TSO%2FPC+PSO+WO+RC+ordena+rd+wr+sink_a+sink_r+%3D+A+B+%3D.jpg

* OpenMP
  * Revisar los recursos disponibles en: https://www.openmp.org/resources/
  * Empezar por el tutorial: Introduction to OpenMP: https://www.youtube.com/watch?embed=no&v=nE-xN4Bf8XI&list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG
  * Complementar con el resumen simple sobre omp: https://github.com/acaldero/slides/blob/main/GII_Arquitectura_De_Computadores/gii-ac-omp-v3.pdf
  * Complementar con la guía rápida oficial en: https://www.openmp.org/resources/refguides/

