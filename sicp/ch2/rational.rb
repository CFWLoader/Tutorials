def gcd a, b

  if b == 0

    a

  else

    gcd b, a % b

  end

end

class Rational_ext

  def initialize numerator, denominator

    g = gcd numerator, denominator

    @numerator = numerator / g

    @denominator = denominator / g

  end

  attr_reader :numerator, :denominator

  def + rhs

    Rational_ext.new @numerator * rhs.denominator + rhs.numerator * @denominator, @denominator * rhs.denominator

  end

  def - rhs

    Rational_ext.new @numerator * rhs.denominator - rhs.numerator * @denominator, @denominator * rhs.denominator

  end

  def * rhs

    Rational_ext.new @numerator * rhs.numerator, @denominator * rhs.denominator

  end

  def / rhs

    Rational_ext.new @numerator * rhs.denominator, @denominator * rhs.numerator

  end

  def inspect

    "#{@numerator}/#{@denominator}"

  end

  def to_s

    "#{@numerator}/#{@denominator}"

  end

end


if $0 == __FILE__

  a = Rational_ext.new 1, 2

  b = Rational_ext.new 2, 3

  p a + b

  p a - b

  p b - a

  p a * b

  p a / b

end