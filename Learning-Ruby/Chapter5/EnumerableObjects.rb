[1, 2, 3].each do |x|
  print x
end

puts

(1..5).each do |x|
  print x
end

puts

square = (1..3).collect {|x| x*x}         # Collect.

print square

puts

evens = (1..10).select {|x| x % 2 == 0}   # Select those even numbers.

print evens

puts

odds = (1..10).reject {|x| x % 2 == 0}    # reject()'s result is reverse to select() with same condition.

print odds

puts

# inject() acts like an accumulator.
# Every result from current iteration will be passed to next iteration. For example, the sum variable in the parameter list.
result = [2, 3, 4, 5].inject { |sum, x| sum += x}

puts result

# Using inject to find max value.
max = [5324, 45, 11, 39382, 3395, 10, 194].inject {|max, x| max > x ? max : x}

puts max