from asyncio import subprocess


import subprocess
from sys import stdout

def check():
    output = subprocess.Popen(["cmd", "/C", "date"], stdout=subprocess.PIPE).communicate()[0]
    return output

print("hello")
print(check())