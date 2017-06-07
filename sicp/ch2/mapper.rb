module Mapper

  def self.map proc, items

    if items.nil?

      nil

    else

      rest = []

      items.each { |val|

        rest << proc.call(val)

      }

      rest

    end

  end

end


def abs x

  x.abs

end


def scale_list items, factor

  Mapper.map lambda{|x| x * factor}, items

end


if $0 == __FILE__

  result = Mapper.map method(:abs), [-10, 2.5, -11.6, 17]

  puts result

  result = Mapper.map lambda{|x| x ** 2}, [1, 2, 3, 4]

  puts result

  result = scale_list [1, 2, 3, 4], 7

  puts result

end