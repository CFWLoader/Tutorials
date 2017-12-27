class Point

  @@pointCount = 0                               # Define a class instance variable.

  def initialize(xVal, yVal)
    @x, @y = xVal, yVal
    @@pointCount += 1                            # Count how many points were created.
  end

  # Notice the definition of class constants.
  ORIGIN = Point.new(0, 0)                      # Define a class constants.

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

  def self.report           # This method's notion is similar with static function in C++.
    @@pointCount
  end

end

point = Point.new(1, 3)

puts point.x, point

point.y=7

puts point

puts Point::ORIGIN

puts Point::report
