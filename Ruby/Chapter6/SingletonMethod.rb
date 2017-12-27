o = 'message'

def o.printSelf       # Defining a method in an object, so-call singleton method.
  print self
end

o.printSelf            # This method can only be used by this object/instance.

def sum(x, y); x + y; end
undef sum             # Undefine a method. It's also used to undefine a class method or undefine a override method without undefining the parent's.