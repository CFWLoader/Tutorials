#lang racket

(define tolerance 0.00001)

(define (fixed-point f first-guess)
	(define (close-enough? v1 v2)
		(< (abs (- v1 v2)) tolerance))
	(define (try guess)
		(let ((next (f guess)))
			(if (close-enough? guess next)
				next
				(try next))))
	(try first-guess))

(define (average a b) (/ (+ a b) 2))

(define (square x) (* x x))

(define (average-damp f)
	(lambda (x) (average x (f x))))

((average-damp square) 10)

(define (sqrt x)
	(fixed-point (average-damp (lambda (y) (/ x y)))
		1.0))

(sqrt 9)

(define (cube-root x)
	(fixed-point (average-damp (lambda (y) (/ x (square y))))
		1.0))

(cube-root 27)

;; SICP P49: Dg(x)=(g(x + dx) - g(x)) / dx
(define (deriv g)
	(lambda (x)
		(/ (- (g (+ x dx)) (g x))
			dx)))

(define dx 0.0001)

;; Derive of f(x) = x^3
(define (cube x) (* x x x))

((deriv cube) 5)

(define (newton-transform g)
	(lambda (x)
		(- x (/ (g x) ((deriv g) x)))))

(define (newtons-method g guess)
	(fixed-point (newton-transform g) guess))

(define (sqrt-n x)
	(newtons-method (lambda (y) (- (square y) x))
		1.0))

(sqrt-n 121)