x = 3

# Auto break.
case
  when x == 1
    puts "one"
  when x == 2
    puts "two"
  when x == 3
    puts "three"
  else
    puts "Unknown."
end

# Evaluation
# Focus on the evaluation formula details.
nameOfNumber = case x
                 when 1
                   "one"
                 when 2
                   "two"
                 when 3
                   "three"
                 else
                   "Unknown."
               end

puts nameOfNumber

# Equivalent form of evaluation. 'then' can be omitted.
nameOfNumber = case
                 when x === 1 then
                   "one"
                 when x === 2 then
                   "two"
                 when x === 3 then
                   "three"
                 else
                   "Unknown."
               end

puts nameOfNumber