import nltk
from nltk.tokenize import word_tokenize

class Analyzer():
    """Implements sentiment analysis."""
    
    def __init__(self, positives, negatives):
        self.list1 = []
        file1 = open(positives, "r")
        for line in file1:
            if not line.startswith(';'):
            #self.words.add(line.rstrip("\n"))
                line = line.rstrip("\n")
                self.list1.append(line)
        file1.close()
        self.list2 = []
        file2 = open(negatives, "r")
        for line in file2:
            if not line.startswith(';'):
            #self.words.add(line.rstrip("\n"))
                line = line.rstrip("\n")
                self.list2.append(line)
        file2.close()
       
        """Initialize Analyzer."""
        
        # TODO

    def analyze(self, text):
        if __name__ == "__init__":
            __init__(self,positives,negatives)
        tokens = word_tokenize(text.lower())
        
        good_words = 0
        bad_words = 0
        
        
        for i in self.list1:
            for j in tokens:
                if j == i:
                    good_words += 1
        for i in self.list2:
            for j in tokens:
                if j == i:
                    bad_words -= 1     
        for i in tokens:
            print(i)
        sum = good_words + bad_words       
        return sum
    def analyze1(self, text):
        if __name__ == "__init__":
            __init__(self,positives,negatives)
        
        good_words = 0
        bad_words = 0
        for i in self.list1:
            for j in text:
                if j.isalpha():
                    if j.lower() == i:
                        good_words += 1
                       
        for i in self.list2:
            for j in text:
                if j.isalpha():
                    if j.lower() == i:
                        bad_words -= 1
                        
        
        sum = good_words + bad_words
        return float(sum)
    def analyze2(self, text):
        if __name__ == "__init__":
            __init__(self,positives,negatives)
        lul = []
        good_words = 0
        bad_words = 0
        for i in self.list1:
            for j in text:
                if j.isalpha():
                    if j.lower() == i:
                        good_words += 1
                        
        for i in self.list2:
            for j in text:
                if j.isalpha():
                    if j.lower() == i:
                        bad_words -= 1
                        
        
        sum = good_words + bad_words
        lul.append(good_words)
        lul.append(bad_words)
        lul.append(sum)
        return lul