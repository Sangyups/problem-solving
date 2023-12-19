#!/bin/bash

number='2'
while [ $number != '1' ]
do
  echo "문제 정보를 입력해주세요."
  read prob

  echo "$prob 이(가) 맞습니까?"
  echo "[1: 예 / 2: 아니오]"
  read number
done

number='2'
while [ $number != '1' ]
do
  echo "출처 사이트를 입력해주세요."
  read site

  echo "$site 이(가) 맞습니까?"
  echo "[1: 예 / 2: 아니오]"
  read number
done

mkdir -p ./src/${site} && cp ./main.go ./src/${site}/${prob}.go
echo "src/${site}/${prob}.go에 저장되었습니다."
git add ./src/${site}/${prob}.go
git commit -m "${site}_${prob}.go"
git push origin main
echo "${site}/${prob}.go 파일 커밋이 완료되었습니다."

sh init.sh

