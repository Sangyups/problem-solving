import heapq
from collections import defaultdict
from dataclasses import dataclass


@dataclass
class Node:
    cnt: int
    word: str

    def __lt__(self, other):
        if self.cnt == other.cnt:
            return self.word > other.word
        else:
            return self.cnt < other.cnt


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        word_freqs = defaultdict(int)
        for word in words:
            word_freqs[word] += 1
        pq = []
        for key, val in word_freqs.items():
            new_node = Node(val, key)
            if len(pq) < k:
                heapq.heappush(pq, new_node)
            else:
                if pq[0] < new_node:
                    heapq.heappop(pq)
                    heapq.heappush(pq, new_node)
        print(pq)
        answer = []
        while pq:
            node = heapq.heappop(pq)
            answer.append(node.word)
        answer.reverse()
        return answer
