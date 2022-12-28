
* Typical 5-stage pipeline:
  * Forwarding: https://www.cs.umd.edu/~meesh/cmsc411/website/proj01/dlx/forwarding.html
  * Forwarding (Mem->Dec o bien WB->Ex, depende cto usado): https://ee.usc.edu/~redekopp/ee357/slides/EE357Unit18_Pipelining_Notes.pdf
    * WB to MEM [ADD $t1,$t2,$t3; SW $t1,0($s0) | ...]
    * WB to EX [ () ] LW $t1,0($t2); next inst.; SUB $t3,$t1,$t4 | ...]
    * MEM to EX [ADD $t1,$t2,$t3; SUB $t3,$t1,$t4 | ...]

* Directory-Based Cache Coherence:
  * Transparencias: http://15418.courses.cs.cmu.edu/spring2013/lecture/directorycoherence/slide_001
  * Video: https://www.youtube.com/watch?v=KEc4NQZjkMI

* CppCon 2015: Brett Hall "Transactional Memory in Practice":
  * Video: https://www.youtube.com/watch?v=k20nWb9fHj0
  
