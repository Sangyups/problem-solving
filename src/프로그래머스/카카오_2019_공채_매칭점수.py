import re

titles = {}


def solution(word, pages):
    basic_scores = [0 for _ in range(len(pages))]
    scores = [0 for _ in range(len(pages))]
    linked = [[] for _ in range(len(pages))]

    word_find = re.compile("[a-zA-Z]+")
    link_find = re.compile('<a href="(https://\\S+)"')
    title_find = re.compile('<meta property="og:url" content="(https://\\S+)"')
    for i, page in enumerate(pages):
        candidates = word_find.findall(page)
        for candidate in candidates:
            if candidate.lower() == word.lower():
                basic_scores[i] += 1
        links = link_find.findall(page)
        title = title_find.findall(page)
        titles[title[0]] = i

        for link in links:
            linked[i].append(link)

    answer = -1
    mx_score = -1

    for i in range(len(pages)):
        scores[i] += basic_scores[i]

        for j in linked[i]:
            idx = titles.get(j, None)
            if idx is None:
                continue
            link_score = basic_scores[i] / len(linked[i])
            scores[idx] += link_score

    for i, score in enumerate(scores):
        if score > mx_score:
            answer = i
            mx_score = score

    return answer
