import threading
import os
import multiprocessing

def destroyer():
    os.system("./run 100 10000")
    
def main():
    for x in range(multiprocessing.cpu_count()):
        threading.Thread(target=destroyer).start()
    while True:
        destroyer()

if __name__ == "__main__":
    main()