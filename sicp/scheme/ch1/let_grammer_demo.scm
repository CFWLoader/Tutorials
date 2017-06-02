#lang racket

;; Use function to express the following function:
;; f(x, y)=x(1 + xy)^2 + y(1 - y) + (1 + xy)(1 - y)
;; Let a = 1 + xy, b = 1 - y
;; Then f(x, y) = xa^2 + yb + ab

(define (f0 x y)
	(define (f-helper a b)
		(+	(* x (* a a))
			(* y b)
			(* a b)))
	(f-helper (+ 1 (* x y)) (- 1 y)))

(define (f1 x y)
	((lambda (a b)
		(+ 	(* x (* a a))
			(* y b)
			(* a b)))
	(+ 1 (* x y))
	(- 1 y)))

;; Use let to create local variables.
(define (f2 x y)
	(let ( 	(a (+ 1 (* x y)))
			(b (- 1 y)))
	(+ 	(* x (* a a))
		(* y b)
		(* a b))))

(f0 1 10)

(f1 1 10)

(f2 1 10)