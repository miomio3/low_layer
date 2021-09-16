.intel_syntax noprefix
.global main
main:
  push 5
  push 4
  pop rdi
  pop rax
  cqo
  idiv rdi
push rax
  push 1
  pop rdi
  pop rax
  sub rax, rdi
push rax
  pop rax
  ret
