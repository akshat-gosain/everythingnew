#!/usr/bin/env python3

import sys
import subprocess
from pathlib import Path
from colorama import Fore, Style
import os
import json
from datetime import datetime
import hashlib
import time
import resource


class TestCaseChecker:
    def __init__(self,showMessage=True,saveProgress=False,insertDelay=False):
        self._showMessage = showMessage
        self._saveProgress=saveProgress
        self._insertDelay=insertDelay

    def _CheckRollNo(self, rollNo):
        if len(rollNo)!=13:
            print(f"Error: Incorrect roll number {rollNo}. Your roll number must have 13 characters.")
            print("  e.g. 2021A7PS9999G, 2020B4A79999G")
            sys.exit()

    def _CheckAllFilesExist(self,programPath,lab,rollNo,ques,testcase):
        success=True
    
        self._CheckRollNo(rollNo)
        necessaryFiles = [f"{programPath}/{lab}_{ques}_{rollNo}.cpp", f"Testcases/{lab}_{ques}_{testcase}_input.txt", f"Testcases/{lab}_{ques}_{testcase}_output.txt"]
        
        for file in necessaryFiles:
            file_path = Path(file)
            if not file_path.is_file():
                print(f"Error: Unable to find '{file_path}'.")
                success=False
        
        if success==False:
            sys.exit()
        return necessaryFiles


    def _CheckProgram(self,cppFile):
        """
        Check whether program file satisfies some conditions like some header file is not used
        """
        
        programOkay = True
        return programOkay


    def _CompileProgram(self,cppFile,cppOutput):
        compiled=True
        # Command to compile the C++ program 
        compile_command = ["g++", cppFile, "-o", cppOutput] 
         
        # Compile the C++ program 
        compile_process = subprocess.run(compile_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE) 
         
        # Check if the compilation was successful 
        if compile_process.returncode == 0: 
            if self._showMessage==True:
                print(f"{cppFile} compiled successfully.") 
        else: 
            compiled=False
            if self._showMessage==True:
                print("Compilation Error.") 
                print(compile_process.stderr.decode())
        
        return compiled
        

    def _CheckAndGetFileNames(self,programPath,lab,rollNo,ques,testcase):
        cppFile, tcInputFile, tcOutputFile = self._CheckAllFilesExist(programPath,lab,rollNo,ques,testcase)
        cppOutput = f'{programPath}/{lab}_{ques}_{rollNo}'
        mainFile = f'./{lab}_{ques}_Main.cpp'
        return mainFile, cppFile, tcInputFile, tcOutputFile, cppOutput
        

    def _PrintProgramIOdetails(self,memoryLimit,inputFileData,mismatch,output,expectedOutput,error):
        print(f"Program Input:")
        print(inputFileData)
        colorInsert1=f"{Fore.RED}"
        colorInsert2=f"{Style.RESET_ALL}"
        if mismatch!=None:
            output=output[:mismatch]+colorInsert1+output[mismatch]+colorInsert2+output[mismatch+1:]
        print(f"Program Output:")
        print(output)
        if len(error)>0:
            print(error.strip())
            if "std::bad_alloc" in error:
                print(f"The above error could be because your program has exceeded the {Fore.GREEN}memory limit{Style.RESET_ALL} of {Fore.GREEN}{memoryLimit} MB{Style.RESET_ALL}.")
                print("Another reason for the above error could be an incorrectly assigned pointer variable.")
        colorInsert1=f"{Fore.GREEN}"
        colorInsert2=f"{Style.RESET_ALL}"
        if mismatch!=None:
            expectedOutput=expectedOutput[:mismatch]+colorInsert1+expectedOutput[mismatch]+colorInsert2+expectedOutput[mismatch+1:]
        print(f"Expected Output:")
        print(expectedOutput)
        

    def _CheckAndCreateFileAndFolder(self,lab,ques,testcase,programPath):
        folderPath=f"{programPath}/.data"
        if not os.path.exists(folderPath):
            os.makedirs(folderPath)

        filePath = f"{folderPath}/{lab}_{ques}.json"
        
        try:
            with open(filePath, 'r') as file:
                programProgress = json.load(file)
                if not isinstance(programProgress, list):
                    programProgress = []
        except FileNotFoundError:
            programProgress = []
        
        return programProgress,filePath

    def _SaveProgramDetails(self,lab,ques,testcase, programPath, cppFile, inputFileData, expectedOutput, output, success):

        programProgress, filePath = self._CheckAndCreateFileAndFolder(lab,ques,testcase,programPath)
        with open( f"{cppFile}", 'r' ) as f:
            program = f.read()

        sha256_hash = hashlib.sha256()
        sha256_hash.update(program.encode('utf-8'))
        programHash = sha256_hash.hexdigest()

        alreadyPresent=False
        for state in programProgress:
            if state["programHash"]==programHash and state["testcase"]==testcase:
                alreadyPresent=True

        if alreadyPresent==True: #currentStatus is already present in the file.
            return
        
        currentStatus = dict()
        timestamp = datetime.now()
        timestampStr = timestamp.strftime('%Y-%m-%d %H:%M:%S')

        currentStatus["timestamp"]=timestampStr
        currentStatus["program"]=program
        currentStatus["programHash"] = programHash
        currentStatus["testcase"]=testcase
