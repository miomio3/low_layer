.intel_syntax noprefix
.global main
main:
  push 0
  push 5
  pop rdi
  pop rax
  sub rax, rdi
push rax
  push 20
  pop rdi
  pop rax
  add rax, rdi
push rax
  push 4
  pop rdi
  pop rax
  sub rax, rdi
push rax
  pop rax
  ret
