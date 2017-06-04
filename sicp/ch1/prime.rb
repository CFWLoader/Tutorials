require './exponent.rb'


def divides? a, b

  b % a == 0

end


def find_divisor n, test_divisor

  case

    when test_divisor ** 2 > n then n

    when divides?(test_divisor, n) then test_divisor

    else find_divisor n, test_divisor + 1

  end

end


def smallest_divisor n

  find_divisor n, 2

end


def prime? n

  n == smallest_divisor(n)

end


def expmod base, exp, m

  case

    when exp == 0 then 1

    when even?(exp) then (expmod(base, exp / 2, m) ** 2) % m

    else (expmod(base, exp - 1, m) * base) % m

  end

end


def fermat_test n

  try_it = lambda {|a| expmod(a, n, n) == a}

  try_it.call(rand(n - 1) + 1)

end


def fast_prime? n, times

  case

    when times == 0 then true

    when fermat_test(n) then fast_prime? n, times - 1

    else false

  end

end


if $0 == __FILE__

  p prime? 2

  p prime? 4

  p prime? 17

  p fast_prime? 17, 4

end