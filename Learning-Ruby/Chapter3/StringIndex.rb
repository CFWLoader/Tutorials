s = "hello"

s[0, 1] = "H" # Replace first letter with a capital letter.
s[s.length, 0] = " world" # Append by assigning beyond the end of the string.
s[5, 0] = "," # Insert a comma, without deleting anything.
s[5, 6] = "" #Delete with no insertion; s == "Hellod"

s = "hello"

s[2..3] # Index range 2 to 3, returning "ll"
s[-3..-1] # Backward index, returning "llo"
s[0..0] # Index range 0 to 0, returning "h"
s[-2..-1] = "p!" # Replacement: s becomes "help!"

# Notice these two method to index the string:
# comma - s[a,b] means b characters from index a.
# range - s[a,b] means the characters index from a to b.

s = "hello"
s["l"] # Notice this index operand will let operator [] return the matched substring instead of other values.
# More, You can use regex forms in index to search substring.