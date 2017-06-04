def expt b, n

   if n == 0

     1

   else

     b * expt(b, n - 1)

   end

end


def expt_iter b, counter, product

  counter == 0 ? product : expt_iter(b, counter - 1, b * product)

end


def expt_iterative b, n

  expt_iter b, n, 1

end


def even? n

  n % 2 == 0

end


def fast_expt b, n

  case n

    when 0 then 1

    when even?(n) then fast_expt(b, n / 2) ** 2

    else

      b * fast_expt(b, n - 1)

  end

end


if $0 == __FILE__

  puts expt 2, 3

  puts expt_iterative 2, 3

  p fast_expt 2, 3

end