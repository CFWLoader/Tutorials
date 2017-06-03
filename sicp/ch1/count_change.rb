def first_denomination kinds_of_coins

  case kinds_of_coins

    when 1 then 1

    when 2 then 5

    when 3 then 10

    when 4 then 25

    when 5 then 50

  end

end


def cc amount, kinds_of_coins

  case

    when amount == 0 then 1

    when (amount < 0 or kinds_of_coins == 0) then 0

    else

      cc(amount, kinds_of_coins - 1) + cc(amount - first_denomination(kinds_of_coins), kinds_of_coins)

  end

end


def count_change amount

  cc amount, 5

end


if $0 == __FILE__

  puts count_change 100

end