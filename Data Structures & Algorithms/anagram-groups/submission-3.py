class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res_map: Dict[Tuple[int], Set[str]] = {}

        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1
            res_map[tuple(count)] = res_map.get(tuple(count), [])
            res_map[tuple(count)].append(s)

        return list(res_map.values())