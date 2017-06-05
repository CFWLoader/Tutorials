def sin_wrapper s

  Math.sin s

end

def close_enough? x, y

  (x - y).abs < 0.001

end

def search f, neg_point, pos_point

  mid_point = (neg_point + pos_point) / 2.0

  if close_enough? neg_point, pos_point

    mid_point

  else

    test_value = f.call mid_point

    case

      when test_value > 0 then search(f, neg_point, mid_point)

      when test_value < 0 then search(f, mid_point, pos_point)

      else mid_point

    end

  end

end


def half_interval_method f, a, b

  a_value = f.call a

  b_value = f.call b

  case

    when (a_value < 0 and b_value > 0)

      search f, a, b

    when (b_value < 0 and a_value > 0)

      search f, b, a

    else

      raise Exception("Values are not of opposite sign: #{a}, #{b}")

  end

end


if $0 == __FILE__

  p half_interval_method method(:sin_wrapper), 2.0, 4.0

  p half_interval_method lambda{|x| x ** 3 - 2 * x - 3}, 1.0, 2.0

end