import serial
import time
import keyboard

# Open the serial port
ser = serial.Serial('COM4', 9600)  # Replace 'COM4' with your Arduino's serial port

# Initialize variables
protocol_count = 0
received_protocols = ""

while True:
    # Read a line from the serial port              
    line = ser.readline().decode('utf-8').strip()

    # Check if the line contains the button press message       
    if "eens" in line or "oneens" in line:
        print(line)
        received_protocols +=  line + ", "
        protocol_count += 1                  
        keyboard.press_and_release('space')

    if "r" in line:               
        print(line)
        keyboard.press_and_release('r')
        received_protocols = ""  # Reset the string when 'r' is received
        protocol_count = 0           

    if "x" in line:
        print(line)
        keyboard.press_and_release('space')
        received_protocols = ""  # Reset the string when 'r' is received
        protocol_count = 0  

    #Reset alles 
    if protocol_count == 3:
        print("Finished")      
        print("Received Protocols:", received_protocols)

        # Send the received_protocols string to Arduino                                             r rrr            
        ser.write(received_protocols.encode()) 
                 
        protocol_count = 0      
        received_protocols = ""

    time.sleep(0.1)  # Add a short delay to avoid excessive reading
                                