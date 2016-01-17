# This demo can't run properly because the codes from book are compiled as the different semantics
# to the book's.
module Functional
  def apply(enum)
    enum.map &self          #
  end

  alias | apply             # Set alias to apply.

  def reduce(enum)
    enum.inject &self
  end

  alias <= reduce
end

class Proc; include Functional; end
class Method; include Functional; end

a = [1, 2, 3, 4]

sum = lambda {|x, y| x + y}

mean = (sum<=a)/a.size

deviation = lambda {|x| x - mean}

square = lambda { |x| x * x}

standardDeviation = Math.sqrt((sum<=square | (deviation|a))/a.size - 1)

puts standardDeviation