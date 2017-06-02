#lang racket

(define one-through-four (list 1 2 3 4))

(define (list-ref items n)
	(if (= n 0)
		(car items)
		(list-ref (cdr items) (- n 1))))

(define (length items)
	(if (null? items)
		0
		(+ 1 (length (cdr items))))
)

(define (append list1 list2)
	(if (null? list1)
		list2
		(cons (car list1) (append (cdr list1) list2))))

(define (scale-list items factor)
	(if (null? items)
		null
		(cons (* (car items) factor)
			(scale-list (cdr items) factor))))

(define (map proc items)
	(if (null? items)
		null
		(cons (proc (car items))
			(map proc (cdr items)))))

;(car one-through-four)

;(car (cdr one-through-four))

(define squares (list 1 4 9 16 25))

(length squares)

(list-ref squares 3)

(scale-list (list 1 2 3 4 5) 10)

(map abs (list -10 2.5 -11.6 17))