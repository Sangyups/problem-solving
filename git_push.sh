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
  echo "언어 종류를 입력해주세요."
  read lang

  echo "$lang 이(가) 맞습니까?"
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

mkdir -p ./src/${site} && cp ./main.${lang} ./src/${site}/${prob}.${lang}
echo "src/${site}/${prob}.${lang}에 저장되었습니다."
git add ./src/${site}/${prob}.${lang}
git commit -m "${site}_${prob}.${lang}"
git push origin main
echo "${site}/${prob}.${lang} 파일 커밋이 완료되었습니다."

sh init.sh

