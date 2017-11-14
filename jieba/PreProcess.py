from string import punctuation
import re
import sys
#import importlib
#importlib.reload(sys)
#sys.setdefaultencoding('utf-8')

#import codecs

# 英文标点符号+中文标点符号
punc = punctuation + u'.,;《》？！“”‘’@#￥%…&×（）——+【】{};；●，。&～、|\s:：'

print(punc)

fr = open('../cppjieba/build/newsR.txt', encoding='utf-8')
fw = open('../cppjieba/build/newsPre.txt', 'w', encoding='utf-8')

# 利用正则表达式替换为一个空格
for line in fr:
    line = re.sub(r"[{}]+".format(punc), " ", line)
    fw.write(line + ' ')

fr.close()
fw.close()