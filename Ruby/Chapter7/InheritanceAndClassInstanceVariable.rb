# Class instance variable is always shared even though in inheritance.
class A
  @@value = 1
  def A.value; @@value; end
end

print A::value

class B < A
  @@value = 2
end

print A::value

class C < A
  @@value = 3
end

print B::value