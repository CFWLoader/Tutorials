# Iteration method. Naively call two relevant code blocks.
def twice
  yield
  yield
end

twice { puts "haha." }

def sequence(n, m, c)
  i = 0
  while i < n
    yield m * i + c
    i += 1
  end
end

sequence(3, 5, 1) {|y| puts y}