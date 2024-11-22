#!/bin/python3

# This is not great code, but it's good enough to reformat 90% of the adocs

import argparse
import os
import sys
import re

class Lesson_Step_Activity():

    def __init__(self, lsa_dir):
        self.lsa_info = {}
        try:
            lsa = os.scandir(lsa_dir)
            for file in lsa:
                if "_content.adoc" in file.name:
                    self.lsa_content_file = file.path
                    with open(file.path, "r") as file:
                        try:
                            self.lsa_info["media_dir"] = re.search(":localmediadir: (.+)", file.read()).groups(1)[0]
                        except AttributeError:
                            pass
                else:
                    try:
                        with open(file.path, "r") as lsa_td_info:
                            # removes prepended underscore reads in to dict
                            self.lsa_info[file.name[1:]] = lsa_td_info.read()
                    except IsADirectoryError:
                        #TODO something else
                        pass 
            self.lsa_info["lsa_title"] = self.lsa_info["title"]
            result =  re.search("_lsa_([a-zA-Z0-9]+)_(.+)", lsa_dir.name)
            self.lsa_info["title"] = result.group(2)
            self.order = result.group(1)
        except FileNotFoundError:
            print(f"{lsa_dir} doesn't exist")
        print(self.lsa_info)

class Lesson():

    def __init__(self, lesson_dir: str):
        try:
            dir_obj = os.scandir(lesson_dir)    
            for file in dir_obj:
                if "_content" in file.name:
                    self.content_dir = file
                if "_media" in file.name:
                    self.media_dir = file
                if "_info" in file.name:
                    self.info_dir = file
        except FileNotFoundError:
            print(f"{lesson_dir} does not exist")

if __name__ == "__main__":
    PARSER = argparse.ArgumentParser(description='Process some integers.')
    PARSER.add_argument('lesson_dir', help='lesson directory')
    PARSER.add_argument('output_dir',default="output",
                         help='name of output directory')

    ARGS = PARSER.parse_args()
    lesson = Lesson(ARGS.lesson_dir)
    lsas = []
    try:
        for lsa in os.scandir(lesson.content_dir):
            lsas.append(Lesson_Step_Activity(lsa))
    except NotADirectoryError:
        sys.exit(1)
    
    lsas.sort(key=lambda x: x.order)
    print("building LSAs:")
    for i in lsas:
        print(i.lsa_info["title"])

    try:
        os.mkdir(ARGS.output_dir)
        os.mkdir(ARGS.output_dir + "/" + "_assets")
    except FileExistsError:
        pass

    count = 0
    for lsa in lsas:
        outfile = ARGS.output_dir + "/" + f"{count:02d}_" + lsa.lsa_info["title"] + ".md"
        try:
            os.system(f"asciidoc -b docbook -o temp.xml {lsa.lsa_content_file}")
            os.system(f"pandoc -f docbook -t markdown_strict --atx-headers temp.xml -o {outfile}")
            #print(f"asciidoc -b docbook -o temp.xml {lsa.lsa_content_file}")
            #print(f"pandoc -f docbook -t markdown_strict temp.xml -o {outfile}")
            os.remove("temp.xml")
            result = ""
            with open(outfile, "r+") as file:
                text = file.read()
                result = re.sub(r'image::.+?/([^/\n]+)\[.*?\]', fr'![](_assets/{lsa.lsa_info["title"]}/\1)', text, flags=re.DOTALL)
                result = re.sub(r'\\\)', r')', result)
                result = re.sub(r'# ', r'## ', result)
                result = re.sub(r':!exercise:', r'', result)
            with open(outfile, "w") as file:
                file.write(result)
                try:
                    file.write("\n## Check On Learning\n\n")
                    file.write(f"{lsa.lsa_info['check_on_learning']}\n")
                except KeyError:
                    pass

                try:
                    file.write("\n## Outcome\n\n")
                    file.write(f"{lsa.lsa_info['outcome']}\n")
                except KeyError:
                    pass

                file.write("""
\n## Admin Information

| attribute | value |
| --- | --- |\n""")
                for key, value in lsa.lsa_info.items():
                    if (("check_on_learning" not in key) and ("outcome" not in key)):
                        file.write(f"| {key} | {value} |\n")
        except AttributeError as error:
            print(f"[!] Failed to parse LSA: {lsa.lsa_info['title']}")
            print(error)
            pass
        count += 1