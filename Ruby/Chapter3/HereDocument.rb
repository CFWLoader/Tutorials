greeting = <<HERE + <<THERE + 'World'
Hello
HERE
There
THERE

puts greeting

# Use a string to mark the bound of the document.
# Notice the character '#' means different things in the here document.
document = <<-"# # #" # This is the only place we can put a comment.
<html><head><title>#{title}</title></head>
<body>
<h1>#{title}</h1>
#{body}
</body>
</html>
# # #