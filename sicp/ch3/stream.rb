class Stream

  def initialize

    @store_chunk = []

  end

  # (define (stream-ref s n))
  def [] idx

    @store_chunk[idx]

  end

  #(define (stream-map proc s))
  def map proc

    new_stream = Stream.new

    @store_chunk.each_with_index {|val, idx|

      new_stream.store_chunk[idx] = proc.call val

    }

    new_stream

  end

  #(define (stream-for-each proc s))
  def apply proc

    @store_chunk.each{|val|

      proc.call val

    }

  end

  def display

    apply puts

  end

end


if $0 == __FILE__

  s = Stream.new

  s.display

end