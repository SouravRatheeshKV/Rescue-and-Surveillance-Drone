# 📟 Arduino Code – Rescue & Surveillance Drone System

This Arduino program is part of the **Rescue and Surveillance Drone for Women Safety** project.
It integrates **GPS, GSM, OLED display, and push buttons** to send emergency alerts with real-time location.

---

## 🔧 Features

* 📍 **GPS Location Tracking** using Neo-6M module
* 📩 **SMS Alert System** using GSM SIM800L
* ⚠️ **Two Alert Modes**

  * **Minor Alert** → Sends location for monitoring
  * **Major Alert** → Sends emergency alert
* 🖥️ **OLED Display Feedback**
* 🔘 **Push Button Trigger System**
* 💬 **Google Maps Link generation**

---

## ⚙️ Components Used

* Arduino Nano
* GSM SIM800L Module
* GPS Neo-6M Module
* OLED Display (SSD1306)
* Push Buttons (2)
* 3.7V Battery

---

## 🔌 Pin Configuration

| Component    | Arduino Pin        |
| ------------ | ------------------ |
| GSM TX/RX    | 6, 7               |
| GPS TX/RX    | 3, 4               |
| Minor Button | 8                  |
| Major Button | 9                  |
| OLED (I2C)   | A4 (SDA), A5 (SCL) |

---

## 🚀 Working Principle

1. System initializes GSM, GPS, and OLED display
2. OLED displays instructions to user
3. Arduino continuously monitors button inputs
4. When a button is pressed:

   * GPS fetches current location
   * GSM sends SMS with:

     * Issue type (Minor/Major)
     * Latitude & Longitude
     * Google Maps link
5. OLED updates alert status

---

## 📩 SMS Format

Example message sent:

```
Issue Type : Major
Latitude: 12.971598
Longitude: 77.594566
https://www.google.com/maps?q=12.971598,77.594566
```

---

## 🖥️ OLED Display Output

* Displays system instructions on startup
* Shows alert type when button is pressed

---

## 💡 Special Features

* Real-time emergency alert system
* Works without internet (uses GSM network)
* Generates direct Google Maps link for quick access
* Simple and fast response mechanism

---

## ⚠️ Notes

* Replace the phone number in code:

  ```
  +916282824876
  ```

  with your own number

* GPS may take time to get initial signal (cold start)

* Ensure proper power supply for GSM module

---

## 🚧 Limitations

* Depends on GSM network availability
* GPS signal delay in indoor environments
* Battery backup required for continuous usage

---

## 🔮 Future Improvements

* Mobile app integration
* Live tracking instead of SMS
* AI-based threat detection
* Cloud data logging

---

## 🧪 Status

✅ Tested successfully
✅ SMS alert working
✅ GPS location tracking working
✅ OLED display functioning

---

## 📌 Summary

This Arduino code acts as the **core controller** of the safety system, enabling fast and reliable emergency communication using embedded hardware components.
