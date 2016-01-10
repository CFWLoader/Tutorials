arr = Array.new

name = :include? # Assign a symbol "include?" to variable "name".
<<doc
  Note that Symbol class defined some String method and they can be operated with String class object.
  But Symbol object is immutable and can be garbage-collected.
doc

puts arr.respond_to? name # Test object arr(Type: Array) has a method named "include?".

name_str = "include?"

puts arr.respond_to? name_str

=begin
  symbol can be used in Reflexion(Search for fields or methods).
=end