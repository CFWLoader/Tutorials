def square x

  x**2

end


def improve guess, x

  (guess + x / guess) / 2

end


def good_enough? guess, x

  (square(guess) - x).abs < 0.001

end


def sqrt_iter guess, x

  if good_enough? guess, x

    guess

  else

    sqrt_iter improve(guess, x), x

  end

end


def sqrt x

  sqrt_iter 1.0, x

end


def sqrt_integrity x

  good_enough = lambda { |guess| (square(guess) - x).abs < 0.001 }

  improve_ = lambda { |guess| (guess + x / guess) / 2 }

  sqrt_iter_ = lambda { |guess|

    if good_enough.call guess

      guess

    else

      sqrt_iter_.call improve_.call(guess)

    end

  }

  sqrt_iter_.call 1.0

end


if $0 == __FILE__

  puts sqrt_integrity 9

  # puts sqrt 9
  #
  # puts sqrt (100 + 37)
  #
  # puts sqrt(sqrt(2) + sqrt(3))
  #
  # puts square sqrt(1000)

end
