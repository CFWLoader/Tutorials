# Pass code block.
def sequence2(n, m, c)
  i = 0
  while i < n
    yield i * m + c
    i += 1
  end
end

# Pass Anonymous Proc object.
# Last argument with '&' will let code block passed in be a Proc object.
def sequence3(n, m, c, &b)
  i = 0
  while i < n
    b.call i * m + c
    i += 1
  end
end

# Pass an explicit Proc object.
# Notice that the lase argument is without '&'.
def sequence4(n, m, c, b)
  i = 0
  while i < n
    b.call i * m + c
    i += 1
  end
end

# Special argument must be placed in the last position of argument list.
# Pass a map of arguments.
def sequence5(args, &b)
  n, m, c = args[:n], args[:m], args[:c]    # Mapping the arguments.
  i = 0
  while i < n
    b.call i * m + c
    i += 1
  end
end

sequence2(5, 2, 2) {|x| print x, " "}

puts

sequence3(5, 2, 2) {|x| print x, " "}

puts

p = Proc.new {|x| print x, " "}

sequence4(5, 2, 2, p)

puts

sequence5({:n => 5, :m => 2, :c => 2}) {|x| print x, " "}

puts