# -*- coding: utf-8 -*-
"""
Created on Tue Jul  4 10:22:04 2023

@author: 苏小洲suxiaozhou
"""
import random
text=open("sort+quqian20.in",'w');
text.write("");
text.close();
text=open("sort+quqian20.in",'a');
for i in range(1,1000000):
    text.write(str(random.randint(0,pow(2,31)-1))+" ")
text.write(str(random.randint(0,pow(2,31)-1)))
text.close()