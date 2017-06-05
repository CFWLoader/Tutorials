def sum term, a, next_step, b

  if a > b

    0

  else

    term.call(a) + sum(term, next_step.call(a), next_step, b)

  end

end


def inc a

  a + 1

end


def sum_integers a, b

  sum lambda{|x| x}, a, method(:inc), b

end


def sum_cubes a, b

  sum lambda{|x| x ** 3}, a, method(:inc), b

end


def pi_sum a, b

  pi_term = lambda{|x| 1.0 / (x * (x + 2))}

  pi_next = lambda{|x| x + 4}

  sum pi_term, a, pi_next, b

end


def integral f, a, b, dx

  add_dx = lambda{|x| x + dx}

  sum(f, a + dx / 2.0, add_dx, b) * dx

end


if $0 == __FILE__

  p sum_cubes 1, 10

  p sum_integers 1, 10

  p 8 * pi_sum(1, 1000)

  p integral lambda{|x| x**3}, 0, 1, 0.01

  p integral lambda{|x| x**3}, 0, 1, 0.001

end