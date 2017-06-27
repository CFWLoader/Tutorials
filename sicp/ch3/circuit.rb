class Wire

  def initialize symbol, init_signal = false

    @symbol = symbol

    @signal = init_signal

  end

  # Lazy evaluation.
  # SICP original codes is constructing a callback fun.
  def get_signal

    @action.nil? ? @signal : @action.call

  end

  def set_signal! new_value

    @signal = new_value

  end

  def add_action! proc, **args

    @action = lambda{proc.call args}

  end

end

class Gate
end


class OrGate < Gate

  def initialize input_wire1, input_wire2, output_wire

    @input1 = input_wire1

    @input2 = input_wire2

    @output = output_wire

    @output.add_action! lambda{|args| args[:i1].get_signal or args[:i2].get_signal}, i1: @input1, i2: @input2

  end

  def get_output

    @output.get_signal

  end

end


class AndGate < Gate

  def initialize input_wire1, input_wire2, output_wire

    @input1 = input_wire1

    @input2 = input_wire2

    @output = output_wire

    @output.add_action! lambda{|args| args[:i1].get_signal and args[:i2].get_signal}, i1: @input1, i2: @input2

  end

  def get_output

    @output.get_signal

  end

end


class Inverter < Gate

  def initialize input_wire, output_wire

    @input = input_wire

    @output = output_wire

    invert_input @input, @output

  end

  def invert_input input, output

    expr = lambda {|i| !i[:ie].get_signal}

    output.add_action! expr, ie: input

  end

  def get_output

    @output.get_signal

  end

end


class HalfAdder

  def initialize a, b, s, c

    d = Wire.new :d

    e = Wire.new :e

    @or_gate = OrGate.new a, b, d

    @and_gate1 = AndGate.new a, b, c

    @inverter = Inverter.new c, e

    @and_gate2 = AndGate.new d, e, s

  end

end


class FullAdder

  def initialize a, b, c_in, sum, c_out

    s = Wire.new :s

    c1 = Wire.new :c1

    c2 = Wire.new :c2

    half_adder1 = HalfAdder.new b, c_in, s, c1

    half_adder2 = HalfAdder.new a, s, sum, c2

    or_gate = OrGate.new c1, c2, c_out

  end

end


def test_case1

  i = Wire.new :in1

  o = Wire.new :out1

  inverter = Inverter.new i, o

  i.set_signal! false

  puts inverter.get_output

  i.set_signal! true

  puts inverter.get_output

end


def test_case2

  in1 = Wire.new :i1, false

  in2 = Wire.new :i2, true

  o = Wire.new :o

  or_gate = OrGate.new in1, in2, o

  p or_gate.get_output

  in2.set_signal! false

  p or_gate.get_output

  p o.get_signal

  #and_gate = AndGate.new in1, in2, o

end


if $0 == __FILE__

  test_case2

end