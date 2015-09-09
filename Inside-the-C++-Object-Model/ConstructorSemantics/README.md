#   Constructor Semantics
This demo demonstrates some constructor semantic of C++.<br/>
In the construction of the class `Derived` instance, the object type is `Base`.<br/>
Emphases that the situation of invoking virtual function `function` in the `Base` constructor.<br/>
The static type (compiling time) of `Derived` instance is `Base` and it becomes `Derived` after construction of `Base` part.<br/>
So the type of `Derived` instance is `Base` in the constructor of `Base` and Base::function() invoked.