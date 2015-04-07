# Problem of C++ object model

This problem requires the knowledge of C++ object model in memory.<br/>
Especially examining the knowledge of virtual table(Polymorphism).
The following statements are the answer of this problem:<br/>
The most fantastic thing in this problem is the virtual table changed by using a pointer.<br/> 
In this problem, pointer p points to the virtual table of class cat and q points to class dog's.<br/>
Statement p[0] = q[0] means changing the head address of p to q's.<br/>
So the method is class dog's but the data is class cat's.<br/>