import serial
import csv
import time

# 🔹 1. Setup Serial (Confirm COM3 is correct in Device Manager)
try:
    ser = serial.Serial('COM3', 115200, timeout=1)
    time.sleep(2) 
    print("Connection Successful!")
except Exception as e:
    print(f"Error: Could not open COM port. {e}")
    exit()

# 🔹 2. Create CSV File
file = open("sensor_data.csv", mode="w", newline="")
writer = csv.writer(file)

# Write Header
writer.writerow(["Humidity", "DHT_Temp", "Ambient_Temp", "Object_Temp", "Red", "Green", "Blue", "Infection"])

print("Reading data... Press Ctrl+C to stop.")

while True:
    try:
        line = ser.readline().decode('utf-8').strip()
        
        if line:
            # Split the data
            parts = line.split(",")

            # 🔹 FIX: Your terminal shows 7 values, so we check for 7
            if len(parts) == 7:
                hum, dhtTemp, ambTemp, objTemp, r, g, b = map(float, parts)

                # --- LOGIC FOR INFECTION ---
                # Based on your data, if Object Temp > 37 or Red > 150, set to 1
                if objTemp > 37.0 or r > 150:
                    infection = 1
                else:
                    infection = 0

                # --- PRINT TO TERMINAL ---
                print(f"Data Received: Temp={objTemp}, Red={r}, Infection={infection}")

                # --- SAVE TO CSV ---
                writer.writerow([hum, dhtTemp, ambTemp, objTemp, r, g, b, infection])
                file.flush() # This saves the file immediately
            else:
                print(f"Wrong data format (needs 7 values): {line}")

    except KeyboardInterrupt:
        print("Stopping...")
        break
    except Exception as e:
        print(f"Error: {e}")

file.close()
ser.close()