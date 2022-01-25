from pickle import TRUE
import socket
import sys
HOST = ''
PORT = 9200

soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    # With the help of bind() function 
    # binding host and port
    soc.bind((HOST, PORT))
       
except socket.error as message:
      
    # if any error occurs then with the 
    # help of sys.exit() exit from the program
    print('Bind failed. Error Code : ' 
          + str(massage[0]) + ' Message ' 
          + massage[1])
    sys.exit()
      
# print if Socket binding operation completed    
print('Socket binding operation completed')

# With the help of listening () function
# starts listening

soc.listen(9)
conn, address = soc.accept()
print('Connected with ' + address[0] + ':' 
          + str(address[1]))

while(TRUE):
    print("Got message: " + conn.recv(1024).decode())