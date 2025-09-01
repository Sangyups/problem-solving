#!/bin/bash

ask_and_confirm() {
    local question="$1"
    local response
    local confirm

    while true; do
        # Ask the question
        read -e -r -p "$question " response

        # Confirm the answer
        read -e -r -p "'$response' (이)가 맞습니까? ([y]/n) " confirm
        confirm=${confirm:-y}

        if [[ "$confirm" =~ ^[Yy]$ ]]; then
            break
        fi
    done

    echo "$response"
}

prob=$(ask_and_confirm "문제 정보를 입력해주세요:")
lang=$(ask_and_confirm "언어 종류를 입력해주세요:")
site=$(ask_and_confirm "출처 사이트를 입력해주세요:")

mkdir -p ./src/${site} && cp ./main.${lang} ./src/${site}/${prob}.${lang}
echo "src/${site}/${prob}.${lang}에 저장되었습니다."
git add ./src/${site}/${prob}.${lang}
git commit -m "${site}_${prob}.${lang}"
git push origin main
echo "${site}/${prob}.${lang} 파일 커밋이 완료되었습니다."

sh init.sh
