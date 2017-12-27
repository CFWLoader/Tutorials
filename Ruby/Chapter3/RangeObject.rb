triple = "AAA".."ZZZ"

puts triple.include? "ABC"
puts triple.include? "ABCD"
puts triple.cover? "ABCD"
puts triple.to_a.include? "ABCD"
puts triple.cover? "ABCCD"
puts triple.cover? "AB"