# ESP8266 WiFi Captive Portal

## Disclaimer
This project is for testing and educational purposes. Use it only against your own networks and devices. I don't take any responsibility for what you do with this program.

## About this project
WiFi captive portal for the NodeMCU (ESP8266 Module) with DNS spoofing.

The built-in LED will blink 5 times when a password is posted.

<b>Warning!</b> Your saved passwords will **not** disappear when you restart/power off the ESP8266.

<b>Note:</b> If you want to see the stored passwords go to "**172.0.0.1**<a>/pass</a>". For changing the SSID, go to "**172.0.0.1**<a>/ssid</a>"

<b>V. 2.0 (Fake sign in)</b>: https://github.com/125K/ESP8266_WiFi_Captive_Portal_2.0

# Showcase

<a target="_blank" href="https://youtu.be/v4-5oX3RG94"><img width="700px" src="https://raw.githubusercontent.com/125K/ESP8266_WiFi_Captive_Portal/master/src/thumbnail.png"></a>

# Screenshots

<table>
  <tr>
    <th>172.0.0.1/index</th>
    <th>172.0.0.1/post</th> 
    <th>172.0.0.1/pass</th>
    <th>172.0.0.1/ssid</th>
  </tr>
  <tr>
    <td>This is the main page. Here the user will write his password and send it.</td>
    <td>This is the post page. The user will be redirected here after posting the password.</td>
    <td>This is where the attacker can retrieve all the passwords that has been posted.</td>
    <td>Here the attacker can change the SSID name of the Access Point on the go.</td>
  <tr>
    <td><img width="200px" src="https://raw.githubusercontent.com/BlueArduino20/ESP8266_WiFi_Captive_Portal/master/src/1_Index_2.jpg" title="index"></td>
    <td><img width="200px" src="https://raw.githubusercontent.com/BlueArduino20/ESP8266_WiFi_Captive_Portal/master/src/2_Post.jpg" title="post"></td>
    <td><img width="200px" src="https://raw.githubusercontent.com/BlueArduino20/ESP8266_WiFi_Captive_Portal/master/src/3_Pass.jpg" title="pass"></td>
<td><img width="200px" src="https://raw.githubusercontent.com/BlueArduino20/ESP8266_WiFi_Captive_Portal/master/src/4_ssid.jpg" title="ssid"></td>
  </tr>
</table>

Here you can donate if you liked my project and you want to support me:

<a href="https://www.buymeacoffee.com/rSiZtB3" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png" alt="Buy Me A Coffee" style="height: 41px !important;width: 174px !important;box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;-webkit-box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;" ></a>

# Installation (ESP8266 Flasher - Easy way)

1. Download <a href="https://github.com/nodemcu/nodemcu-flasher"><b>ESP8266 Flasher</b></a>.

2. Download the <b><a href="https://github.com/125K/ESP8266_WiFi_Captive_Portal/releases/download/1.1/release.bin">release.bin</b></a> file.

3. Open the ESP8266 Flasher and select the Node MCU port

<img width="80%" src="https://raw.githubusercontent.com/BlueArduino20/ESP8266_WiFi_Captive_Portal_2.0/master/src/1_port_selection.PNG">

4. Then, go to the config tab and select the .bin file you've just downloaded.

<img width="80%" src="https://raw.githubusercontent.com/BlueArduino20/ESP8266_WiFi_Captive_Portal_2.0/master/src/2_file_selection.png">

5. Finally, go back to the first tab and press "Flash"

6. Your Node MCU is ready!

# Installation (Arduino IDE)

1. Open your <a href="https://www.arduino.cc/en/main/software">Arduino IDE</a> and go to "File -> Preferences -> Boards Manager URLs" and paste the following link:
``http://arduino.esp8266.com/stable/package_esp8266com_index.json``
2. Go to "Tools -> Board -> Boards Manager", search "esp8266" and install esp8266
3. Go to "Tools -> Board" and select you board"
4. Download and open the sketch "<a href="https://github.com/125K/ESP8266_WiFi_Captive_Portal/blob/master/WiFi_Captive_Portal.ino"><b>WiFi_Captive_Portal.ino</b></a>"
5. You can optionally change some parameters like the SSID name and texts of the page like title, subtitle, text body...
6. Upload the code into your board.
7. You are done!


## Check out my other projects

- **WiFi-Spam**: :email::satellite: Spam thousands of WiFi access points with custom SSIDs.
  - https://github.com/125K/WiFi-Spam
- **PwrDeauther**: :zap: Deauth a specific WiFi access point or an entire channel.
  - https://github.com/125K/PwrDeauther
