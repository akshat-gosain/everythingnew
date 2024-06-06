#!/usr/bin/env python3

"""
CreateSubmission.py file should NOT be edited in ANY manner.
If you edit this program, it will be considered a malpractice and STRICT action will be taken.
"""

import os
import sys
from datetime import datetime
import socket
import netifaces
import json
import zipfile
import fcntl
import struct
import shutil
from colorama import Fore, Style


class CreateSubmission:
    def __init__(self,lab,rollNo):
        self._d = dict()
        self._d["1"]=lab
        self._d["2"]=rollNo
        self._Get3()
        self._Get45()
        self._Get6()
        self._Get7()
        self._GetProgress()
        self._SaveSubmissionInfo()
        self._CreateZip()
        self._DeleteTempFiles()

    def _Get3(self):
        d = self._d
        l,r = d["1"],d["2"]
        f = []
        for i in range(10):
            file=f"{l}_Q{i}_{r}.cpp"
            if os.path.isfile(file):
                f.append(file)
        d["3"]=f
            
    def _Get45(self):
        d = self._d
        cd = datetime.today().date()
        d["4"] = cd.strftime("%d/%m/%Y")

        ct = datetime.today().time()
        d["5"] = ct.strftime("%H:%M:%S")


    def _Get6(self):
        d=self._d
        i4="NF"
        try:
            interfaces = netifaces.interfaces()
            for interface in interfaces:
                addresses = netifaces.ifaddresses(interface).get(netifaces.AF_INET)
                if addresses:
                    for address_info in addresses:
                        addr = address_info['addr']
                        if addr != '127.0.0.1':
                            i4=addr
                            break
                if i4!="NF":
                    break
        except (socket.error, ValueError) as e:
            pass
        d["6"]=i4
    
    def _Get7(self):
        d=self._d
        m="NF"
        for nam in ["enp1s0","enp3s0","enp2s0","eno1"]:
            try:
                s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                info = fcntl.ioctl(s.fileno(), 0x8927,  struct.pack('256s', bytes(nam, 'utf-8')[:15]))
                m = ':'.join('%02x' % b for b in info[18:24])
                break
            except Exception as e:
                pass
        d["7"]=m

    def _GetProgress(self):
        d=self._d

        l,r = d["1"],d["2"]
        f = []
        for i in range(10):
            sourceFile=f".data/{l}_Q{i}.json"
            if os.path.isfile(sourceFile):
                destFile=f"./{l}_Q{i}.json"
                shutil.copy2(sourceFile, destFile)
                f.append(destFile)

        d["8"]=f
        self._zf=f
    
    def _SaveSubmissionInfo(self):
        d=self._d
        l,r = d["1"],d["2"]
        jf = f"{l}_{r}.json"
        with open(jf, 'w') as j_f:
            json.dump(d,j_f)
        self._zf = d["3"]+self._zf+[jf]

    def _CreateZip(self):
        zf=self._zf
        d=self._d
        
        if len(zf) < 2:
            self._m="Zip file could not be created because some files are missing."
            return
        l,r = d["1"],d["2"]
        zf_name = f"{l}_{r}.zip"
        
        # Open the zip file in write mode ('w')
        with zipfile.ZipFile(zf_name, 'w') as zfh:
            # Add each file to the zip file
            for f in zf:
                zfh.write(f)
        
        self._m=f"Zip file '{zf_name}' created successfully.\nUpload '{zf_name}' on local Quanta (https://quanta.bits-goa.ac.in/)."

    def _DeleteTempFiles(self):
        zf=self._zf
        d=self._d
        cppFileNo = len(d["3"])
        for f in zf[cppFileNo:]:
            os.remove(f)
    
    def ShowMessage(self):
        d=self._d
        zf=self._zf
#        l,r = d["1"],d["2"]
        if len(zf)>len(d["3"]) and len(zf)>=2:
            print(f'The following {Fore.GREEN}{len(d["3"])}{Style.RESET_ALL} files were added to the zip file:')
            i=0
            for f in zf[:len(d["3"])]:
                i+=1
                print(f'{i}. {Fore.GREEN}{f}{Style.RESET_ALL}')
            print(self._m)
        else:
            if len(d["3"])==0:
                print("Error : cpp files are missing.")
            else:
                print("Error : Some files are missing.")
            print(self._m)

def main():
#    print("Warning : ./CreateSubmission.py file should NOT be edited in ANY manner. If you edit this file, it will be considered malpractice and strict action will be taken.\n")
    if len(sys.argv) != 2:
        print("Error: Some command-line arguments are incorrect.")
        print("Usage: ./CreateSubmission.py <YourBitsId>")
        print("   eg. ./CreateSubmission.py YourBITSId")
        sys.exit()
    rollNo = sys.argv[1] #[a.upper() for a in sys.argv[1:]]
    lab="L11"
    
    if len(rollNo)!=13:
        print(f"Error: The BITS Id {rollNo} is incorrect. BITS Id must have 13 characters.")
        sys.exit()
    if not (lab[0]=="L" and lab[1:] in ["1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"]):
        print(f"Error: The lab number {lab} is incorrect. Examples of correct lab numbers : L1, L2, L3, etc.")
        sys.exit()
    
    labSub = CreateSubmission(lab,rollNo)
    labSub.ShowMessage()
    
   

if __name__=="__main__":
    main()
