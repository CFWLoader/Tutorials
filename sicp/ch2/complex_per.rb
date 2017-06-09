class Complex_per

  def same_class? rhs

    self.class == rhs.class

  end

  def fit_class clazz

  end

  def + rhs

    self + fit_class(rhs)

  end

  def - rhs

    self - fit_class(rhs)

  end

  def * rhs

    self + fit_class(rhs)

  end

  def / rhs

    self + fit_class(rhs)

  end

end

class Rectangular < Complex_per

  attr_accessor :real_part, :img_part

  def initialize real_part = 0, img_part = 0

    @real_part = real_part

    @img_part = img_part

  end

  def make_from_mag_ang mag, angle

    @real_part = mag * Math.cos(angle)

    @img_part = mag * Math.sin(angle)

  end

  def polar_values

    return Math.sqrt(@real_part ** 2 + @img_part ** 2), Math.atan2(@img_part, @real_part)

  end

  def + rhs

    Complex_per.new @real_part + rhs.real_part, @img_part + rhs.img_part

  end

  def - rhs

    Rectangular.new @real_part - rhs.real_part, @img_part - rhs.img_part

  end

  def * rhs

    Rectangular.new @real_part * rhs.real_part - @img_part * rhs.img_part, rhs.real_part * @img_part + @real_part * rhs.img_part

  end

  def / rhs

    # mag1 = Math.sqrt(@real_part ** 2 + @img_part ** 2)
    #
    # angle1 = Math.atan @img_part / @real_part
    #
    # mag2 = Math.sqrt(rhs.real_part ** 2 + rhs.img_part ** 2)
    #
    # angle2 = Math.atan rhs.img_part / rhs.real_part
    #
    # mag = mag1 * mag2
    #
    # angle = angle1 + angle2
    #
    # Complex_per mag * Math.cos(angle), mag * Math.sin(angle)

    Rectangular.new (@real_part * rhs.real_part + @img_part * rhs.img_part) / (rhs.real_part ** 2 + rhs.img_part ** 2),
                    (rhs.real_part * @img_part - @real_part * rhs.img_part) / (rhs.real_part ** 2 + rhs.img_part ** 2)

  end

end


class Polar < Complex_per

  attr_accessor :mag, :ang

  def initialize magnitude = 0, angle = 0

    @mag = magnitude

    @ang = angle

  end

  def make_from_real_imaginary real, img

    @mag = Math.sqrt(real ** 2 + img ** 2)

    @ang = Math.atan2 img, real

  end

  def rectangular_values

    return @mag * Math.cos(@ang), @mag * Math.sin(@ang)

  end

  def + rhs

    real = @mag * Math.cos(@ang) + rhs.mag * Math.cos(rhs.ang)

    img = @mag * Math.sin(@ang) + rhs.mag * Math.sin(rhs.ang)

    Polar.new Math.sqrt(real ** 2 + img ** 2), Math.atan2(img, real)

  end

  def - rhs

    real = @mag * Math.cos(@ang) - rhs.mag * Math.cos(rhs.ang)

    img = @mag * Math.sin(@ang) - rhs.mag * Math.sin(rhs.ang)

    Polar.new Math.sqrt(real ** 2 + img ** 2), Math.atan2(img, real)

  end

  def * rhs

    Polar.new @mag * rhs.mag, @ang + rhs.ang

  end

  def / rhs

    Polar.new @mag / rhs.mag, @ang - rhs.ang

  end

end


if $0 == __FILE__

  com1 = Rectangular.new 1, 1

  com2 = Rectangular.new 2, 2

  po1 = Polar.new com1.polar_values[0], com1.polar_values[1]

  po2 = Polar.new com2.polar_values[0], com2.polar_values[1]

  p com2 / com1

  p (po2 / po1).rectangular_values

  p com2.same_class? po1

end