require './fixed_point.rb'

def average_damp f

  lambda{|x| (x + f.call(x)) / 2.0}

end


def average_damp_ruby x, f

  yield (x + f.call(x)) / 2.0

end


def sqrt x

  fixed_point average_damp(lambda{|y| x / y}), 1.0

end


def cube_root x

  fixed_point average_damp(lambda{|y| x / (y ** 2)}), 1.0

end

DX = 0.00001

# derivative
def deriv g

  lambda{|x| (g.call(x + DX) - g.call(x)) / DX}

end


def newton_transform g

  lambda{|x| x - g.call(x) / deriv(g).call(x)}

end


def newtons_method g, guess

  fixed_point newton_transform(g), guess

end


def sqrt_newton x

  newtons_method lambda{|y| y ** 2 - x}, 1.0

end


if $0 == __FILE__

  p average_damp(lambda{|x| x ** 2}).call 10

  average_damp_ruby(10, lambda{|x| x ** 2}) {|x| p x}

  p sqrt 2

  p sqrt_newton 2

  p cube_root 27

  p deriv(lambda{|x| x ** 3}).call 5

end