class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        freq = [0]*26
        for l in s:
            freq[ord(l) - ord('a')]+=1
        
        for x in freq:
            print(x)
    