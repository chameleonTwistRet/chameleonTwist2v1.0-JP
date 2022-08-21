import os
import json
from datetime import date as ddate, datetime
from collections import OrderedDict
from matplotlib import pyplot as plot
import matplotlib.dates as mpl_dates
import matplotlib.ticker as mticker
import numpy as np
import pandas as pd

class Badge:
    def __init__(self, id: str, label: str, message: str, color: str):
        self.id = id
        self.label = label
        self.message = message
        self.color = color
        self.storeBadge()

    def __str__(self):
        return '{ "schemaVersion": 1, "label": "%s", "message": "%s", "color": "%s" }' % (self.label, self.message, self.color)

    def storeBadge(self):
        """ Stores badge information in json file """
        with open("../assets_for_repo/badges/%s.json" % self.id, "w") as json_file:
            s = json.loads(str(self))
            json.dump(s, json_file)
            json_file.close()
        return

    def getHTML(self):
        return '<img src=\"https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/chameleonTwistRet/chameleonTwist2v1.0-JP/master/assets_for_repo/badges/%s.json&style=\'plastic\'\"/>' % self.id


def getPushInfo() -> dict:
    """ Returns a dictionary of push information """
    with open("../assets_for_repo/pushes.json") as json_file:
        data = json.load(json_file)
        json_file.close()
        return data

def getFuncsPerDate(data: dict) -> dict:
    """ Returns a dictionary of functions per date """
    funcsPerDate = {}
    for push in data['pushes']:
        date = push['short_date']
        if date not in funcsPerDate:
            funcsPerDate[date] = 0
        funcsPerDate[date] += int(push['funcs_done'])
    return funcsPerDate

def generateGraph(data: dict) -> None:
    """ Generates a graph of the pushes """
    funcsPerDate = getFuncsPerDate(data)
    funcsPerDate = OrderedDict(sorted(funcsPerDate.items()))

    dateSTRs = list(funcsPerDate.keys())
    dates = [datetime.strptime(date,'%d-%m-%Y') for date in dateSTRs]
    # funcs = list(funcsPerDate.values())       # Tracks funcs per day
    funcs = np.cumsum(list(funcsPerDate.values()))

    plot.plot_date(dates, funcs, linestyle='solid')
    date_format=mpl_dates.DateFormatter("%b, %d %Y")
    plot.gcf().autofmt_xdate()
    plot.gca().xaxis.set_major_formatter(date_format)
    plot.gca().set_ylim([0, data['project']['total_funcs']])

    plot.title('Functions Complete Over Time')
    plot.xlabel('Date')
    plot.ylabel('Completed Functions')

    # always show max value on y-axis
    yt1 = plot.gca().get_yticks()
    yt = yt1[:-1]
    yt = [ int(x) for x in yt ]
    yt = np.append(yt, data['project']['total_funcs'])
    ytl = yt.tolist()
    ytl[-1] = "%d" % data['project']['total_funcs']
    plot.gca().set_yticks(yt)
    plot.gca().set_yticklabels(ytl)

    # Make responsive
    plot.tight_layout()
    plot.savefig("../assets_for_repo/graph.png")
    return

def getCompletionPercentage(data: dict) -> float:
    """ Returns the completion percentage of the project and color """
    perc = (data['project']['funcs_done'] / data['project']['total_funcs'])*100
    if perc <= 25:
        color = "#990000"
    elif perc > 25 and perc <= 50:
        color = "#ff9900"
    elif perc > 50 and perc <= 75:
        color = "#ffff00"
    else:
        color = "#009900"
    perc = "{0:.2f}".format(perc)
    return perc, color

def writeReadMe(data: dict) -> None:
    """ Writes readme with graph and badges """
    with open("../README.md", "w") as readme:
        readme.write("# ChameleonTwist2v1.0-JP\n")

        comBadge = Badge("compiler", "Compiler", "IDO 5.3", "#FFAE42")
        readme.write("\n")
        readme.write(comBadge.getHTML() + "\n\n")
        shaBadge = Badge("sha", "SHA", "b60d0347e7b765195fb27c3ee50a806ea9977dca", "#aa0000")
        readme.write("\n")
        readme.write(shaBadge.getHTML() + "\n")
        readme.write("\n")

        readme.write("## Progress Info\n")
        readme.write("![Graph](assets_for_repo/graph.png)\n")
        funcsBadge = Badge("funcs", "Functions Done", "%d" % data['project']['funcs_done'], "#9932CC")
        readme.write(funcsBadge.getHTML() + "\n")
        completeBadge = Badge("completion", "Complete", "%s%%" % getCompletionPercentage(data)[0], getCompletionPercentage(data)[1])
        readme.write(completeBadge.getHTML() + "\n")

        readme.write("## Building\n")
        readme.write("""git clone this repository in a WSL 2 directory

Requirements (for debian based systems only currently)
`./install.sh`

Place a vanilla japanese chameleon twist 2 rom (v1.0) in the root directory named `baserom.z64`
\nRun `make setup` to split the rom, then run `make -j` to build the rom
`make clean` will clean the asm/ assets/ and build/ directories\n""")

        readme.write("## Contributing\n")
        readme.write("When Pushing run `cd tools` then `python3 create_repo_assets.py` to update the information and then push. REMEMBER to `cd ..` back to the root before pushing\n")
        return

def findNewDoneFuncs(data: dict) -> int:
    """ Finds new functions added to the project """
    INITIAL_FUNCS = 26
    unsolved = 0
    for file in os.listdir("../src"):
        with open("../src/%s" % file, "r") as f:
            for line in f:
                if "#pragma" in line:
                    unsolved += 1
            f.close()
    solved = data['project']['total_funcs'] - unsolved
    return solved - data['project']['funcs_done'] + 26

def findNewDoneFiles(data: dict) -> int:
    """ Finds new functions added to the project """
    count = 0
    flag = True
    for file in os.listdir("../src"):
        with open("../src/%s" % file, "r") as f:
            for line in f:
                if "#pragma" in line:
                    flag = False
            if flag:
                count += 1
            f.close()
        flag = True
    return count - data['project']['files_done']

def storePush(data: dict) -> dict:
    """ Stores push information in json file """
    short_date = str(ddate.today()).split('-')
    date = str(datetime.now().isoformat())
    funcs_done = findNewDoneFuncs(data)
    files_done = findNewDoneFiles(data)

    data['pushes'].append({
        'date': date,
        'short_date': short_date[2]+"-"+short_date[1]+"-"+short_date[0],
        'funcs_done': funcs_done,
        'files_done': files_done,
    })
    data['project']['funcs_done'] = data['project']['funcs_done'] + funcs_done
    data['project']['files_done'] = data['project']['files_done'] + files_done

    with open("../assets_for_repo/pushes.json", "w") as json_file:
        json.dump(data, json_file)
        json_file.close()

    return data

if __name__ == "__main__":
    data = getPushInfo()
    data = storePush(data)
    writeReadMe(data)
    generateGraph(data)
