class Interval

  def initialize low, high

    @low_bound = low

    @high_bound = high

  end

  attr_reader :low_bound, :high_bound

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