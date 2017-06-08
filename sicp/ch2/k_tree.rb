<<begin

This is the ruby version of the tree in sicp. In sicp, tree is implemented by list.
But I modify it to trivial implementation.

begin

class TreeNode

  attr_accessor :val, :childs

  def initialize val, childs = nil

    @val = val

    childs.nil? ? @childs = [] : @childs = childs

  end

  def leave?

    @childs.nil?

  end

end


class K_Tree

  def initialize seq_ptn

    @root = TreeNode.new nil, interpret_pattern(seq_ptn)

  end

  def interpret_pattern ptn

    if ptn.nil? or ptn.empty?

      nil

    else

      node_list = []

      ptn.each {|val|

        if val.class == Array

          node_list << TreeNode.new(nil, interpret_pattern(val))

        else

          node_list << TreeNode.new(val)

        end

      }

      node_list

    end

  end

  def inspect

    @root.inspect

    inspect_assistance @root

  end

  def inspect_assistance node

    if node.val.nil?

      ret_str = '['

      node.childs.each {|sub|

        ret_str += inspect_assistance(sub) + ' '

      }

      ret_str + ']'

    else

      node.val.to_s

    end

  end

  def count_leaves

    quque = @root.childs.clone

    count = 0

    until quque.empty?

      if quque.first.val.nil?

        quque << quque.first.childs

        quque.flatten!

      else

        count += 1

      end

      quque.shift

    end

    count

  end

  def scale_element factor

    quque = @root.childs.clone

    count = 0

    until quque.empty?

      if quque.first.val.nil?

        quque << quque.first.childs

        quque.flatten!

      else

        quque.first.val *= factor

      end

      quque.shift

    end

    count

  end

  def sum_odd_squares

    quque = @root.childs.clone

    sum = 0

    until quque.empty?

      if quque.first.val.nil?

        quque << quque.first.childs

        quque.flatten!

      else

        sum += quque.first.val ** 2 if quque.first.val % 2 != 0

      end

      quque.shift

    end

    sum

  end

end


if $0 == __FILE__

  # tree = K_Tree.new [[1, 2], 3, 4, [[5], 6], 7]
  #
  # puts tree.inspect
  #
  # tree.scale_element 3
  #
  # p tree

  tree = K_Tree.new [[1, 2], 3, 4, 7]

  p tree.sum_odd_squares

end