class Interval

  def initialize low, high

    @low_bound = low

    @high_bound = high

  end

  def inspect

    "#{@low_bound}~#{@high_bound}"

  end

  def + rhs

    Interval.new @low_bound + rhs.low_bound, @high_bound + rhs.high_bound

  end

  def * rhs

    paras = [@low_bound * rhs.low_bound, @low_bound * rhs.high_bound, @high_bound * rhs.low_bound, @high_bound * rhs.high_bound]

    paras.sort!

    Interval.new paras.first, paras.last

  end

  def / rhs

    self * Interval.new(1.0 / rhs.high_bound, 1.0 / rhs.low_bound)

  end

  # notice that ruby's 'private' doesn't allow accessing members between instances in same class.
  # So this changed to 'protected'.
  protected

  attr_reader :low_bound, :high_bound

end


if $0 == __FILE__

  i1 = Interval.new 1, 10

  i2 = Interval.new 2, 9

  p i1

  p i2

  p i1 + i2

  p i1 * i2

  p i1 / i2

end