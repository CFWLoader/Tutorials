class Point
  attr_accessor :x, :y            # attr* series function will auto-generate getters and setters for attributes.(Metaprogramming in Ruby.)

  # attr_reader :x                # Defining immutable variables.
  # attr :x [,true]               # Define getter and setter for a variable if the second argument defined true, false or nil will be only getter.

  def initialize xVal, yVal
    @x, @y = xVal, yVal
  end

  def to_s                  # Object.toString in Java.
    "(#@x, #@y)"
  end
end

p = Point.new(1, 3)

p.x= 4

puts p

