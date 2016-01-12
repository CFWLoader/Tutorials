iterator = 9.downto 1

begin
  print iterator.next while true        # Finally throw an exception.
rescue StopIteration                    # Cath the StopIteration exception.
  puts "...blastoff!"
end