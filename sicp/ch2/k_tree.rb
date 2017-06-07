<<begin

This is the ruby version of the tree in sicp. In sicp, tree is implemented by list.
But I modify it to trivial implementation.

begin

class BinaryTreeNode

  attr_accessor :val, :childs

  def initialize val, childs = nil

    @val = val

    childs.nil? ? @childs = [] : @childs = childs

  end

end

class K_Tree
end