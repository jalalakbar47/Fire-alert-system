import time
import random

def check_for_fire():
    # Simulate temperature sensor values (in Celsius)
    temperature = random.uniform(25, 100)  # simulate temperature
    print(f"Temperature Reading: {temperature:.2f}°C")
    return temperature > 60  # Trigger alert if temp > 60°C

def send_sms_alert():
    print("🔥 ALERT: High temperature detected! Sending SMS...")
    time.sleep(1)
    print("📱 SMS sent to emergency contact!")

def make_emergency_call():
    print("📞 Initiating emergency call to fire services...")
    time.sleep(1)
    print("📞 Call connected. Location sent.")

def fire_alert_system():
    print("🚨 Fire Alert System Initialized.")
    print("Monitoring for heat spikes...\n")

    for _ in range(5):  # Simulate 5 sensor checks
        time.sleep(2)
        if check_for_fire():
            send_sms_alert()
            make_emergency_call()
            break
        else:
            print("✅ Temperature normal.\n")
    else:
        print("✔️ No fire detected during monitoring.")

if __name__ == "__main__":
    fire_alert_system()