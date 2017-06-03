def factorial n

  if n == 1

    1

  else

    n * factorial(n - 1)

  end

end


def fact_iter product, counter, max_count

  if counter > max_count

    product

  else

    fact_iter counter * product, counter + 1, max_count

  end

end


def factorial_iterative n

  fact_iter 1, 1, n

end


if $0 == __FILE__

  puts factorial 4

  puts factorial_iterative 4

end