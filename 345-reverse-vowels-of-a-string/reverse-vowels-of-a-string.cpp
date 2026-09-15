class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            // i ko next vowel tak le jao
            while (i < j && !isVowel(s[i])) {
                i++;
            }

            // j ko previous vowel tak le jao
            while (i < j && !isVowel(s[j])) {
                j--;
            }

            // vowels swap
            swap(s[i], s[j]);

            i++;
            j--;
        }

        return s;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' ||
               c == 'O' || c == 'U';
    }
};