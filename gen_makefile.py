''' Cette fichier genere Makefile à partir des JSON.
    le syntax est décire le projet est simple.
    EX:
'''
import os
import sys
import json

def valideNameJson(name):
    return name[-4:] == "json"

def getDictionary(fileName):
    fileToRead = open(fileName,"r")
    if not valideNameJson(fileName): return
    data = fileToRead.read()
    data = json.loads(data)
    fileToRead.close()
    return data
def appendToFile(name,data):
    fileToWrite = open(name,"a")
    fileToWrite.write(str(data))
    fileToWrite.close()

def getGenObj(objList):
    res = ""
    for objName in objList:
        res += "obj/%.o: "
        res += objName + "\n"
        res += "    " + "@mkdir -p obj\n"
        res += "    " + "@echo $@ $<\n"
        res += "    " + "@$(CC) $(CPP_FLAGS) -c $(INCLUDE_DIR) -o $@  $<\n\n"
    return res

def makeProjects(projetFile,dependance_h,dependance_cpp):
    print("hello")

data = getDictionary("data.json")
dependances_h = data["dependance_h"]
dependances_cpp = data["dependance_cpp"]
projects = data["projects"]
appendToFile("test",getGenObj(data["gen_obj"]))
