# Initialize the digital pins where the LEDs are connected as output
pinMode(D2,OUTPUT)
pinMode(D3,OUTPUT)
pinMode(D4,OUTPUT)

# Define the 'blink' function to be used by the threads
# timeON and timeOFF are optional parameters, used as default if not specified when you call the function
def blink(pin,timeON=100,timeOFF=100):                                          
    while True:
        digitalWrite(pin,HIGH)   # turn the LED ON by making the voltage HIGH
        sleep(timeON)            # wait for timeON 
        digitalWrite(pin,LOW)    # turn the LED OFF by making the voltage LOW
        sleep(timeOFF)           # wait for timeOFF 

# Create three threads that execute instances of the 'blink' function. 
thread(blink,D2)               # D2 is ON for 100 ms and OFF for 100 ms, the default values of timeON an timeOFF
thread(blink,D3,200)         # D3 is ON for 200 ms and OFF for 100 ms, the default value of timeOFF
thread(blink,D4,500,200)   # D4 is ON for 500 ms and OFF for 200 ms