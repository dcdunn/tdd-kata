# Soundex

From [wikipedia](https://en.wikipedia.org/wiki/Soundex):

"Soundex is a phonetic algorithm for indexing names by sound,
as pronounced in English".

Each word is transformed to another word, which is a letter,
followed by three digits. Words that sound alike encode to 
same soundex representation. For example, "Dunn", "Dunne", "Donne",
"Doon", "Dun", "Done", "Doom", "Dome" are all indexed by "D500".

The algorithm for generating the index is:

 1. Retain the first letter of the name and drop all other occurrences of a, e, i, o, u, y, h, w.

 2. Replace consonants with digits as follows (after the first letter):
   * b, f, p, v -> 1
   * c, g, j, k, q, s, x, z -> 2
   * d, t -> 3
   * l -> 4
   * m, n -> 5
   * r -> 6

 3. If two or more letters with the same number are adjacent in the original name (before step 1), only retain the first letter; also two letters with the same number separated by 'h' or 'w' are coded as a single number, whereas such letters separated by a vowel are coded twice. This rule also applies to the first letter.

 4. If you have too few letters in your word that you can't assign three numbers, append with zeros until there are three numbers. If you have more than 3 letters, just retain the first 3 numbers.