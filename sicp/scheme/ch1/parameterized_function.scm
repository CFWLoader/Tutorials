#lang racket

(define (cube x) (* x x x))

(define (sum term a next b)
	(if (> a b)
		0
		(+ 	(term a)
			(sum term (next a) next b))))

(define (inc n) (+ n 1))

(define (sum-cubes a b)
	(sum cube a inc b))

(display "Summing cube 1 to 10: ")

(sum-cubes 1 10)

(define (identity x) x)

(define (sum-integers a b)
	(sum identity a inc b))

(display "Summing integer 1 to 10: ")

(sum-integers 1 10)

(define (pi-sum a b)
	(define (pi-term x)
		(/ 1.0 (* x (+ x 2))))
	(define (pi-next x)
		(+ x 4))
	(sum pi-term a pi-next b))

(display "Appriximating pi: ")

(* 8 (pi-sum 1 1000))

;; SICP P39
(define (integral f a b dx)
	(define (add-dx x) (+ x dx))
	(* (sum f (+ a (/ dx 2.0)) add-dx b) dx))

(display "integral cube: Start at 0, end at 1, step is 0.01:\n")

(integral cube 0 1 0.01)

(display "integral cube: Start at 0, end at 1, step is 0.001:\n")

(integral cube 0 1 0.001)