# Creating lambda object.
succ = lambda {|x| x + 1}

puts succ.call(2)

succ1 = ->(x) {x + 1}

puts succ1.call(5)

puts succ[3]                  # Other way to call lambda function.

puts succ.(4)