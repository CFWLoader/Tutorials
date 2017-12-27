x = 3

# Notice that unless logic don't allow else-if condition.
# The logic of unless statement is reverse to if statement.
unless x == 5
  puts "x != 5"
else
  puts "x = 5"
end

k = 4 unless x == 5

puts k                          # Like do-if.