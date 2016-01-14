# Return a fiber to compute fibonacci number.
def fibonacciGenerator(x0 , y0)
  Fiber.new do
    x, y = x0, y0
    loop do
      Fiber.yield y                   # yield() will let Fiber object deliver the control to the caller.
      x, y = y, x + y
    end
  end
end

# It's a tendency that Ruby programmer usually encapsulate the fiber
# in their code because it's hard to figure out directly.
class FibonacciGenerator
  def initialize                      # Constructor of class.
    @x, @y = 0, 1
    @fiber = Fiber.new do
      loop do
        @x, @y = @y, @x + @y
        Fiber.yield @x
      end
    end
  end

  def next                            # Next Fibonacci number.
    @fiber.resume
  end

  def rewind                          # Restart the computation.
    @x, @y = 0, 1
  end
end

# Enumerator Style.
class Generator
  def initialize(enumerable)
    @enumerable = enumerable
    createFiber
  end

  def next
    @fiber.resume
  end

  def rewind
    createFiber
  end

  private
  def createFiber
    @fiber = Fiber.new do
      @enumerable.each do |x|
        Fiber.yield x
      end
      raise StopIteration
    end
  end
end

g = fibonacciGenerator 0, 1

10.times do
  print g.resume, " "
end

puts

g2 = FibonacciGenerator.new

10.times { print g2.next, " "}

puts

g2.rewind

10.times { print g2.next, " "}

puts

g3 = Generator.new(1..10)

loop { print g3.next, " " }

puts

g3.rewind

loop { print g3.next, " " }

puts