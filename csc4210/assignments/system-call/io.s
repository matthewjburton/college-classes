# ----------------------------------------------------------------------------
# Writes "Hello, World" to the console using only system calls.
# Runs on 64-bit Linux only.
# To assemble and run:
#
# 	To assemble (compile)
# 	gcc -no-pie io.s
# 	To execute
# 	./a.out
# -----------------------------------------------------------------------------
	.section .bss
	.lcomm message, 13

	.globl main
	.type main,@function
	.section .text
main:
	# read(0, message, 13)
	mov $0, %rax 		# system call 0 is read
	mov $0, %rdi 		# file handle 0 is stdin
	mov $message, %rsi 	# address of string to output
	mov $13, %rdx 		# number of bytes
	syscall 		# invoke operating system to do the write
	
	# write(1, message, 13)
	mov $1, %rax 		# system call 1 is write
	mov $1, %rdi 		# file handle 1 is stdout
	mov $message, %rsi 	# address of string to output
	mov $13, %rdx 		# number of bytes
	syscall 		# invoke operating system to do the write

	# exit(0)
	mov $60, %rax 		# system call 60 is exit
	xor %rdi, %rdi 		# we want return code 0
	syscall 		# invoke operating system to exit