#        currentStatus["input"]=inputFileData
#        currentStatus["expectedOutput"]=expectedOutput
#        currentStatus["actualOutput"]=output
        currentStatus["testcasePassed"]=success
        
        programProgress.append(currentStatus)
        with open(filePath, 'w') as file:
            json.dump(programProgress, file, indent=4)

    def _PrintAndSaveDetails(self,memoryLimit,lab,ques,testcase,programPath,cppFile,tcInputFile,mismatch,output,expectedOutput,error,success):
        if self._saveProgress==True or self._showMessage==True:
            with open( f"{tcInputFile}", 'r' ) as f:
                inputFileData = f.read()
                inputFileData=inputFileData.strip()

        if self._saveProgress==True:
            self._SaveProgramDetails(lab,ques,testcase,programPath, cppFile, inputFileData, expectedOutput, output, success)

        if self._showMessage==True:
            self._PrintProgramIOdetails(memoryLimit,inputFileData,mismatch,output,expectedOutput,error)

    def _CreateMainFile(self,ques,mainFile,cppFile):
        # Step 1: Open the original file and read its content
        with open(f'{ques}_Template.cpp', 'r') as file:
            file_contents = file.read()
        
        # Step 2: Replace the string
        modified_contents = file_contents.replace('__STUDENTPROGRAM__', cppFile)
        
        # Step 3: Write the modified content to a new file
        with open(mainFile, 'w') as file:
            file.write(modified_contents)

    def FileExists(self,fileName):
        file_path = Path(fileName)
        return file_path.is_file()


    def LimitMemory(self, maxsize):
        """Set maximum memory usage for the subprocess."""
        resource.setrlimit(resource.RLIMIT_AS, (maxsize, maxsize))

    def RunExecutable(self, command, inputData, timeout_seconds=4, memory_limit_mb=10):
        """Run an executable with a timeout and memory limit, passing inputData to it."""
        memory_limit_bytes = memory_limit_mb * 1024 * 1024
        stdout, stderr = '', ''
        process = None

        try:
            process = subprocess.Popen(
                command,
                preexec_fn=lambda: self.LimitMemory(memory_limit_bytes),
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                shell=True
            )
            if isinstance(inputData, str):
                inputData = inputData.encode()
            stdout, stderr = process.communicate(input=inputData, timeout=timeout_seconds)
            stdout = stdout.decode()
            stderr = stderr.decode()
        except subprocess.TimeoutExpired:
            stderr = "TimeoutExpired"
            if self._showMessage:
                print("Process killed due to timeout.")
            raise
        except Exception as e:
            stderr = str(e)
            if self._showMessage:
                print(f"An error occurred: {e}")
            raise
        finally:
            if process and process.poll() is None:  # Process is still running
                process.terminate()  # Try to terminate gracefully
                time.sleep(1)  # Give it a moment
                if process.poll() is None:  # Process is still running
                    process.kill()  # Force kill
                    if self._showMessage:
                        print("Process force killed.")

        return stdout, stderr
    
    def RunTestCase(self,lab,rollNo,ques,testcase,timeout,memoryLimit,programPath=".",compileAgain=True):
        success = 0
        message = ""
        
        cppFile = f"{programPath}/{lab}_{ques}_{rollNo}.cpp"
        if not self.FileExists(cppFile):
            if self._showMessage==True:
                print(f"Error: Unable to find '{cppFile}'.")
            return 0,f"Unable to find '{lab}_{ques}_{rollNo}.cpp'"
        
        mainFile,cppFile, tcInputFile, tcOutputFile, cppOutput = self._CheckAndGetFileNames(programPath,lab,rollNo,ques,testcase)


        #Modify the _CheckProgram function to implement additional checks
        programOkay = self._CheckProgram(cppFile)
        if programOkay==False:
            return 0,""
        
        
        self._CreateMainFile(ques,mainFile,cppFile)
        
        if self._insertDelay==True:
            pass
