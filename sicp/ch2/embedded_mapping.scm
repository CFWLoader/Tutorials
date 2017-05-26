#lang racket

; (accumulate append
; 			null
; 			(map (lambda (i)
; 					(map (lambda (j) (list i j))
; 						(enumerate-interval 1 (- i 1))))
; 			(enumerate-interval 1 n)))

(define (flatmap proc seq)
	(accumulate append null (map proc seq)))

(define (prime-sum? pair)
	(prime? (+ (car pair) (cadr pair))))

(define (make-pair-sum pair)
	(list (car pair) (cadr pair) (+ (car pair) (cadr pair))))