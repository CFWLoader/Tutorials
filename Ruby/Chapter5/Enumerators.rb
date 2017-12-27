def twice
  if block_given?           # Confirm the caller give a executable code block or not.
    yield
    yield
  else
    self.to_enum(:twice)    # If not, return self as a enumerator.
  end
end

enumerator = 3.times

enumerator.each { |x| print x }

puts

enumerator = "hello".each_char.with_index   # Return the enumerator with index.

for ch, idx in enumerator
  print "#{idx} : #{ch} "
end