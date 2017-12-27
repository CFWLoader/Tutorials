# Conclusion: Proc object acts like a iterator.
# Lambda object acts like a method.
def test
  puts "entering method"
  1.times { puts "entering block"; return} # Makes test method return.
  puts "exiting method" # This line is never executed.
end

test

def testProc
  puts "entering method"
  p = Proc.new { puts "entering proc"; return} # Makes test method return.
  p.call                  # Invoking the proc makes method return.
  puts "exiting method" # This line is never executed.
end

testProc

def testLambda
  puts "entering method"
  # p = lambda { puts "entering proc"; return} # Makes test method return.
  p = ->() { puts "entering proc"; return}
  p.call                  # Invoking the proc makes method return.
  puts "exiting method" # This line is executed.
end

testLambda