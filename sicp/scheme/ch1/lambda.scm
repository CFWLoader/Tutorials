#lang racket

(define (sum term a next b)
	(if (> a b)
		0
		(+ 	(term a)
			(sum term (next a) next b))))

(define (pi-sum a b)
	(sum 	(lambda (x) (/ 1.0 (* x (+ x 2))))
			a
			(lambda (x) (+ x 4))
			b))

(display "Appriximating pi:\n")

(* 8 (pi-sum 1 1000))

(display "\n")

(define (integral f a b dx)
	(* (sum f (+ a (/ dx 2.0)) (lambda (x) (+ x dx)) b) dx))

(display "integral cube: Start at 0, end at 1, step is 0.01:\n")

(integral (lambda (x) (* x x x)) 0 1 0.01)

(display "integral cube: Start at 0, end at 1, step is 0.001:\n")

(integral (lambda (x) (* x x x)) 0 1 0.001)