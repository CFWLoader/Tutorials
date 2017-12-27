planet = "Earth"

print 'Hello' + ' ' + planet
puts # For new line.

planetNumber = 3

# You have to use method 'to_s' to convert other types to string type explicitly in string concatenation.
# print 'Hello planet ' + planetNumber
print 'Hello planet ' + planetNumber.to_s
puts

# But Ruby can automatically convert the variables via string internal insertion.
print "Hello planet #{planetNumber}\n"

# C++ style string concatenation.
greeting = "Hello"

greeting << " " << "World"

puts greeting
