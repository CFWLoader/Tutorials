x = 1

if x == 1
  puts "x = 1"
elsif x==2                  # Notice "else if" in Ruby is "elsif".
  puts "x = 2"
else
  puts "x = other."
end

# The following 2 demos are equivalent to "if x==1".
begin
  puts "x = 1"
end if x == 1

(
  puts "x = 1"
) if x == 1

k = 3 if true               # Do if true.

a = (k == 3) ? 5 : 6        # Ruby support 3-parameters-operation expression.

puts k