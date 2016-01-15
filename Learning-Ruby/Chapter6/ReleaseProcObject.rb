a, b = [1, 2, 3], [4, 5]

accumulation = Proc.new {|total, x| total + x}

# Use '&' in passing argument will let Proc object be a normal code block.
sum = a.inject 0, &accumulation

puts sum

sum = b.inject sum, &accumulation

puts sum