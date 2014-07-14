
import os
from subprocess import Popen, PIPE
from subprocess import call
import traceback

class Environment(object):

    SERVERS = {
        "rachel and matt" : "Rachel-And-Matt\\server.bat"
        }
    
    def __init__(self, print):
        self.print = print

    def _process(self, message):
        self._run(message)

    def _run(self, command):
        try:
            exec(command)
        except Exception as error:
            self.print(traceback.format_exc())

    def help(self):
        commands = ["self.system", "self.runBatchScript",
                    "self.runBatchFile",
                    "self.runScript", "self.listScripts",
                    "self.runServer", "self.listServers"]
        self.print("\n Commands:")
        self.print("--------------")
        for command in commands:
            self.print(command)

    def system(self, command):
        value = os.system(command)
        return value

    def runBatchFile(self, batchFilepath):
        file = batchFilepath
        if os.path.exists(file):
            Popen(file)
        else:
            self.print("Batch script of the filename '{}' does not exist.".format(file))
    def runBatchScript(self, batchFilename):
        file = "remote-control-scripts\\" + batchFilename
        self.runBatchFile(file)
        
    def runScript(self, scriptFilename):
        file = "remote-control-scripts/" + scriptFilename
        if os.path.exists(file):
            exec(open(file, "r").read())
        else:
            self.print("Script of that filename does not exist.")
    def listScripts(self):
        value = glob.glob("remote-control-scripts/*")
        self.print(value)
        return value

    def runServer(self, serverName):
        if serverName.lower() in self.SERVERS:
            self.runBatchFile(self.SERVERS[serverName])
            
    def listServers(self):
        self.print("\n Servers:")
        self.print("--------------")
        for key in self.SERVERS.keys():
            self.print(key)
            
