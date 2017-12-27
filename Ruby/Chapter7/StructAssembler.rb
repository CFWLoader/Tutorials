# Use Struct to create class can auto-generate some basic operations of a class such as getters, setters and comparators.
Point = Struct.new("Point" , :x, :y)          # Dynamically create a class named 'Point'.
# If we omit the first literal variable(notice the first argument's type), the dynamic class is anonymous.
# Point = Struct.new(:x, :y)                    # Second way to create a class.

# Dynamically define the operations of a class.
# You can also use undef to undefine some methods dynamically.
class Point
  def to_s
    "(#{self.x}, #{self.y})"                    # Notice that we use self.{member name} to access member instead of '@'.
  end
end

p = Point.new(5, 6)

print p


