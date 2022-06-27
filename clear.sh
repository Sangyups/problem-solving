#!/bin/bash

number='2'
while [ $number = '2' ]
do
  echo "문제 정보를 입력해주세요."
  read prob

  echo "$prob 이(가) 맞습니까?"
  echo "[1: 예 / 2: 아니오]"
  read number
done

number='2'
while [ $number = '2' ]
do
  echo "출처 사이트를 입력해주세요."
  read site

  echo "$site 이(가) 맞습니까?"
  echo "[1: 예 / 2: 아니오]"
  read number
done

mkdir -p ./src/${site} && cp ./PS/main.cpp ./src/${site}/${prob}.cpp
echo "src/${site}/${prob}.cpp에 저장되었습니다."
git add ./src/${site}/${prob}.cpp
git commit -m "${site}_${prob}.cpp"
git push origin main
echo "${site}/${prob}.cpp 파일 커밋이 완료되었습니다."

cat > ./PS/main.cpp << EOF
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'
#define pii pair<int, int>

typedef long long ll;

using namespace std;

void preproc() {
}

void solution() {
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  preproc();
  solution();
}
EOF
echo "초기화가 완료되었습니다."
