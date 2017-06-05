TOLERANCE = 0.00001

cos = lambda {|x| Math.cos x}

sin = lambda {|x| Math.sin x}

def fixed_point f, first_guess

  close_enough = lambda{|v1, v2| (v1 - v2).abs < TOLERANCE}

  try = lambda{|guess|

    next_val = f.call guess

    if close_enough.call guess, next_val

      next_val

    else

      try.call next_val

    end

  }

  try.call first_guess

end


def sqrt x

  #fixed_point lambda{|y| x / y}, 1.0

  fixed_point lambda{|y| (y + x / y) / 2.0}, 1.0

end


if $0 == __FILE__

  p fixed_point cos, 1.0

  p fixed_point lambda{|y| sin.call(y) + cos.call(y)}, 1.0

  p sqrt 2

end