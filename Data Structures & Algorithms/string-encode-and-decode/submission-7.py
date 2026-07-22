class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res += str(len(s)) + "!" +  s
        return res

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        while i < len(s):
            l = ""
            while s[i] != "!":
                l += s[i]
                i += 1
            n = int(l)
            currStr = ""
            for j in range(n):
                i += 1
                currStr += s[i]
            res.append(currStr)
            i += 1
        return res
            

