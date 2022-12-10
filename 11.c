#pip install fuzzywuzzy
#pip install python-Levenshtein


from fuzzywuzzy import fuzz
from fuzzywuzzy import process

res = []

inp = input("Enter word: ")
filename = input("Enter file name: ")

f = open(filename, 'r')


for line in f.readlines():
  word = line.rstrip('\n')

  matchval = fuzz.ratio(inp, word)

  if (matchval >= 50):
    res.append(word)

print(res)
