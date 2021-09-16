assert(){
  expected="$1" ##変数を宣言したときには、宣言と=の間に空白を入れてはいけない
  input="$2"

  cc -o 9cc main.c node.c perser.c
  ./9cc "$input" > tmp.s
  cc -o tmp tmp.s
  ./tmp
  actual="$?"

  if [ "$actual" = "$expected" ]; then ##[の後と]の前は一つ空白
    echo "$input => $actual"
  elif [ "$expected" = "error" ]; then
    echo "↑ error message. Input = $input ."
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

assert 21 "5+20-4"
assert 21 " 5 + 20 - 4"
assert error  "5 ++"
assert 0 "5/4 - 1"