#            self._SaveAndInsertDelay(cppFile)

        
        #Check if the output file exists. Compile program again if output file does not exist.
        output_path = Path(cppOutput)
        if not output_path.is_file() or compileAgain==True:
            compiled = self._CompileProgram(mainFile,cppOutput)
            if compiled == False:
                return 0, "Compilation error."
    
        # Command to execute the compiled program 
        run_command = [f'{cppOutput}'] 

        # Run the compiled program 
        with open( f"{tcInputFile}", 'rb' ) as f:
            inputData = f.read()

        try:
            start_time = time.perf_counter()
#            run_process = subprocess.run(run_command,timeout=timeout,input=inputData, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
            output, error = self.RunExecutable(run_command,inputData,timeout,memoryLimit)
            end_time = time.perf_counter()
            # Get the output and error messages from the program 
#            output = run_process.stdout.decode() 
#            error = run_process.stderr.decode() 
            # Print the output and error messages 

            output = output.strip()
            with open(f"{tcOutputFile}", 'r' ) as f:
                expectedOutput = f.read()
                expectedOutput = expectedOutput.strip()
            
            
            mismatch=None
            if output == expectedOutput:
                success = 1
            else:
                for i,c1,c2 in zip(range(len(expectedOutput)),output,expectedOutput):
                    if c1!=c2:
                        mismatch=i
                        break

            self._PrintAndSaveDetails(memoryLimit,lab,ques,testcase,programPath,cppFile,tcInputFile,mismatch,output,expectedOutput,error,success)
            if self._showMessage==True:
                print(f"Program running time: {end_time - start_time} seconds")
        
        #If the program does not terminate in timeout number of seconds
        except subprocess.TimeoutExpired:
            success=0
            message = f"Testcase {ques}_{testcase} could not complete in {timeout} seconds."
        except Exception as e:
            success=0
            message = str(e)
            message = message.replace(',', '')            

        return success, message

def main():
    if len(sys.argv) != 4:
        print("Error: Some command-line arguments are incorrect.")
        print("Usage: ./RunTestCase.py <Question_number> <YourBitsId> <TestCase_number>")
        print("   eg. ./RunTestCase.py Q1 YourBITSId T1")
        sys.exit()
    ques,rollNo,testcase = [a.upper() for a in sys.argv[1:]]
    lab="L11"
    
    if len(rollNo)!=13:
        print(f"Error: The BITS Id {rollNo} is incorrect. BITS Id must have 13 characters.")
        sys.exit()
    
    checker = TestCaseChecker(showMessage=True,saveProgress=True,insertDelay=False)
    
    timeout = 4  # in seconds
    memoryLimit = 200 # in MB
    programPath = '.'
#    programPath = f'submissions/{lab}_{rollNo}'  #Comment later.
    success, message = checker.RunTestCase(lab,rollNo,ques,testcase,timeout,memoryLimit,programPath,compileAgain=True)
  
    if len(message)>0:
        print(message)
    if success==1:
        print(f"Test Case {testcase} {Fore.GREEN}Passed{Style.RESET_ALL}.")
    else:
        print(f"Test Case {testcase} {Fore.RED}Failed{Style.RESET_ALL}.")
   

if __name__=="__main__":
    main()
