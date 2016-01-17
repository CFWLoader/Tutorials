class Point
  def initialize(xVal, yVal)
    @x, @y = xVal, yVal
  end

  # Getters and Setters.
  def x
    @x
  end

  def y
    @y
  end

  def x= value
    @x = value
  end

  def y= value
    @y = value
  end

  def to_s                  # Object.toString in Java.
    "(#@x, #@y)"
  end

end

point = Point.new(1, 3)

puts point.x, point

point.y=7

puts point
