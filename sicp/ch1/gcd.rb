def gcd a, b

  if b == 0

    a

  else

    gcd b, a % b

  end

end


if $0 == __FILE__

  p gcd 7, 3

  p gcd 10, 3

  p gcd 9, 3

end