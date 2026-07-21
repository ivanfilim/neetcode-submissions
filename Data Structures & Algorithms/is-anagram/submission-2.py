class Solution:
    def anagramDict(self, s: str) -> dict[str, int]:
        res = {}
        for c in s:
            res[c] = res.get(c, 0) + 1
        return res
    def isAnagram(self, s: str, t: str) -> bool:
        return self.anagramDict(s) == self.anagramDict(t)