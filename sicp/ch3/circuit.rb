class Wire

  def initialize symbol

    @symbol = symbol

  end

end

class Gate
end


class OrGate < Gate

  def initialize input_wire1, input_wire2, output_wire

    @input1 = input_wire1

    @input2 = input_wire2

    @output = output_wire

  end

end


class AndGate < Gate

  def initialize input_wire1, input_wire2, output_wire

    @input1 = input_wire1

    @input2 = input_wire2

    @output = output_wire

  end

end


class Inverter < Gate

  def initialize input_wire, output_wire

    @input = input_wire

    @output = output_wire

  end

end


class HalfAdder

  def initialize a, b, s, c

    @d = Wire.new :d

    @e = Wire.new :e

    @or_gate = OrGate.new a, b, @d

    @and_gate1 = AndGate.new a, b, c

    @inverter = Inverter.new c, @e

    @and_gate2 = AndGate.new @d, @e, s

  end

end


class FullAdder

  def initialize a, b, c_in, sum, c_out

  end

end


if $0 == __FILE__

end