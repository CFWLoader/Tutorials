# Creating lambda object.
succ = lambda {|x| x + 1}

puts succ.call(2)

succ1 = ->(x) {x + 1}

puts succ1.call(5)