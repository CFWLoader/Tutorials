module Filter

  def self.filter pred, seq

    if seq.nil?

      nil

    else

      rest = []

      seq.each {|val|

        if pred.call val

          rest << val

        end

      }

      rest

    end

  end

  def self.accumulate op, initial, seq

    if seq.nil?

      initial

    else

      result = initial

      seq.each { |val|

        result = op.call(result, val)

      }

      result

    end

  end

end


def odd? x

  !(x % 2 == 0)

end


def plus x, a

  x + a

end


def multiply x, a

  x * a

end


def enumerate_interval low, high

  if low > high

    nil

  else

    result = []

    low.upto(high) {|val| result << val}

    result

  end

end


if $0 == __FILE__

  result = Filter.filter method(:odd?), [1, 2, 3, 4, 5, 6]

  print result

  puts

  result = Filter.accumulate method(:plus), 0, [1, 2, 3, 4, 5]

  print result

  puts

  result = Filter.accumulate method(:multiply), 1, [1, 2, 3, 4, 5]

  print result

  puts

  result = enumerate_interval 2, 7

  print result

  p

end