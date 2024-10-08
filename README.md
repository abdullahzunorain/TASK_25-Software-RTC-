## Task 25: Software RTC (Real-Time Clock)

#### Overview
This task involves implementing a **software-based real-time clock (RTC)** without using an external RTC chip. The software RTC will work as long as the system is powered on, and it will be lost after power-off or reset. This design is often used in systems with time synchronization features (e.g., syncing with mobile devices or the internet).

#### Instructions

1. **Timer Interrupt for One Second:**
   - Set up a **timer interrupt** that occurs every **one second**.
   - Use counters or the timer to generate a precise 1-second interrupt.

2. **Define a Time Structure:**
   - Create a structure called `__time` (since `time` might be a reserved keyword).
   - The structure should include variables for **seconds, minutes, hours, days, months, and years**.

3. **Time Incrementing in ISR:**
   - In the **timer interrupt service routine (ISR)**, increment the **seconds** variable.
   - If **seconds == 60**, reset it to 0 and increment the **minutes** variable.
   - Similarly, increment **minutes, hours, days**, and so on, adjusting the time fields as needed.
   - Handle **leap years** for February (29 days) using the appropriate formula:
     - A year is a leap year if it is divisible by **4**, but years divisible by **100** are **not** leap years unless they are also divisible by **400**.
   - Use an array to store the number of days in each month.

4. **Display Time on LCD:**
   - Display the **current time** from the software RTC on a **16x2 LCD**.
   - Ensure the screen updates every second without **flickering**.

5. **Serial Time Setting:**
   - Port the code from previous tasks so that the **time on the software RTC** can be set via the **serial port** from a **PC**.
   - Implement functions to set the time fields (seconds, minutes, etc.) by receiving data through the serial interface.

6. **Dual RTC Display and Time Comparison:**
   - Modify the program to display both:
     - **Software RTC time** on the **first line** of the 16x2 LCD.
     - **DS1302 hardware RTC time** on the **second line** of the 16x2 LCD.
   - Sync your PC's time with an **NTP server** and set the time on **both RTCs** from the PC via the serial port.
   - Let the system run for **24 hours**.
   - After 24 hours, sync the PC time with the NTP server again and **compare the drift** in time between the software RTC, DS1302 RTC, and the accurate time from the PC.
     - Refer to [this video](https://www.youtube.com/watch?v=xPEKM3zcOaA) to learn how to sync your PC time with the server.

7. **RTC Error Compensation (Optional):**
   - Though we won’t implement it in this training, you can explore **RTC error compensation**:
     - This involves calibrating the software RTC based on an **accurate external timing signal** and **temperature drift compensation**.
     - The **11.0592 MHz crystal** on the STC development kit has some **frequency offset**, which changes with temperature.
     - Adjustments like counting **990 ms** or **1020 ms** (instead of 1000 ms) can be made depending on the crystal's deviation due to temperature.
     - This is a complex task and takes days of testing, but you can attempt it if you want to explore more.

---
